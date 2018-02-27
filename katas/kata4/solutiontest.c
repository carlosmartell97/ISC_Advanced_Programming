#include <stdio.h>
#include <stdbool.h>
#include "minunit.h"
#include "solution.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

int testsRun = 0;

static char * testAllNumbers() {
  muAssert("error, '0' IS a valid number", validNumber("0", 1) == 1);
  return 0;
}

static char * testDecimals() {
  muAssert("error, ' 0.1' IS a valid number", validNumber(" 0.1", 4) == 1);
  return 0;
}

static char * testLetters() {
  muAssert("error, 'abc' is NOT a valid number", validNumber("abc", 3) == 0);
  return 0;
}

static char * testOtherLetters() {
  muAssert("error, '1 a' is NOT a valid number", validNumber("1 a", 3) == 0);
  return 0;
}

static char * testScientificNotation() {
  muAssert("error, '2e10' IS a valid number", validNumber("2e10", 4) == 1);
  return 0;
}

static char * testDecimalsAndScientific() {
  muAssert("error, '245.81e10.134' IS a valid number", validNumber("245.81e10.134", 13) == 1);
  return 0;
}

static char * testFinishesWithE() {
  muAssert("error, '245.81e' is NOT a valid number", validNumber("245.81e", 7) == 0);
  return 0;
}

static char * testOnlyWithCommas() {
  muAssert("error, '1,846,246' IS a valid number", validNumber("1,846,246", 9) == 1);
  return 0;
}

static char * testInvalidCommas() {
  muAssert("error, '1,86,246' is NOT a valid number", validNumber("1,86,246", 8) == 0);
  return 0;
}

static char * testStartsWithCommas() {
  muAssert("error, ',864,246' is NOT a valid number", validNumber(",864,246", 8) == 0);
  return 0;
}

static char * testAll() {
  muAssert("error, '05,134,167.84051e1,841.666' IS a valid number", validNumber("05,134,167.84051e1,841.666", 26) == 1);
  return 0;
}

static char * allTests() {
  muRunTest(testAllNumbers);
  muRunTest(testDecimals);
  muRunTest(testLetters);
  muRunTest(testOtherLetters);
  muRunTest(testScientificNotation);
  muRunTest(testDecimalsAndScientific);
  muRunTest(testFinishesWithE);
  muRunTest(testOnlyWithCommas);
  muRunTest(testInvalidCommas);
  muRunTest(testStartsWithCommas);
  muRunTest(testAll);
  return 0;
}

int main(int argc, char **argv) {
  char *result = allTests();
  if (result != 0) {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");
    printf("_-_-_-_-_-_-_- \"\"  \"\" \n");
    printf(KRED "✗ %s \n" RESET, result);
  }
  else {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( ^ .^)  +     + \n");
    printf("_-_-_-_-_-_-_-  \"\"  \"\" \n");
    printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);
  }
  printf("Tests run: %d\n", testsRun);
  return result != 0;
}
