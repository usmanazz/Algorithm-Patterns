#include <iostream>
#include <vector>

using namespace std;

// PROBLEM: Given an array of positive numbers and a positive number ‘k,’ 
// find the maximum sum of any contiguous subarray of size ‘k’.

// EXAMPLE: Input: [2, 1, 5, 1, 3, 2], k=3 
//          Output: 9
//          Explanation: Subarray with maximum sum is [5, 1, 3].

class MaxSumSubArrayOfSizeK {
 public:
  static int findMaxSumSubArray(int k, const vector<int>& arr) {
    if (arr.empty())
    return 0;

    int maxSum = 0;
    int start = 0;
    int runningSum = 0;
    
    for (int end = 0; end < arr.size(); end++) {
      runningSum += arr[end];

      // begin moving window once window size == k
      if (end >= k - 1) {
        maxSum = max(maxSum, runningSum);
        runningSum -= arr[start];
        start++;
      }
    }
    return maxSum;
  }

  // Time : O(n) to iterate thru array in 1 pass
  // Space: O(1) constant additional space
};
