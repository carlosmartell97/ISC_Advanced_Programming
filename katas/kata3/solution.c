#include <stdio.h>

int main(){
  int vertical=0, horizontal=0;
  char c;
  while(scanf("%c", &c)){
    if(c=='U'){
      vertical++;
    }
    else if(c=='D'){
      vertical--;
    }
    else if(c=='R'){
      horizontal++;
    }
    else if(c=='L'){
      horizontal--;
    }
    else {
      break;
    }
  }
  if(vertical==0 && horizontal==0){
    printf("true\n");
  } else {
    printf("false\n");
  }
  return 0;
}
