using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

// PROBLEM: Given a string with lowercase letters only, if you are allowed to replace no more than k letters with any letter, 
// find the length of the longest substring having the same letters after replacement.

// EXAMPLE: Input: String="aabccbb", k=2
//          Output: 5
//          Explanation: Replace the two 'c' with 'b' to have the longest repeating substring "bbbbb".

class CharacterReplacement {
 public:
  static int findLength(const string& str, int k) {
    if (str.length() == 0)
      return 0;

    int maxLength = 0;
    int maxFreq = 0;
    int start = 0;
    unordered_map<char, int> map;

    for (int end = 0; end < str.length(); end++) {
      // add to map
      if (map.find(str[end]) == map.end())
        map[str[end]] = 0;
      map[str[end]]++;

      // don’t we need to update this count when we shrink the window since we have to replace all the 
      // remaining letters to get the longest substring having the same letter in any window, we can’t get 
      // a better answer from any other window even though all occurrences of the letter with 
      // frequency maxRepeatLetterCount is not in the current window.
      maxFreq = max(maxFreq, map[str[end]]);

      // if current substring has more than k chars to replace
      // shrink substring until can make k replacements
      while (end - start + 1 - maxFreq > k) {
        char startChar = str[start];
        map[startChar]--;

        if (map[startChar] == 0)
          map.erase(startChar);

        start++;
      }
      maxLength = max(maxLength, end - start + 1);
    }
    return maxLength;
  }

  // Time : O(n) to iterate thru whole array
  // Space: O(n) worst case store freq of n distinct elements in map
};