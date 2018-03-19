#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    scanf("%d", &N);
    int x;
    int y;
    scanf("%d%d", &x, &y);
    int xA = 0;
    int xB = W-1;
    int yA = 0;
    int yB = H-1;

    // game loop
    while (1) {
        char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", bombDir);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        if(strcmp(bombDir, "U") == 0){
            // fprintf(stderr, "up\n");
            yB = y-1;
        }
        else if(strcmp(bombDir, "R") == 0){
            // fprintf(stderr, "right\n");
            xA = x+1;
        }
        else if(strcmp(bombDir, "D") == 0){
            // fprintf(stderr, "down\n");
            yA = y+1;
        }
        else if(strcmp(bombDir, "L") == 0){
            // fprintf(stderr, "left\n");
            xB = x-1;
        }
        else if(strcmp(bombDir, "UR") == 0){
            // fprintf(stderr, "up right\n");
            yB = y-1;
            xA = x+1;
        }
        else if(strcmp(bombDir, "DR") == 0){
            // fprintf(stderr, "down right\n");
            xA = x+1;
            yA = y+1;
        }
        else if(strcmp(bombDir, "DL") == 0){
            // fprintf(stderr, "down left\n");
            yA = y+1;
            xB = x-1;
        }
        else if(strcmp(bombDir, "UL") == 0){
            // fprintf(stderr, "up left\n");
            yB = y-1;
            xB = x-1;
        }
        x = xA+(xB - xA) / 2;
        y = yA+(yB - yA) / 2;

        // the location of the next window Batman should jump to.
        printf("%d %d\n", x, y);
    }

    return 0;
}
