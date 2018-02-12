#include <string.h>
#include <iostream>
#include <map>
using namespace std;

class Node {
public:
  string name;
  map<string, Node*> directories;
  Node():Node("undefined"){ }
  Node(string name){
    this->name = name;
  }
};

void print(map<string, Node*> dir, string indent){
  map<string, Node*>::iterator it = dir.begin();
  while(it != dir.end()){
    printf("%s%s\n", indent.c_str(), it->second->name.c_str());
    print(it->second->directories, indent+" ");
    it++;
  }
}

int main (){
  int paths;
  char path[80];
  char *folders;
  cin >> paths;
  map<string, Node*> root;

  for(int line=0; line<paths; line++){
    cin >> path;
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
  }
  
  print(root, "");
  return 0;
}
