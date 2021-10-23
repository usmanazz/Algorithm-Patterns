using namespace std;

#include <iostream>
#include <vector>

// PROBLEM: Given an array of numbers sorted in an ascending order, find the ceiling of a given number ‘key’. The ceiling of 
// the ‘key’ will be the smallest element in the given array greater than or equal to the ‘key’. Write a function to return 
// the index of the ceiling of the ‘key’. If there isn’t any ceiling return -1.

// EXAMPLE: Input: [4, 6, 10], key = 6
//          Output: 1
//          Explanation: The smallest number greater than or equal to '6' is '6' having index '1'.

class CeilingOfANumber {
 public:
  static int searchCeilingOfANumber(const vector<int>& arr, int key) {
    if (key > arr.back())
      return -1;

    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (arr[mid] == key)
        return mid;
      else if (arr[mid] < key)
        left = mid + 1;
      else
        right = mid - 1;
    }

    // left will point at smallest number greater than key
    return left;
  }

  // Time: O(logn) to reduce search space by half every iteration
  // Space: O(1) additional space
};