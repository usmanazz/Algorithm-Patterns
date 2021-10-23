using namespace std;

#include <iostream>
#include <limits>
#include <limits.h>
#include <vector>

// PROBLEM: Given an infinite sorted array (or an array with unknown size), find if a given number ‘key’ is present in the array. 
// Write a function to return the index of the ‘key’ if it is present in the array, otherwise return -1. Since it is not possible 
// to define an array with infinite (unknown) size, you will be provided with an interface ArrayReader to read elements of the array. 
// ArrayReader.get(index) will return the number at index; if the array’s size is smaller than the index, it will return 
// Integer.MAX_VALUE.

// EXAMPLE: Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 16
//          Output: 6
//          Explanation: The key is present at index '6' in the array.

class ArrayReader {
 public:
  vector<int> arr;

  ArrayReader(const vector<int> &arr) { this->arr = arr; }

  virtual int get(int index) {
    if (index >= arr.size()) {
      return numeric_limits<int>::max();
    }
    return arr[index];
  }
};

class SearchInfiniteSortedArray {
 public:
  static int search(ArrayReader *reader, int key) {
    if (reader->get(0) == INT_MAX)
      return -1;

    int left = 0;
    int right = 0;

    while (reader->get(right) < key) {
      left = right;
      right = right + 1 * 2;
    }

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (reader->get(mid) == key)
        return mid;
      else if (reader->get(mid) < key)
        left = mid + 1;
      else
        right = mid - 1;
    }

    return -1;
  }

  // Time: O(logn), 2logn to first find the bounds and then perform binary search
  // Space: O(1) additional space
};