# Kata 3: 657. Judge Route Circle
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to **the original place**.<br/>
<br/>
The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R(Right), L(Left), U(Up) and D(Down). The output should be true or false representing whether the robot makes a circle.<br/>
<br/>
**Example 1:**
```
Input: "UD"  Output: true
```
**Example 2:**
```
Input: "LL"  Output: false
```
## Breakdown
Okay, if we look carefully at what we want, it's actually pretty simple... we want to know if the Robot ends up at the same position it started. In other words, we want **no displacement in its vertical and horizontal axis**. That's the key, that no matter how much it moves around, we just need to make sure that for every move upwards there's a move downwards and that for every move to the right there's a move to the left.<br/>
<br/>
So, what if we do just that? We can have integer variables **_vertical_** and **_horizontal_**, both initialized to 0. Then, for every upwards move we read, we increment our **_vertical_** variable by 1; for every downwards move we read, we decrement it by 1.<br/>
Similarly, for every move to the right we read, we increment our **_horizontal_** variable by 1; for every move to the left we read, we decrement it by 1.<br/>
Finally, we just need to check if both **_vertical_** and **_horiztonal_** variables have a value of 0. Any other value means the Robot ended up displacing in some direction from its original position, and we would just print _false_.<br/>
<br/>
I invite you to go check out my implementation of this solution in C, located inside this folder :)
