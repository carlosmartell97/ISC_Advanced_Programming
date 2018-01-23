#include <assert.h>
#include "operations.h"
#define MAX_INT 2147483647

/**
*  Use long addition to catch overflow
*/
int add(int a, int b){
  // do the addition and check if there's an overflow
  long result = (long)a + b;
  assert(result <= MAX_INT && result > -MAX_INT);
  return (int)result;
}

/**
*  Use long substraction to catch overflow
*/
int substraction(int a, int b){
  long result = (long)a - b;
  assert(result <= MAX_INT && result > -MAX_INT);
  return (int)result;
}
