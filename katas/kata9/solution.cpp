#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool two_movies_possible(int flight_length, vector<int> movie_lengths){
  map<int, bool> pairs;
  int hours_left, length;
  for(int movie=0; movie<movie_lengths.size(); movie++){
    length = movie_lengths[movie];
    if(length != flight_length && length > 0){
      hours_left = flight_length - length;
      // printf(" len:%d hrs_lft:%d\n", length, hours_left);
      if(pairs.find(length) != pairs.end()){
        return true;
      } else {
        pairs[hours_left] = true;
      }
    }
  }
  return false;
}

int main(){
  int tests, flight_length, movies, length;
  vector<int> movie_lengths;
  cin >> tests;
  for(int test=0; test<tests; test++){
    cin >> flight_length >> movies;
    movie_lengths.clear();
    for(int movie=0; movie<movies; movie++){
      cin >> length;
      movie_lengths.push_back(length);
    }
    printf("CASE #%d: %s\n", test+1, two_movies_possible(flight_length, movie_lengths)?"yes":"no");
  }
  return 0;
}
