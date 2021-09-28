using namespace std;

#include <iostream>
#include <vector>

// PROBLEM: Given an array containing 0s, 1s and 2s, sort the array in-place. You should treat numbers of the array 
// as objects, hence, we can’t count 0s, 1s, and 2s to recreate the array. The flag of the Netherlands consists of 
// three colors: red, white and blue; and since our input array also consists of three different numbers that is 
// why it is called Dutch National Flag problem.

// EXAMPLE: Input: [1, 0, 2, 1, 0]
//          Output: [0 0 1 1 2]

class DutchFlag {
 public:
  static void sort(vector<int> &arr) {
    if (arr.empty())
      return;

    int curr = 0;
    int left = 0;
    int right = arr.size() - 1;

    while (curr <= right) {
      if (arr[curr] == 0) {
        swap(arr[curr], arr[left]);
        left++;
        curr++;
      }
      else if (arr[curr] == 1)
        curr++;
      else {
        // curr == 2 so swap with right and only increment right since
        // curr can still be a 0, 1, or 2

        swap(arr[curr], arr[right]);
        right--;
      }
    }
  }

  // Time : O(N) process each element once in arr
  // Space: O(1) constant additional space
};