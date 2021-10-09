using namespace std;

#include <iostream>
#include <vector>

// PROBLEM: Given a list of non-overlapping intervals sorted by their start time, insert a given interval at the 
// correct position and merge all necessary intervals to produce a list that has only mutually exclusive intervals.

// EXAMPLE: Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,6]
//          Output: [[1,3], [4,7], [8,12]]
//          Explanation: After insertion, since [4,6] overlaps with [5,7], we merged them into one [4,7].


class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class InsertInterval {
 public:
  static vector<Interval> insert(const vector<Interval> &intervals, Interval newInterval) {
    if (intervals.empty())
      return {newInterval};

    vector<Interval> ans;

    // add all intervals to result with start < newInterval
    int i = 0;
    while (i < intervals.size() && intervals[i].start < newInterval.start) {
      ans.push_back(intervals[i]);
      i++;
    }

    // add newInterval to result (it may or may not overlap with most recent interval added)
    if (ans.empty() || ans[ans.size() - 1].end < newInterval.start)
      ans.push_back(newInterval);
    else {
      Interval recentInterval = ans[ans.size() - 1];
      int mergedEnd = newInterval.end > recentInterval.end ? newInterval.end : recentInterval.end;
      Interval merged = {recentInterval.start, mergedEnd};
      ans.pop_back();
      ans.push_back(merged);
    }

    // add rest of intervals to result
    while (i < intervals.size()) {
      Interval interval = intervals[i];
      Interval recentIntervalAdded = ans[ans.size() - 1];

      if (recentIntervalAdded.end < interval.start)
        ans.push_back(interval);
      else {
        int mergeEnd = interval.end > recentIntervalAdded.end ? interval.end : 
                       recentIntervalAdded.end;
        Interval merged = {recentIntervalAdded.start, mergeEnd};
        ans.pop_back();
        ans.push_back(merged);                       
      }
      i++;
    }

    return ans;
  }

  // Time : O(N) to process all elements in list
  // Space: O(N) to create new list worst case all elements dont overlap
};