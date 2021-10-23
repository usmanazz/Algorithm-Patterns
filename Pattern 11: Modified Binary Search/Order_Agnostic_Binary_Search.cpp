using namespace std;

#include <iostream>
#include <vector>

// PROBLEM: Given a sorted array of numbers, find if a given number ‘key’ is present in the array. Though we know that the array 
// is sorted, we don’t know if it’s sorted in ascending or descending order. You should assume that the array can have duplicates. 
// Write a function to return the index of the ‘key’ if it is present in the array, otherwise return -1.

// EXAMPLE: Input: [4, 6, 10], key = 10
//          Output: 2

class BinarySearch {
 public:
  static int search(const vector<int>& arr, int key) {

    int left = 0;
    int right = arr.size() - 1;
    bool isAscending = arr[0] < arr.back();

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (arr[mid] == key)
        return mid;

      if (isAscending) {
        if (arr[mid] < key)
          left = mid + 1;
        else
          right = mid - 1;
      } else {
        if (arr[mid] < key)
          right = mid - 1;
        else
          left = mid + 1;
      }
    }

    return -1; 
  }

  // Time: O(logn) where n elements in array
  // Space: O(1) additional space for ptrs
};