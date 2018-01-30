# Kata 2: 420. Strong Password Checker.
A password is considered strong if below conditions are all met:

1. It has at least 6 characters and at most 20 characters.
2. It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
3. It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).<br/>
<br/>
Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.

## Breakdown
This problem might sound easy at first, but let's think about it carefully. One of our conditions is the length of the password, and we can very quickly check if it's shorter than 6 or longer than 20 characters. If the password is shorter than 6 characters, we should not only account for the character insertions needed to meet the minimum length required, we might also need to replace existing characters so the other requirements are met... Just as in
```
aaa3
```
where we don't only need to insert 2 more characters, but we should also change one of the existing letters so that we don't have three repeating letters in a row. Similar things happen if the password is longer than 20 characters... what if the letter we try to delete/replace causes another condition not to be met anymore? Even if the password does have a length between 6 and 20, we might still find some issues that force us to look at our solution more closely... we cannot always replace for the same character, what if a single character replacement/deletion can take care of more than 1 condition at the same time? what if one read across the password is not enough? We need to take into account how every change we make might lead to other changes, and efficiently choose the path with the least modifications needed for all conditions to be met.
