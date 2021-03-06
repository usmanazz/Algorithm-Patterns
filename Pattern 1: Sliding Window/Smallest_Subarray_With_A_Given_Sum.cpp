using namespace std;

#include <iostream>
#include <limits.h>
#include <vector>

// PROBLEM: Given an array of positive numbers and a positive number āS,ā find the length of the 
// smallest contiguous subarray whose sum is greater than or equal to āSā. Return 0 if no such subarray exists.

// EXAMPLE: Input: [2, 1, 5, 2, 3, 2], S=7 
//          Output: 2
//          Explanation: The smallest subarray with a sum greater than or equal to '7' is [5, 2].

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    int windowSum = 0
    int minLength = INT_MAX;
    int windowStart = 0;
    
    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
      windowSum += arr[windowEnd];  // add the next element
      
      // shrink the window as small as possible until the 'windowSum' is smaller than 'S'
      while (windowSum >= S) {
        minLength = min(minLength, windowEnd - windowStart + 1);
        windowSum -= arr[windowStart];  // subtract the element going out
        windowStart++;                  // slide the window ahead
      }
    }

    return minLength == INT_MAX ? 0 : minLength;
  }

  // Time: O(n) to iterate thru array
  // Space: O(1) additional space
};