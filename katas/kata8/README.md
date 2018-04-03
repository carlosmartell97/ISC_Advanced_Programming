# Kata 8: Coders Strike Back

## Problem Description

### The Goal
Win the race.

### Rules
The circuit of the race is made up of checkpoints. To complete one lap, your vehicle (pod) must pass through each checkpoints **in order** and back through the start. The first player to reach the starting checkpoint on the final lap wins. <br/>
<br/>
![pods](https://www.codingame.com/servlet/fileservlet?id=4281219941049) <br/>
<br/>
The pods work as follows:<br/>
* To pass a checkpoint, the center of a pod must be inside the radius of the checkpoint.
* To move a pod, you must print a target destination point followed by a thrust value. Details of the protocol can be found further down.
* The thrust value of a pod is its acceleration and must be between **0** and **100**.

### Victory Conditions
Be the first to complete all the laps of the circuit with your pod.

### Lose Conditions
* Your program provides incorrect output.
* Your program times out.
* Your pod does not reach the next checkpoint in time.
* Somebody else wins.

### Expert Rules
The game is played on a map **16000** units wide and 9000 units high. The coordinate X=0, Y=0 is the top left pixel. <br/>
<br/>
### The checkpoints work as follows:
* The checkpoints are circular, with a radius of 600 units.
* The disposition of the checkpoints is selected randomly for each race.
### The pods work as follows:
* If your pod does not reach the next checkpoint under 100 turns, you are eliminated and lose the game.
* The pods may move normally outside the game area.

Note: The program must, within an infinite loop, read the contextual data from the standard input and provide to the standard output the desired instructions.
### Game Input
Input for one game turn <br/>
```
One line: 4 integers x & y for the position. nextCheckPointX & nextCheckPointY for the number of the
next checkpoint the pod must go through.
```
Output for one game turn
```
One line: 2 integers for the target coordinates of your pod followed by thrust, the thrust to give
your pod.
```
### Constraints
```
0 ≤ thrust ≤ 100
Response time first turn ≤ 1000ms
Response time per turn ≤ 150ms
```
## Breakdown
At first, the only information we have for the next checkpoint is its _X_ and _Y_ coordinates, but as we progress through the game, things get a bit more interesting. By the time we get to the Bronze League, we also have the distance to the next checkpoint and its angle from the direction we're facing (between -90 and 90), _nextCheckpointDist_ and _nextCheckpointAngle_. We also get the ability to use _BOOST_ as thrust, to go even faster. <br/>
<br/>
How do we use all this extra information? Well, it can help us reduce the distance we cover after a checkpoint when we reach it and our momentum keeps us going forward. If we're close enough to the checkpoint, we should start slowing down. Also, if we're not looking directly at the next checkpoint (_nextCheckpointAngle_), it would also be good to go a bit slower until we're facing the direction of the checkpoint. <br/>
<br/>
### This is exactly what I'm doing:
* if the distance to the checlpoint is more than 5000 and the direction we're facing is within -45º and 45º of the next checkpoint, it's a good moment to use some _BOOST_. <br/>
### otherwise, our thrust is 100. Plus a few adjustments:
* if the distance is between 1001 and 2999, subtract a number between 0 and 25 from our current thrust, depending on how close to 1001 the distance is.
* if the direction we're facing is less than -90º or more than 90º from the next checkpoint, subtract a number between 0 and 5 from our current thrust, depending on how off the direction we're looking at is.
* if the distance is less than 1000, subtract a number between 0 and 40 from our current thrust, depending on how close we are to the checkpoint. <br/>

### Solution
I invite you to go check out my full solution to this problem in _C_.
