# Kata 1: 760. Find Anagram Mappings

## problem description
Given two lists A and B, and B is an anagram of A. B is an anagram of A means B is made by randomizing the order of the elements in A.

We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A appears in B at index j.

These lists A and B may contain duplicates. If there are multiple answers, output any of them.

For example, given
```
A = [12, 28, 46, 32, 50]  B = [50, 12, 32, 46, 28]
```
We should return
```
[1, 4, 3, 2, 0]
```
as  P[0] = 1 because the  0th element of  A appears at  B[1], and  P[1] = 4 because the  1st element of  A appears at  B[4], and so on.
Note:
1. A, B have equal lengths in range [1, 100].
2. A[i], B[i] are integers in range [0, 10^5].


## Breakdown:
Well, first of all, since both lists have equal lengths... if list A is of length 1, we know that no matter how many times you randomize it, the list will remain the same. So, in these cases we should just return the trivial solution **[0]**.<br/>
<br/>
For all other cases, computation is needed. And of course, there's the brute force approach...<br/>
We could go through every element of A and look for it in B. So, we would first look at number 12 of A, look at position 0 of B, then position 1 of B and we find the 12 we were looking for. Then, we would look at number 28 of A, look at position 0 of B, position 1 of B, position 2 of B... and until the very end of B and we find the 28 we were looking for! So, for every element of A, we would look at all elements in B. A and B have the same length, adding up to a complexity of O(n^2). We can surely do better than that...<br/>
<br/>
What if we could know the position of a letter in B, in constant time? Again, just as Kata 0, hash tables come in handy. We could first go through all elements in B and store them in buckets in the hash table with the number itself as the key and its position in B as the value.<br/>Then, if we go through every element of A, we can look for each number in the hash table and know its position in B right away, without having to look for it ourselves in B. This strategy only requires to go through B once, then A once... O(n). A much better solution!