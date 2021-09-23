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

      // went over replacement limit of k, increment start ptr and 
      // increase replacementsLeft if start points at a 0. 
      // we only need to shrink the subarray by 1 if we go over limit k
      // since we're just trying to stay within the limit and avoid 
      // doing more computations
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