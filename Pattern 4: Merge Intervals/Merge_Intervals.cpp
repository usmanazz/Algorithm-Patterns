using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

// PROBLEM: Given a list of intervals, merge all the overlapping intervals to produce a list that has only mutually exclusive intervals.

// EXAMPLE: Intervals: [[1,4], [2,5], [7,9]]
//          Output: [[1,5], [7,9]]
//          Explanation: Since the first two intervals [1,4] and [2,5] overlap, we merged them into 
//          one [1,5].

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MergeIntervals {
 public:
  static bool cmp(Interval& a, Interval& b) {
    return a.start < b.start;
  }

  static vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.empty())
      return {};

    sort(intervals.begin(), intervals.end(), cmp);
    
    vector<Interval> ans;
    ans.push_back(intervals[0]);

    for (int i=1; i < intervals.size(); i++) {
      Interval interval1 = ans[ans.size() - 1];
      Interval interval2 = intervals[i];

      if (interval2.start <= interval1.end) {
        if (interval2.end > interval1.end) {
          Interval merged = {interval1.start, interval2.end};
          ans.pop_back();
          ans.push_back(merged);
        }
      } else {
        // dont overlap so add curr interval to ans
        ans.push_back(interval2);
      }
    }

    return ans;
  }

  // Time : O(N logN) to sort intervals based on start time
  // Space: O(N) to construct new interval list in worst case
};