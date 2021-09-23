using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

// PROBLEM: Given a string, find the length of the longest substring, which has all distinct characters.

// EXAMPLE: Input: String="aabccbb"
//          Output: 3
//          Explanation: The longest substring with distinct characters is "abc".

class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    if (str.length() == 0)
      return 0;

    int maxLength = 0;
    int currLength = 0;
    int start = 0;
    unordered_map<char, int> map;

    for (int end = 0; end < str.length(); end++) {
      currLength++;

      // add to map
      if (map.find(str[end]) == map.end())
        map[str[end]] = 0;
      map[str[end]]++;

      // if char is repeated, update start ptr until no repeated 
      // chars in curr substring
      while (map[str[end]] > 1) {
        char startChar = str[start];
        map[startChar]--;
        currLength--;

        if (map[startChar] == 0)
          map.erase(startChar);

        start++;
      }

      // update max
      maxLength = max(maxLength, currLength);
    }
    return maxLength;
  }

  // Time: O(n) to iterate thru array
  // Space: O(n) worst case string contains n distinct chars
};