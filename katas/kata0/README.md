# Kata 0

## problem description
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

## Breakdown:
First, since I know each input has exactly one solution, all inputs of length 2 will have the trivial solution of indexes 0 and 1. These two numbers must equal the target and no computation is needed.

If the input's length is bigger than two, one strategy could be to look at each element, and for each, search in the rest of the array for the number that would add up to the target. For example, if my target was 8 and I had the array
```
[6, 9, 3, 1, 5]
```
I would first look at 6, and move to the right searching the rest of the array for a 2. Then look at 9, see that it's bigger than my target and discard that number. Then look at 3, and move to the right searching the rest of the array for a 5... which there is, and return [2,4].<br/>
However, this strategy would have a complexity of n to go through all elements and for each of these elements, logn (with binary search) to look for the number that would add up to the target (so, n*logn). **And that is if the array is already sorted***. If it's not sorted, that complexity would have to be considered as well.<br/>
<br/>
Now, if we think about it, there's a better strategy with the use of a data structure... hash tables.<br/>
What if we could check, in constant time, whether the number that's missing to reach the target is in the array or not? With a hash table, we could first go through the array and add each element to the hash table. Then, we could go through the array a second time, but now, checking if the number missing to reach the target is in the hash table or not. So, the key in each bucket in the hash table would be the number itself and the value in each bucket would be the index position.<br/>
<br/>
So, if we had the same input as before,
```
[6, 9, 3, 1, 5]
```
we would first go through the array, adding each element to the hash table. Then, for the second time looking at the array... we would look at 6 and see that 2 is not in the hash table, look at 9 and see that it's bigger than the target and discard it, look at 3 and see that 5 is indeed in the hash table. So, we return the values of those two buckets in the hash table, [2,4].<br/>
This way, we would be just going through the array array twice, linear complexity. O(n).
