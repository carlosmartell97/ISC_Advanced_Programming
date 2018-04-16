# Kata 9: Inflight Entertainment System

## Problem Description
**You've built an inflight entertainment system with on-demand movie streaming.** Users on longer flights like to start a second movie right when their first one ends, but they complain that the plane usually lands before they can see the ending. **So you're building a feature for choosing two movies whose total runtimes will equal the exact flight length.** </br>
</br>
![enertainment system](https://www.electronicproducts.com/uploadedImages/Computer_Peripheral/Systems/In-flight%20entertainment.jpg) </br>
</br>
Write a function that takes an integer *flight_length* (in minutes) and a list of integers *movie_lengths* (in minutes) and returns a boolean indicating whether there are two numbers in *movie_lengths* whose sum equals *flight_length*. </br>
</br>
**When building your function:** </br>
- Assume your users will watch exactly two movies
- Don't make your users watch the same movie twice
- Optimize for runtime over memory

## Breakdown
So... we must find a way to determine whether there is a pair of movies that add up exactly to the length of the flight. That is, if the flight has a duration of 8 hours (quite a long flight, of course you would like some movies), you could pick any of the following options as movie pairs:
- one movie lastting 1 hour, another one lasting 7 hours
- one movie lastting 2 hours, another one lasting 6 hours
- one movie lastting 3 hours, another one lasting 5 hours
- one movie lastting 4 hours, another one lasting 4 hours

And according to the problem description, you wouldn't like to watch the same movie twice. Thus, for every movie available, we need to know if there's another movie that we can watch right after, finishing right when the plane lands. How can we do this?
</br>
</br>
The simplest solution would be: for every movie, search the whole list for another movie lasting exactly the hours left after such movie before landing. So that if we had the following list of movie lengths in a 10 hour flight:
```
1 5 2 7 10 4 3
```
we would look at 1 and search the whole list for a 9, then look at 5 and search the whole list for another 5, then look at 2 and search the whole list for a 8, then look at 7 and search the whole list for a 3... which there is! and we've found our solution. However, how efective is this? For every movie, we search the whole list, which gives us a poor runtime of **O(n^2)**. We can certainly do better. </br>
</br>
There is a way to know if there is a movie with the exact remaining hours without having to look through the entire list. How about we hash? we can know whether we've seen a movie with such length, in constant lookup time. This strategy would require us, in the worst case scenario, to go through all the movies listed and have constant time lookups for our second movie choice, **O(n)**. If we get to the end of the movies listed without finding such movie pair, that means whatching 2 movies during flight is not possible, and you must find something else to do. </br>
</br>
I invite you to go check out my full solution to this problem in *C++*. I've included a sample file *input.txt* so that you can see this solution works. This file has the following format:
- first, a number *t* indicating the number of test cases.
- then, *t* lines follow, each containing first a number *n* for the number of movies in that test case. After this, *n* numbers follow, each representing the length for a movie.

My program outputs *t* lines, each with format
```
CASE #i: yes/no
```
a yes or no answer to a particular test number *i*.
