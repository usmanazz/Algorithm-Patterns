using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

// PROBLEM: Given an array of intervals representing ‘N’ appointments, find out if a person can attend all the appointments.

// EXAMPLE: Appointments: [[1,4], [2,5], [7,9]]
//          Output: false
//          Explanation: Since [1,4] and [2,5] overlap, a person cannot attend both of these appointments.

class Interval {
 public:
  int start;
  int end;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class ConflictingAppointments {
 public:
  static bool cmp(Interval& a, Interval& b) {
    // sort by end time if starts are equal
    return a.start == b.start ? a.end < b.end : a.start < b.start;
  }

  static bool canAttendAllAppointments(vector<Interval>& intervals) {
    if (intervals.empty())
      return true;

    sort(intervals.begin(), intervals.end(), cmp);

    for (int i=0; i < intervals.size() - 1; i++) {
      Interval currInterval = intervals[i];
      Interval nextInterval = intervals[i + 1];

      if (nextInterval.start < currInterval.end)
        return false;
    }

    return true;
  }

  // Time: O(N logN) N elements in list
  // Space: O(1) or O(N) for underlying space taken by sorting
};