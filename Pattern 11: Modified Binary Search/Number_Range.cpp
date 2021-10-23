using namespace std;

#include <iostream>
#include <vector>

// PROBLEM: Given an array of numbers sorted in ascending order, find the range of a given number ‘key’. The range of the ‘key’ 
// will be the first and last position of the ‘key’ in the array. Write a function to return the range of the ‘key’. If the 
//‘key’ is not present return [-1, -1].

// EXAMPLE: Input: [4, 6, 6, 6, 9], key = 6
//          Output: [1, 3]

class FindRange {
 public:
  static pair<int, int> findRange(const vector<int> &arr, int key) {

    if (arr.empty())
      return make_pair(-1, -1);

    pair<int, int> result(-1, -1);

    result.first = search(arr, key, 0, arr.size() - 1, true);
    if (result.first == -1) // could not find key so return
      return result;
    result.second = search(arr, key, 0, arr.size() - 1, false);

    return result;
  }

 private:
  static int search(const vector<int> &arr, int key, int left, int right, bool isStart) {
    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (arr[mid] < key)
        left = mid + 1;
      else if (arr[mid] > key)
        right = mid - 1;
      else {
        // arr[mid] == key
        // need to find first/last occurence of key
        
        if (isStart) {
          if (mid == left || arr[mid - 1] != key)
            return mid;
          right = mid - 1;
        } else {
          if (mid == right || arr[mid + 1] != key)
            return mid;
          left = mid + 1;
        }
      }
    }

    return -1;
  }

  // Time: O(logn), 2logn to find both start and end of range
  // Space: O(1) additional space for ptrs
};