#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "solution.h"

/* Add function signatures here */

int main(int argc, char **argv) {
  /* Start your code here */
  int size;
  printf(" Size of input: ");
  scanf("%d", &size);
  char input[size];
  printf(" Enter the word you want to evaluate: ");
  scanf("%s", input);
  printf(" %s -> %s\n", input, validNumber(input, size)?"true":"false");
  return 0;
}
