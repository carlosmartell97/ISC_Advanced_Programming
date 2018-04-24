# Kata 10: UTF-8 Validation

## Problem Description
A character in UTF8 can be from **1 to 4 bytes** long, subjected to the following rules:
- For 1-byte character, the first bit is a 0, followed by its unicode code.
- For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10. </br>

This is how the UTF-8 encoding would work:
```
Char. number range  |        UTF-8 octet sequence
   (hexadecimal)    |              (binary)
--------------------+---------------------------------------------
0000 0000-0000 007F | 0xxxxxxx
0000 0080-0000 07FF | 110xxxxx 10xxxxxx
0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx  ``
```
Given an array of integers representing the data, return whether it is a valid utf-8 encoding. </br>
</br>
**Note:** </br>
The input is an array of integers. Only the **least significant 8 bits** of each integer is used to store the data. This means each integer represents only 1 byte of data. </br>
</br>

### Example 1:
```
data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001. </br>
Return true. It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.  
```
### Example 2:
```
data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100. </br>
Return false.  The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.
```

## Breakdown
How do we approach a problem like this? Well, for every binary representation we're looking at, we can follow this logic:
- First, we have to check if its most representative digit is 0. If it is, we know we're not expecting the next binary representation to have 10 as its most representative digits.
- If it's not zero, we have to count the amount of ones this binary representation has as most representatives. Let's call this amount of ones _n_. Then, we know we're expecting the next n-1 binary representations to have 10 as its most representative digits. </br>

### Almost there...
So, we could have a variable (let's call it _lookForNext_, initially set to 0) to store the amount of binary representations to look out next that should have 10 as its most representative bits. In the first case mentioned before, _lookForNext_ would be set to 0. In this second case, it would be set to _n-1_. </br>
Also, the 2 conditions before would be checked only if _lookForNext_ is 0. Otherwise, we must examine the next _lookForNext_ binary representations and check whether their most significant digits are 10. If for any of these binary representations this is not the case, the input doesn't follow the UTF-8 format and we return **false**. And for each of these examinations, we reduce the value of _lookForNext_ by one. </br>
</br>
If we've already examined all binary representations and _lookForNext_ is not 0, that means the input has some numbers missing, and we return **fase** for it not following the UTF-8 format. If we've looked at all binary representations, _lookForNext_ is zero and none of the unfortunate cases occured, then the input does indeed follow the UTF-8 format and we return **true**. </br>
</br>
And of course, before any of this can be done, we must first convert the numbers from the input to their binary representation. Only then, can we start looking at every binary representation one by one and follow the logic mentioned before. </br>
So, we first convert all numbers in input to their binary representation, **O(n)**. For each of the 8 bits in these binary representations, we examine, at most, its 8 bits. And we never go back to check a binary representation we've already examined. From left to right, all binary representations are examined with the help of _lookForNext_. So, still **O(n)**.
