#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{

    // game loop
    while (1) {
        int x;
        int y;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDist; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        scanf("%d%d%d%d%d%d", &x, &y, &nextCheckpointX, &nextCheckpointY, &nextCheckpointDist, &nextCheckpointAngle);
        int opponentX;
        int opponentY;
        scanf("%d%d", &opponentX, &opponentY);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");


        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
        int thrust;
        fprintf(stderr, "distance: %d\n", nextCheckpointDist);
        if(nextCheckpointDist > 5000 && nextCheckpointAngle < 45 && nextCheckpointAngle > -45){
            printf("%d %d BOOST\n", nextCheckpointX, nextCheckpointY);
        }
        else {
            thrust = 100;
            if(nextCheckpointDist > 1000 && nextCheckpointDist < 3000){
                thrust -= (nextCheckpointDist*25)/1000;
            }
            if(nextCheckpointAngle < -90 && nextCheckpointAngle > 90){
                thrust -= ((nextCheckpointAngle+90)*5)/180;
            }
            if(nextCheckpointDist < 1000){
                thrust -= (nextCheckpointDist*40)/1000;
            }
            printf("%d %d %d\n", nextCheckpointX, nextCheckpointY, thrust);
        }
    }

    return 0;
}
