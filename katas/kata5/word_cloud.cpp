#include <cstdio>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
using namespace std;

int main(int argc, char **argv) {
  string read;
  ifstream stopWords("stopWords.txt");
  map<string, bool> ignoreWords;
  while(stopWords >> read){
    ignoreWords[read] = true;
  }

  ifstream odyssey("odyssey.txt");
  map<string, int> ocurrences;
  int max=0;
  char ignoreCharacters[] = {',', '-', '.', '(', ')', '!', '?', '#', ';', ':', '"'};
  while (odyssey >> read){
    // printf("read: %s\n", read.c_str());
    transform(read.begin(), read.end(), read.begin(), ::tolower);
    for(int i=0; i<sizeof(ignoreCharacters)/sizeof(ignoreCharacters[0]); i++){
      read.erase(remove(read.begin(), read.end(), ignoreCharacters[i]), read.end());
    }
    if(read=="" || ignoreWords.find(read)!=ignoreWords.end()){
      continue;
    }
    else if(ocurrences.find(read) != ocurrences.end()){
      ocurrences[read] = ocurrences[read]+1;
      if(ocurrences[read]>max) max=ocurrences[read];
    } else {
      ocurrences[read] = 1;
    }
  }

  Fl_Window *window = new Fl_Window(1664,936);
  Fl_Box *box;
  srand(time(0));
  for (map<string, int>::iterator it=ocurrences.begin(); it!=ocurrences.end(); it++ ){
    box = new Fl_Box((rand()%1550)-80,rand()%850,260,100,it->first.c_str());
    box->box(FL_NO_BOX);
    box->labelsize(((it->second*90)/max)+12);
    box->labelfont(FL_BOLD+FL_ITALIC);
    // printf("%s,%d\n", it->first.c_str(), it->second);
  }
  window->end();
  window->show(argc, argv);
  return Fl::run();
}
