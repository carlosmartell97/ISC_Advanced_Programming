# 1067: Disk Tree
## Problem Description
Hacker Bill has accidentally lost all the information from his workstation's hard drive and he has no backup copies of its contents. He does not regret for the loss of the files themselves, but for the very nice and convenient directory structure that he had created and cherished during years of work.<br/>
Fortunately, Bill has several copies of directory listings from his hard drive. Using those listings he was able to recover full paths (like "WINNT\SYSTEM32\CERTSRV\CERTCO1\X86") for some directories. He put all of them in a file by writing each path he has found on a separate line.<br/>
Your task is to write a program that will help Bill to restore his state of the art directory structure by providing nicely formatted directory tree.<br/><br/>
**Input**<br/>
The first line of the input contains single integer number N (1 ≤ N ≤ 500) that denotes a total number of distinct directory paths. Then N lines with directory paths follow. Each directory path occupies a single line and does not contain any spaces, including leading or trailing ones. No path exceeds 80 characters. Each path is listed once and consists of a number of directory names separated by a back slash ("\\").
Each directory name consists of 1 to 8 uppercase letters, numbers, or the special characters from the following list: exclamation mark, number sign, dollar sign, percent sign, ampersand, apostrophe, opening and closing parenthesis, hyphen sign, commercial at, circumflex accent, underscore, grave accent, opening and closing curly bracket, and tilde ("!#$%&'()-@^_{}~").<br/>
**Output**<br/>
Write to the output the formatted directory tree. Each directory name shall be listed on its own line preceded by a number of spaces that indicate its depth in the directory hierarchy. The subdirectories shall be listed in lexicographic order immediately after their parent directories preceded by one more space than their parent directory. Top level directories shall have no spaces printed before their names and shall be listed in lexicographic order. See sample below for clarification of the output format.<br/><br/>
**Sample input**<br/>
```
7
WINNT\SYSTEM32\CONFIG
GAMES
WINNT\DRIVERS
HOME
WIN\SOFT
GAMES\DRIVERS
WINNT\SYSTEM32\CERTSRV\CERTCO~1\X86
```
**Sample output**<br/>
```
GAMES
 DRIVERS
HOME
WIN
 SOFT
WINNT
 DRIVERS
 SYSTEM32
  CERTSRV
   CERTCO~1
    X86
  CONFIG
```

## Breakdown
Ok, so there's a root directory cointaining top-level directories. Inside these directories, there can be directories with more directories and so on... But, how could we solve something like this? Well, we can already identify several key pieces for our solution. This whole structure can be well defined as a tree, with folders as nodes and connections between them indicating the directory to which a folder belongs to. So, we start to map this into a class I decided to call Node:
```
class Node {
public:
  string name;
  map<string, Node*> directories;
  Node():Node("undefined"){ }
  Node(string name){
    this->name = name;
  }
};
```
Each node has a name (foler name) and a map of directories. Why use a map srtucture? Because in C++, by default these structures sort their elements by key. In our case, that means sorting our directories lexicographically. Cool! One less thing to worry about. And, how do we build this tree? Well, first we have to look closely at each of our full directory paths. For each of these folder names separated by "\\", we must know if we already consider it a subdirectory of its parent directory. If not, well, that means we've found a directory we had never seen before and it should be added to its parent directory.<br/>
<br/>
So... for each full directory path, we start by considering our root directory as our "previous" directory. And, we search in this root directory for a folder named as the string before the first "\\" in the directory path. If it doesn't exist, we should add a new Node to that map. Then, we continue to consider the directory of this Node (the one that was just created or was already there) as our "previous" directory from now on.<br/>
This way, when we look at the next string separated by "\\", we won't be looking at our root directory anymore but at its appropriate subdirectory. And so, and so on. We keep changing our "previous" reference for all levels in each full directory path. This allows us to effectively build our tree. And so, after realizing all this and getting my thoughts together, this is how I did it:
```
folders = strtok(path, "\\");            // separate each folder name by "\"
map<string, Node*> *previous = &root;    // start by considering root as our previous directory
while (folders != NULL) {                // go through all elements (folder names) in the path
  if(previous->find(folders)==previous->end()){
    previous->operator[](folders) = new Node(folders);// if this folder does not exist in our
                                                      // "previous" reference, add new Node
  }
  previous = &previous->operator[](folders)->directories; // update our previous reference to this
                                                          // current folder
  folders = strtok (NULL, "\\"); // keep looking for more folder names in our path, separated by "\"
}
```
So this builds our tree. Now, how can we display that information? Well, if you think about it, this is exactly what a Depth First Search would do, if we start at root. So that's exactly what I decided to do:
```
void print(map<string, Node*> dir, string indent){
  map<string, Node*>::iterator it = dir.begin();
  while(it != dir.end()){
    printf("%s%s\n", indent.c_str(), it->second->name.c_str());
    print(it->second->directories, indent+" ");
    it++;
  }
}
```
Sending the string " " down the recursion takes care of printing the directories with their respective indentation, and all of these map structures are sorted by key (folder name), so they are printed in lexicographical order! At the end, it all makes so much sense.<br/>
<br/>
You can see my complete solution to this problem inside this directory, in C++.
