using namespace std;

#include <iostream>
#include <vector>

// PROBLEM: Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target. 
// Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target.

// EXAMPLE: Input: [1, 2, 3, 4, 6], target=6
//          Output: [1, 3]
//          Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6

class PairWithTargetSum {
 public:
  static pair<int, int> search(const vector<int>& arr, int targetSum) {
    if (arr.empty())
      return make_pair(-1, -1);

    int start = 0;
    int end = arr.size() - 1;

    while (start < end) {
      if (arr[start] + arr[end] > targetSum)
        end--;
      else if (arr[start] + arr[end] < targetSum)
        start++;
      else
        return make_pair(start, end);
    }

    return make_pair(-1, -1);
  }

  // Time: O(N) to iterate thru array
  // Space: O(1) additional space
};