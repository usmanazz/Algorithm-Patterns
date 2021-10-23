using namespace std;

#include <iostream>
#include <vector>

// PROBLEM: Given an array of numbers sorted in ascending order, find the element in the array that has the minimum difference 
// with the given ‘key’.

// EXAMPLE: Input: [4, 6, 10], key = 7
//          Output: 6
//          Explanation: The difference between the key '7' and '6' is minimum than any other number in the array 

class MinimumDifference {
 public:
  static int searchMinDiffElement(const vector<int>& arr, int key) {
    if (key < arr[0])
      return arr[0];
    if (key > arr.back())
      return arr.back();
    
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (arr[mid] < key)
        left = mid + 1;
      else if (arr[mid] > key)
        right = mid - 1;
      else {
        return arr[mid];
      }
    }

   // could not find target so after while loop:
   // left points at ceil of key
   // right points at floor of key
   // get the min difference element of the 2
   return abs(key - arr[left]) < abs(key - arr[right]) ? arr[left] : arr[right];
  }

  // Time: O(logn) for binary search
  // Space: O(1) additional space for ptrs
};