# Problem Description
Sheila is a student and she drives a typical student car: it is old, slow, rusty, and falling apart.
Recently, the needle on the speedometer fell off. She glued it back on, but she might have placed
it at the wrong angle. Thus, when the speedometer reads s, her true speed is s + c, where c is an
unknown constant (possibly negative). Sheila made a careful record of a recent journey and wants to
use this to compute c. The journey consisted of n segments. In the ith segment she traveled a
distance of di and the speedometer read si for the entire segment. This whole journey took time t.
Help Sheila by computing c. <br/>
Note that while Sheila’s speedometer might have negative readings,
her true speed was greater than zero for each segment of the journey.
<br/>
**Input**<br/>
The first line of input contains two integers n (1 ≤ n ≤ 1 000), the number of sections in Sheila’s
journey, and t (1 ≤ t ≤ 106), the total time. This is followed by n lines, each describing one segment
of Sheila’s journey. The ith of these lines contains two integers di (1 ≤ di ≤ 1 000) and si
(|si| ≤ 1 000), the distance and speedometer reading for the ith segment of the journey. Time is
specified in hours, distance in miles, and speed in miles per hour.<br/>
**Output**<br/>
Display the constant c in miles per hour. Your answer should have an absolute or relative error of le
ss than
10−6<br/>
<br/>
**Sample Input**<br/>
3 5<br/>
4 -1<br/>
4 0<br/>
10 3<br/>
**Sample Output**<br/>
3.000000000

## Breakdown
Let's first think about the easiest scenario: only 1 segment. This way, in our equation
```
s1+c = d1/t1
```
we only need to isolate for c. However, for journeys with more than one segment, we need to find a value
for c that fits various equations at once...
```
s1+c = d1/t1
s2+c = d2/t2
s3+c = d3/t3
...
```
That's right, a system of n equations. From here on, we could take a look at some iterative methods to
solve this system. Giving us the value of c. Nice, right?


## Code
Solution implementation pending.
