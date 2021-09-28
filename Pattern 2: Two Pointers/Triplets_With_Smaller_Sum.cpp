using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

// PROBLEM: Given an array arr of unsorted numbers and a target sum, count all triplets in it such that 
// arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices. Write a function to 
// return the count of such triplets.

// EXAMPLE: Input: [-1, 4, 2, 1, 3], target=5 
//          Output: 4
//          Explanation: There are four triplets whose sum is less than the target: 
//          [-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3]

class TripletWithSmallerSum {
 public:
  static int searchTriplets(vector<int> &arr, int target) {
    if (arr.empty())
      return 0;

    int count = 0;
    sort(arr.begin(), arr.end());

    for (int i=0; i < arr.size() - 2; i++) {
      count += searchPairs(arr, target - arr[i], i + 1);
    }

    return count;
  }

private:
  static int searchPairs(vector<int> &arr, int target, int left) {
    int count = 0;
    int right = arr.size() - 1;

    while (left < right) {
      int curSum = arr[left] + arr[right];

      if (curSum < target) {
        // since arr[right] >= arr[left], therefore, we can replace arr[right] by any number between
        // left and right to get a sum less than the target sum.
        // so count will equal all the values arr[right] can be between right and left
        count += right - left;
        left++;

      } else {
        right--;
      }
    }

    return count;
  }

  // Time : O(N^2) to iterate thru array and for each element, process N elements in subarray
  // Space: O(N) space for sorting
};