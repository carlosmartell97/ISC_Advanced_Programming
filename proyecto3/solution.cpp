#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

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

int main(){
  int tests, n_words;
  string word;
  cin >> tests;
  vector< vector<string> > starting_with_letter(26);
  map<string, Node*> found_words;
  bool ordering_is_possible = false;
  for(int test=0; test<tests; test++){
    // printf("\n\nCASE #%d\n", test+1);
    cin >> n_words;
    for(int w=0; w<n_words; w++){
      cin >> word;
      // printf(" word: %s\n", word.c_str());
      if(found_words.find(word) == found_words.end()){
        found_words[word] = new Node(word);
      } else {
        found_words[word]->ocurrences++;
      }
      int first_letter_normalized = (int)word[0]-96;
      // printf("  first: %c -> %d\n", word[0], first_letter_normalized);
      // printf("  last: %c\n", word[word.size()-1]);
      starting_with_letter[first_letter_normalized].push_back(word);
    }
    // printf(" -----------\n");
    for(map<string, Node*>::iterator it=found_words.begin(); it!=found_words.end(); it++){
      word = it->second->full_word;
      // printf(" now looking at %s\n", word.c_str());
      int last_letter_normalized = (int)word[word.size()-1]-96;
      for(int i=0; i<starting_with_letter[last_letter_normalized].size(); i++){
        string following_word = starting_with_letter[last_letter_normalized][i];
        // printf("   found %s\n", following_word.c_str());
        found_words[word]->next_nodes.push_back(following_word);
        found_words[following_word]->entry_point = false;
      }
    }
    // printf(" -----------\n");
    for(map<string, Node*>::iterator it=found_words.begin(); it!=found_words.end(); it++){
      word = it->second->full_word;
      // printf(" %s:\n", word.c_str());
      if(it->second->entry_point){
        // printf("  good entry point\n");
        for(map<string, Node*>::iterator it2=found_words.begin(); it2!=found_words.end(); it2++){
          it2->second->seen = 0;
        }
        int nodes_visited = 0;
        queue<Node*> q;
        q.push(it->second);
        while(!q.empty()){
          Node* top = q.front();
          // printf("  top:%s\n", top->full_word.c_str());
          q.pop();
          for(int i=0; i<top->next_nodes.size(); i++){
            if(found_words[top->next_nodes[i]]->seen != found_words[top->next_nodes[i]]->ocurrences) {
              q.push(
                found_words[top->next_nodes[i]]
              );
              // printf("   ->%çs\n", found_words[top->next_nodes[i]]->full_word.c_str());
            }
          }
          // printf("   visited %s\n", top->full_word.c_str());
          top->seen++;
          nodes_visited++;
        }
        // printf("  nodes visited:%d\n", nodes_visited);
        if(nodes_visited == n_words){
          ordering_is_possible = true;
          continue;
        }
      } else {
        // printf("  not an entry point\n");
      }
    }
    if(ordering_is_possible){
      printf("Ordering is possible.\n");
    } else {
      printf("The door cannot be opened.\n");
    }
    ordering_is_possible = false;
    found_words.clear();
    starting_with_letter.clear();
  }
  // printf("DONE\n");
  return 0;
}
