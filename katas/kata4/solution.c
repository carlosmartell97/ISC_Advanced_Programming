#include <stdbool.h>
#include "solution.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

bool validNumber(char input[], int size){
  bool hasE=false, hasDot=false, hasNumbers=false, finishesWithE=false, hasComa=false;
  int numbersWithoutComma=0;
  for(int i=0; i<size; i++){
    // printf(" checking %c\n", input[i]);
    if(input[i]==' '){
      continue;
    }
    else if(input[i]=='e'){
      if(hasE) return false; // 'e' present twice
      if(!hasNumbers) return false;
      hasE=true;
      finishesWithE=true;
      hasDot=false;
      hasComa=false;
      numbersWithoutComma=0;
    }
    else if(input[i]=='.'){
      if(hasDot) return false; // '.' present twice
      hasDot=true;
    }
    else if(input[i]==','){
      if(!hasComa){
        if(numbersWithoutComma==0 || numbersWithoutComma>3){
          return false;
        }
      } else {
        if(numbersWithoutComma!=3){
          return false;
        }
      }
      hasComa=true;
      numbersWithoutComma=0;
    }
    else if(isdigit(input[i])){
      hasNumbers=true;
      numbersWithoutComma++;
      if(finishesWithE) finishesWithE=false;
    }
    else {
      return false;
    }
  }
  if(!finishesWithE){
    return true;
  }
  return false;
}
