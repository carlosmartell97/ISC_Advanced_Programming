#include <stdio.h>
#include "operations.h"

void printTestMessage(int condition, char *messagePassed, char *messageFailed){
  if(condition){
    printf("%s\n", messagePassed);
  } else {
    printf("%s\n", messageFailed);
  }
}

int testAddition(void){
  int a = 3;
  int b = 9;
  int resultAdd = add(a,b);
  int expectedAdd = a+b;
  return resultAdd==expectedAdd;
}

int testSubstraction(void){
  int a = 3;
  int b = 9;
  int resultSubs = substraction(a,b);
  int expectedSubs = a-b;
  return resultSubs==expectedSubs;
}

int main(){
  // test add


  printTestMessage(
    testAddition(),
    " add test PASSED",
    " add test FAILED"
  );

  printTestMessage(
    testSubstraction(),
    " substraction test PASSED",
    " substraction test FAILED"
  );
  return 0;
}
