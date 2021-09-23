using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

// PROBLEM: Given a string, find the length of the longest substring in it with no more than K distinct characters.

// EXAMPLE: Input: String="araaci", K=2
//          Output: 4
//          Explanation: The longest substring with no more than '2' distinct characters is "araa".

class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int windowStart = 0
    int maxLength = 0;
    unordered_map<char, int> map;
    
    // in the following loop we'll try to extend the range [windowStart, windowEnd]
    for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
      char rightChar = str[windowEnd];
      map[rightChar]++;
      
      // shrink the sliding window, until we are left with 'k' 
      // distinct characters in the frequencymap
      while (map.size() > k) {
        char leftChar = str[windowStart];
        map[leftChar]--;
        if (map[leftChar] == 0) {
          map.erase(leftChar);
        }
        windowStart++; // shrink the window
      }
      maxLength = max(maxLength, windowEnd - windowStart + 1); // remember the maximum length so far
    }

    return maxLength;
  }

  // Time: O(n) to iterate thru array
  // Space: O(k) worst case map contains k == n elements
};