using namespace std;

#include <iostream>
#include <vector>

// PROBLEM: Find the maximum value in a given Bitonic array. An array is considered bitonic if it is monotonically increasing 
// and then monotonically decreasing. Monotonically increasing or decreasing means that for any index i in 
// the array arr[i] != arr[i+1].

// EXAMPLE: Input: [1, 3, 8, 12, 4, 2]
//          Output: 12
//          Explanation: The maximum number in the input bitonic array is '12'.

class MaxInBitonicArray {
 public:
  static int findMax(const vector<int>& arr) {
    if (arr.empty())
      return -1;
    if (arr.size() == 1)
      return arr[0];

    int left = 0;
    int right = arr.size() - 1;

    // break when left == right since they both will be pointing at max element
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (arr[mid] > arr[mid + 1])
        right = mid;
      else {
        // arr[mid] is less than arr[mid + 1] so max element 
        // must be between mid + 1 and right
        left = mid + 1;
      }

    }

    return arr[left];
  }

  // Time: O(logn) for binary search
  // Space: O(1)
};