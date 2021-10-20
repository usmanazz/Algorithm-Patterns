using namespace std;

#include <iostream>
#include <queue>
#include <vector>
#include <queue>

// PROBLEM: Given an array of intervals, find the next interval of each interval. In a list of intervals, for an interval ‘i’ 
// its next interval ‘j’ will have the smallest ‘start’ greater than or equal to the ‘end’ of ‘i’. Write a function to return an 
// array containing indices of the next interval of each input interval. If there is no next interval of a given interval, return -1. 
// It is given that none of the intervals have the same start point.

// EXAMPLE: Input: Intervals [[2,3], [3,4], [5,6]]
//          Output: [1, 2, -1]
//          Explanation: The next interval of [2,3] is [3,4] having index ‘1’. Similarly, the next interval of [3,4] is [5,6] 
//          having index ‘2’. There is no next interval for [5,6] hence we have ‘-1’.

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class NextInterval {
 public:
  static vector<int> findNextInterval(const vector<Interval> &intervals) {
    if (intervals.empty())
      return {};

    vector<int> result(intervals.size());
    // pair: <start/end time, index>
    priority_queue<pair<int, int>> maxStart;
    priority_queue<pair<int, int>> maxEnd;

    // create maxstart and maxend heaps
    for (int i=0; i < intervals.size(); i++) {
      maxStart.push(make_pair(intervals[i].start, i));
      maxEnd.push(make_pair(intervals[i].end, i));
    }

    while (!maxEnd.empty()) {
      // find the next interval of the interval which has the highest 'end'
      auto maxEndTop = maxEnd.top();
      maxEnd.pop();
      // store default if cant find next interval
      result[maxEndTop.second] = -1;
      
      if (maxStart.top().first >= maxEndTop.first) {
        auto startTop = maxStart.top();

        // find interval that has closest start
        while (!maxStart.empty() && maxStart.top().first >= maxEndTop.first) {
          startTop = maxStart.top();
          maxStart.pop();
        }

        // update next interval if found one
        result[maxEndTop.second] = startTop.second;
        // add start back into heap as it could be the next interval of other intervals
        // all previous starts that were popped cant be the next for other intervals since
        // they were greater than the end of the current Interval
        maxStart.push(startTop);
      }
    }

    return result;
  }

  // Time: O(nlogn) to create 2 heaps and process all intervals
  // Space: O(n) to store all intervals in 2 heaps and return result of size n
};