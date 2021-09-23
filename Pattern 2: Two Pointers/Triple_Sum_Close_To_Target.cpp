using namespace std;

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

// PROBLEM: Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is 
// as close to the target number as possible, return the sum of the triplet. If there are more than one such 
// triplet, return the sum of the triplet with the smallest sum.

// EXAMPLE: Input: [-2, 0, 1, 2], target=2
//          Output: 1
//          Explanation: The triplet [-2, 1, 2] has the closest sum to the target.

class TripletSumCloseToTarget {
 public:
  static int searchTriplet(vector<int>& arr, int targetSum) {
    if (arr.empty())
      return -1;

    // to identify and avoid duplicates
    sort(arr.begin(), arr.end());

    int minDistToTarget = INT_MAX;
    int sumClosestToTarget = INT_MAX;

    for (int i=0; i < arr.size() - 2; i++) {
      getTripletSum(arr, targetSum, arr[i], i + 1, minDistToTarget, sumClosestToTarget);
    }

    return sumClosestToTarget;
  }

private:
  static void getTripletSum(vector<int>& arr, int targetSum, int value, int left, int &minDistToTarget, 
    int &sumClosestToTarget) {
      int right = arr.size() - 1;

      while (left < right) {
        int currSum = value + arr[left] + arr[right];

        // update sum closest to target 
        int currDist = abs(currSum - targetSum);
        if (currDist < minDistToTarget) {
          minDistToTarget = currDist;
          sumClosestToTarget = currSum;
        } 
        else if (currDist == minDistToTarget) {
          // if dist equal, return smaller sum
          sumClosestToTarget = min(currSum, sumClosestToTarget);
        }

        // try to get closer to target sum
        if (currSum < targetSum)
          left++;
        else if (currSum > targetSum)
          right--;
      }
    }

    // Time : O(N^2) to iterate thru array and iterate thru subarray to find triplets
    // Space: O(N) or O(log N) depending on sorting alg
};