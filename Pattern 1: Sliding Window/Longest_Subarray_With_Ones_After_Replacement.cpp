using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

// PROBLEM: Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s, 
// find the length of the longest contiguous subarray having all 1s.

// EXAMPLE: Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
//          Output: 6
//          Explanation: Replace the '0' at index 5 and 8 to have the longest contiguous subarray of 1s having length 6.

class ReplacingOnes {
 public:
  static int findLength(const vector<int>& arr, int k) {
    if (arr.empty())
    return 0;

    int  maxLength = 0;
    int replacementsLeft = 0;
    int start = 0;

    for (int end = 0; end < arr.size(); end++) {
      if (arr[end] == 0)
        replacementsLeft++;

      // we're not concerned with having a valid window so it doesn't matter if we shrink the window or not. 
      // we're only concerned with finding a better answer (a longer window) so we only care about expanding the window 
      // by one when find a better answer, otherwise we just maintain the current valid size with just a single left++
      if (replacementsLeft > k) {
        if (arr[start] == 0)
          replacementsLeft--;
        start++;
      }
      maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
  }

  // Time : O(n) to iterate thru array
  // Space: O(1) constant additional space
};