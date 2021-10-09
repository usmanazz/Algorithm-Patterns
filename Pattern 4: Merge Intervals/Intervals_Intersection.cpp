using namespace std;

#include <iostream>
#include <vector>

// PROBLEM: Given two lists of intervals, find the intersection of these two lists. Each list consists of 
// disjoint intervals sorted on their start time.

// EXAMPLE: Input: arr1=[[1, 3], [5, 6], [7, 9]], arr2=[[2, 3], [5, 7]]
//          Output: [2, 3], [5, 6], [7, 7]
//          Explanation: The output list contains the common intervals between the two lists.

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class IntervalsIntersection {
 public:
  static vector<Interval> merge(const vector<Interval> &arr1, const vector<Interval> &arr2) {
    vector<Interval> result;

    if (arr1.empty() || arr2.empty())
      return {};

    int ptr1 = 0;
    int ptr2 = 0;

    while (ptr1 < arr1.size() && ptr2 < arr2.size()) {
      // if they overlap
      if (arr1[ptr1].start >= arr2[ptr2].start && arr1[ptr1].start <= arr2[ptr2].end ||
      arr2[ptr2].start >= arr1[ptr1].start && arr2[ptr2].start <= arr1[ptr1].end) {
        
        int start = max(arr1[ptr1].start, arr2[ptr2].start);
        int end = min(arr1[ptr1].end, arr2[ptr2].end);
        result.push_back({start, end});
      }

      // increment the ptr with the end time that ends sooner
      if (arr1[ptr1].end < arr2[ptr2].end)
        ptr1++;
      else
        ptr2++;
    }

    return result;
  }
  
  // Time: O(N + M) number of elements in arr1 and arr2
  // Space: O(N + M) the max size is number of elements in both lists
};