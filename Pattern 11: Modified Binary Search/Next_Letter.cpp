using namespace std;

#include <iostream>
#include <vector>

// PROBLEM: Given an array of lowercase letters sorted in ascending order, find the smallest letter in the given array greater 
// than a given ‘key’. Assume the given array is a circular list, which means that the last letter is assumed to be connected 
// with the first letter. This also means that the smallest letter in the given array is greater than the last letter of the array 
// and is also the first letter of the array. Write a function to return the next letter of the given ‘key’.

// EXAMPLE: Input: ['a', 'c', 'f', 'h'], key = 'h'
//          Output: 'a'
//          Explanation: As the array is assumed to be circular, the smallest letter greater than 'h' is 'a'.

class NextLetter {
 public:
  static char searchNextLetter(const vector<char>& letters, char key) {
    // handle cases: 
    // 1. key is greater than or equal last element of array
    // 2. key is less than first element of array
    if (key >= letters.back() || key < letters[0])
      return letters[0];

    int left = 0;
    int right = letters.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (letters[mid] <= key)
        left = mid + 1;
      else
        right = mid - 1;
    }

    // guaranteed to return smallest letter greater than key
    return letters[left];
  }

  // Time: O(logn) for binary search
  // Space: O(1) additional space
};