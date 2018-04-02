#include <stdlib.h>
#include <stdio.h>
#include "solution.h"

/* Add function signatures here */

int main(int argc, char **argv) {
  /* Start your code here */
  int games, healthD, attackD, healthK, attackK, buff, debuff;
  scanf("%d", &games);
  for(int game=1; game<=games; game++){
    scanf("%d", &healthD);
    scanf("%d", &attackD);
    scanf("%d", &healthK);
    scanf("%d", &attackK);
    scanf("%d", &buff);
    scanf("%d", &debuff);
    printf("Case #%d: ", game);
    play(healthD, attackD, healthK, attackK, buff, debuff);
  }

  return 0;
}
