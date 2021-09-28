using namespace std;

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

// PROBLEM: Given a string and a pattern, find out if the string contains any permutation of the pattern. Permutation is 
// defined as the re-arranging of the characters of the string. For example, “abc” has the following six permutations.

// EXAMPLE: Input: String="oidbcaf", Pattern="abc"
//          Output: true
//          Explanation: The string contains "bca" which is a permutation of the given pattern.

class StringPermutation {
 public:
  static bool findPermutation(const string &str, const string &pattern) {
    if (str.length() == 0)
      return false;

    int matches = 0;
    int start = 0;
    unordered_map<char, int> map;

    // store char freq from pattern in map
    for (int i=0; i < pattern.length(); i++) {
      int currChar = pattern[i];
      if (map.find(currChar) == map.end())
        map[currChar] = 0;
      map[currChar]++;
    }

    // sliding window
    for (int end = 0; end < str.length(); end++) {
      int endChar = str[end];
      
      if (map.find(endChar) != map.end()) {
        map[endChar]--;
        if (map[endChar] == 0){ // found a match
          matches++;
        }
      }

      // found permutation
      if (matches == map.size())
        return true;

      // move window once it is at least the size of pattern
      if (end >= pattern.length() - 1) {
        int startChar = str[start];
        start++;

        if (map.find(startChar) != map.end()) {
          // if previously found a match, remove it from result
          if (map[startChar] == 0)
            matches--;
          // add back to pattern hash map
          map[startChar]++;
        }
      }
    }

    return false;
  }

  // Time: O(N + M), iterate thru n elements in str and iterate thru M elements in pattern
  // Space: O(M) worst case M distinct chars to store in map
};