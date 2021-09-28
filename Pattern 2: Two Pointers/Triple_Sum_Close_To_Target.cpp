using namespace std;

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

// PROBLEM: Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close 
// to the target number as possible, return the sum of the triplet. If there are more than one such triplet, 
// return the sum of the triplet with the smallest sum.

// EXAMPLE: Input: [-2, 0, 1, 2], target=2
//          Output: 1
//          Explanation: The triplet [-2, 1, 2] has the closest sum to the target.


class TripletSumCloseToTarget {
 public:
  static int searchTriplet(vector<int>& arr, int targetSum) {
    if (arr.empty())
      return -1;

    int dist = INT_MAX;
    int ans = -1;

    for (int i=0; i < arr.size() - 2; i++) {
      findTripletSum(arr, targetSum, arr[i], i + 1, dist, ans);
    }

    return ans;
  }

 private:
  static void findTripletSum(vector<int>& arr, int targetSum, int value, int left, 
  int& dist, int& ans) {
    
    int right = arr.size() - 1;

    while (left < right) {
      int curSum = value + arr[left] + arr[right];
      int curDist = abs(targetSum - curSum);
      
      // found new sum closer to targetSum
      if (curDist < dist) {
        dist = curDist;
        ans = curSum;
      }
      // if more than 1 triplet with sum close to target, return smaller
      else if (curDist == dist) {
        ans = min(ans, curSum);
      }

      // iterate thru subarray
      if (curSum < targetSum)
        left++;
      else if (curSum > targetSum)
        right--;
      else
        break;
    }
  } 

  // Time : O(N^2) to iterate thru array and iterate thru subarray to find triplets
  // Space: O(N) or O(log N) depending on sorting alg
};