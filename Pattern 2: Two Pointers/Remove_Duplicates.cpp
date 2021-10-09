using namespace std;

#include <iostream>
#include <vector>

// PROBLEM: Given an array of sorted numbers, remove all duplicates from it. You should not use any extra space; 
// after removing the duplicates in-place return the length of the subarray that has no duplicate in it.

// EXAMPLE: Input: [2, 3, 3, 3, 6, 9, 9]
//          Output: 4
//          Explanation: The first four elements after removing the duplicates will be [2, 3, 6, 9].

class RemoveDuplicates {
 public:
  static int remove(vector<int>& arr) {
    if (arr.empty())
      return -1;

    int insertIndex = 1;
    for (int i=1; i < arr.size(); i++) {
      if (arr[i - 1] != arr[i]) {
        arr[insertIndex] = arr[i];
        insertIndex++;
      }
    }

    return insertIndex;
  }

  // Time: O(n) to iterate thru array
  // Space: O(1) additional space
};