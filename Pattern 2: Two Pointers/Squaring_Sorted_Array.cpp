using namespace std;

#include <iostream>
#include <vector>

// PROBLEM: Given a sorted array, create a new array containing squares of all the numbers of the input array in the sorted order.

// EXAMPLE: Input: [-2, -1, 0, 2, 3]
//          Output: [0, 1, 4, 4, 9]

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    if (arr.empty())
      return {};

    vector<int> ans(arr.size(), 0);
    int left = 0;
    int right = arr.size() - 1;
    int i = arr.size() - 1;
    
    while (left <= right) {
      int leftSquare = arr[left] * arr[left];
      int rightSquare = arr[right] * arr[right];

      if (leftSquare > rightSquare) {
        ans[i--] = leftSquare;
        left++;
      } else {
        ans[i--] = rightSquare;
        right--;
      }
    }

    return ans;
  }

  // Time : O(n) to iterate thru arr
  // Space: O(n) to return arr otherwise O(1)
};