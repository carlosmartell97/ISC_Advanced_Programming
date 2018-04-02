#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// #include <math.h>
#include "solution.h"

void play(int healthD, int attackD, int healthK, int attackK, int buff, int debuff){
  // printf("\n");
  int dragonMaxHealth = healthD;
  int consecutiveDragonHeals = 0;
  int turn = 1;
  while(1){
    // printf(" \nTURN %d\n", turn);
    // printf("    buff:%d\n", buff);
    // printf("  debuff:%d\n", debuff);
    // printf(" healthD:%d   attackD:%d\n", healthD, attackD);
    // printf(" healthK:%d   attackK:%d\n", healthK, attackK);

    // DRAGON'S turn
    // if(attackK>0){
    //   printf(" ratio: %f\n", healthD/(attackK*1.0));
    //   printf("ratio2: %f\n", (healthD-attackK)/(attackK*1.0));
    // }
    if(debuff > 0 && attackK > 0 && healthD/(attackK*1.0) > 0.33){
      // printf("DRAGON uses debuff against knight\n");
      attackK -= debuff; if(attackK<0)attackK=0;
      consecutiveDragonHeals=0; // reset consecutiveDragonHeals
    }
    else if(buff > 0 && attackK > 0 && (healthD-attackK)/(attackK*1.0) > 0.33){
      // printf("DRAGON uses buff\n");
      attackD += buff;
      consecutiveDragonHeals=0; // reset consecutiveDragonHeals
    }
    else if(healthK-attackD > 0 && healthD-attackK <= 0){ // knight would still live after attack and our health isn't critical
      // printf("DRAGON heals himself\n");
      healthD = dragonMaxHealth;          // DRAGON heals
      consecutiveDragonHeals++;
    }
    else {
      float turnsLeftAtacking = healthK/attackD;
      bool betterIfBuff = false;
      // printf("turns left atacking: %f\n", turnsLeftAtacking);
      if(buff > 0){
        for(int i=attackD, counter=0; i<=healthK; i++, counter++){
          float factor = healthK/(i*1.0);
          int cast = factor;
          if(cast == factor){
            // printf("\t%d x %f = %d\n", i, factor, healthK);
            // printf("\tturns could be %f\n", factor+counter);
            if(factor+counter < turnsLeftAtacking){
              // printf("\tfound BETTER one\n");
              i = healthK+1;
              betterIfBuff = true;
              // printf("DRAGON uses buff\n");
              attackD += buff;
              consecutiveDragonHeals=0; // reset consecutiveDragonHeals
            }
          }
          else {
            // printf("\t%d x %d = %d\n", i, cast+1, i*(cast+1));
            // printf("\tturns could be %d\n", cast+1+counter);
            if(cast+1+counter < turnsLeftAtacking){
              // printf("\tfound BETTER one\n");
              i = healthK+1;
              betterIfBuff = true;
              // printf("DRAGON uses buff\n");
              attackD += buff;
              consecutiveDragonHeals=0; // reset consecutiveDragonHeals
            }
          }
        }
      }
      if(!betterIfBuff){
        // printf("DRAGON attacks\n");
        healthK -= attackD; // DRAGON attacks
        consecutiveDragonHeals=0; // reset consecutiveDragonHeals
      }
    }

    // KNIGHT'S TURN
    if(healthK > 0){        // knight is alive
      // printf("KNIGHT attacks\n");
      healthD -= attackK; // KNIGHT attacks
    } else {
      printf("%d\n", turn);
      consecutiveDragonHeals=0; // reset consecutiveDragonHeals
      break;
    }
    if(healthD <= 0){
      // printf("\n DRAGON died in %d turns\n", turn);
      printf("IMPOSSIBLE\n");
      consecutiveDragonHeals=0; // reset consecutiveDragonHeals
      break;
    }
    if(consecutiveDragonHeals > 3){
      printf("IMPOSSIBLE\n");
      consecutiveDragonHeals=0; // reset consecutiveDragonHeals
      break;
    }
    turn++;
  }
  // printf("\n");
}
