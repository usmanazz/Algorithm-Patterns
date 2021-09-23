using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

// PROBLEM: Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

// EXAMPLE: Input: [-3, 0, 1, 2, -1, 1, -2]
//          Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
//          Explanation: There are four unique triplets whose sum is equal to zero.

class TripletSumToZero {
 public:
  static vector<vector<int>> searchTriplets(vector<int> &arr) {
    vector<vector<int>> triplets;
    
    // 1. sort array to avoid duplicates
    // 2. iterate thru entire arr up to arr size - 2
    // 3. then find a pair in subarray where y + z = -x

    sort(arr.begin(), arr.end());

    for (int i=0; i < arr.size() - 2; i++) {
      // skip duplicates
      if (i > 0 && arr[i] == arr[i - 1]) {
        continue;
      }

      searchForPair(arr, -arr[i], i + 1, triplets);
    }

    return triplets;
  }

private:
  static void searchForPair(vector<int> &arr, int target, int left, 
    vector<vector<int>>& triplets) {

    int right = arr.size() - 1;

    while (left < right) {
      int sum = arr[left] + arr[right];
      if (sum == target) {
        triplets.push_back({-sum, arr[left], arr[right]});
        left++;
        right--;

        // avoid duplicates
        while (left < right && arr[left] == arr[left - 1]) left++;
        while (left < right && arr[right] == arr[right + 1]) right--;
      }
      else if (sum > target)
        right--;
      else
        left++;
    }
  }

  // Time : O(N^2) to iterate thru array and find pair for each element
  // Space : O(N) or O(log N) depending on sorting implementation
};