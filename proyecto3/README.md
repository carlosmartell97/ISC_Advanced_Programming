# CODECHEF problem: Play on Words
https://www.codechef.com/problems/WORDS1

## Description
There are some doors with a very interesting word puzzle. A team of archaeologists has to solve it to open them. Because there is no other way to open the doors, the puzzle is very important for us. <br/>
<br/>
There is a large number of magnetic plates on every door. Every plate has one word written on it. The plates must be arranged into a sequence in such a way that **every word begins with the same letter as the previous word ends**. For example, the word ```acm``` can be followed by the word ```motorola```. Your task is to write a computer program that will read the list of words and determine whether it is possible to arrange all of the plates in a sequence (according to the given rule) and consequently to open **the door**. <br/>
<br/>
![door puzzle](https://i2-prod.mirror.co.uk/incoming/article6212005.ece/ALTERNATES/s810/Maze-Lock.jpg)<br/>

### Input
The input consists of _T_ test cases. The number of them (_T_, equal to about 500) is given on the first line of the input file. Each test case begins with a line containing a single integer number _N_ that indicates the number of plates (1 <= _N_ <= 100000). Then exactly _N_ lines follow, each containing a single word. Each word contains at least two and at most 1000 lowercase characters, that means only letters 'a' through 'z' will appear in the word. _The same word may appear several times in the list_.

### Output
Your program has to determine whether it is possible to arrange all the plates in a sequence such that the first letter of each word is equal to the last letter of the previous word. All the plates from the list must be used, each exactly once. The words mentioned several times must be used that number of times. <br/>
<br/>
If there exists such an ordering of plates, your program should print the sentence ```Ordering is possible.```. Otherwise, output the sentence ```The door cannot be opened.```.

### Example
Sample input:
```
3
2
directi
codechef
3
skenzo
logicboxes
orderbox
2
ok
ok
```

Sample output:
```
The door cannot be opened.
Ordering is possible.
The door cannot be opened.
```

## Breakdown
Okay, let's try to picture this problem. We're trying to find out whether there exists a sequence of arranging these words so that every word begins with the same letter that the previous word ends with. If we stop and think about it for a moment, we could very well approach this as a graph problem. What if we had nodes as words, and a relationship between nodes _a_ and _b_ meant word _a_ ends with the same letter _b_ starts with? This way, our solution relies on finding a node from which we can traverse the graph and visit all nodes. How would that work out?

## Solution
First, let's define our concept of _Node_. For that, we use this class definition:
```
class Node {
public:
  string full_word;
  bool entry_point;
  vector<string> next_nodes;
  int ocurrences, seen;
  Node(string full_word){
    this->full_word = full_word;
    this->entry_point = true;
    this->seen = 0;
    this->ocurrences = 1;
  }
};
```
Basically, it has a word and a list of possible relationships to other nodes. I'll explain the other attributes later. <br/>
Now, let's have a map to store all these nodes: ```map<string, Node*> found_words;```, mapping strings (words) to their respective Node objects. Our solution is basically divided in 3 parts.

### Part 1
We fill the map with all words in the input case. And, we'll have a bidemensional list for all letters in the alphabet and the words we find that start with each letter: ```vector< vector<string> > starting_with_letter(26);```. <br/>
So, we add every word to this bidimensional list, according to the letter with which the word starts: ```starting_with_letter[first_letter_normalized].push_back(word);```. <br/>
We're using the ASCII value of the letter, and we normalize it by subtracting 96 from it: ```int first_letter_normalized = (int)word[0]-96;```. <br/>
But let's remember that words might be repeated in the input, and we do want to consider them as separate nodes. So, that's why we have the attributes ```seen``` and ```ocurrences``` in our Nodes. If we find a word that's already in our map, we don't create a new Node for it, we just update the ```ocurrences``` attribute of that node.

### Part 2
Now that our map is complete, we can start creating relationships between nodes. For that, we go through every Node in our map and look at its last letter. For every Node we see, we must create relationships to Nodes that start with the letter this Node ends. And that's where our bidimensional list comes useful. We can easily know which words start with any letter. So again, we normalize the last letter of the Node we're looking at: ```int last_letter_normalized = (int)word[word.size()-1]-96;```. <br/>
And, for every word in our bidimensional list that starts with the same letter the Node we're looking at ends with, we must create a relationship to it:
```
for(int i=0; i<starting_with_letter[last_letter_normalized].size(); i++){
  string following_word = starting_with_letter[last_letter_normalized][i];
  found_words[word]->next_nodes.push_back(following_word);
  found_words[following_word]->entry_point = false;
}
```
Do you now see what the attribute ```entry_point``` in our Nodes stands for? When we try to traverse the graph, we'll have to start this traversal from Nodes that have no relationships coming into them, Nodes that only have relationships coming out of them. So, if we're creating a relationship from Node _a_ to Node _b_, we know Node _b_ can no longer be considered a starting node, not a possible ```entry point``` for our traversal.

### Part 3
Now we have all our Nodes and the relationships between them, we have the graph we were looking for. Now we must find out if there's a Node in this graph from which we can traverse it and visit all other Nodes. For that, we'll be doing a _Breadth First Search_. So, we look at every Node in our map... and for each, we first check if it's a possible entry point: ```if(it->second->entry_point){ ... }```. <br/>
If it is, we try a _breadth First Search_ with this Node as our starting point. Now, our Nodes don't have some boolean _visited_ that we just turn on and off when we're done looking at it, because remember: the words in out input might be repeated. That's why our Nodes have the attributes ```seen``` and ```ocurrences```. Every time we look at a Node, we update its ```seen``` attribute. And we only considered a Node as visited when this attribute's value is equal to ```ocurrences```. <br/>
So before trying to traverse from any Node, we reset this ```seen``` attribute for all Nodes in our graph:
```
for(map<string, Node*>::iterator it2=found_words.begin(); it2!=found_words.end(); it2++){
  it2->second->seen = 0;
}
```
And we do try our usual _Breadth First Search_, starting only with our initial Node in the queue:
```
int nodes_visited = 0;
queue<Node*> q;
q.push(it->second);
while(!q.empty()){
  Node* top = q.front();
  q.pop();
  for(int i=0; i<top->next_nodes.size(); i++){
    if(found_words[top->next_nodes[i]]->seen != found_words[top->next_nodes[i]]->ocurrences) {
      q.push(
        found_words[top->next_nodes[i]]
      );
    }
  }
  top->seen++;
  nodes_visited++;
}
```
We keep track of the amount of Nodes we were able to visit in each _Breadth First Search_ traversal with ```nodes_visited```. Only if by the end of our traversal this value is equal to the number of words in our input, it means that a traversal visiting all Noes was possible and thus exists an ordering for the word plates, and we can open the door! <br/>
Finally, at the end of every test, we reset our values for a solution found or not, our map of Nodes and our bidimensional list of words:
```
ordering_is_possible = false;
found_words.clear();
starting_with_letter.clear();
```
![door_opened](https://freelyphotos.com/freely_images/freely-10109.jpg)
