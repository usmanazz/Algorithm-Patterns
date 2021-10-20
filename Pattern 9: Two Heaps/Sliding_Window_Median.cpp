using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <queue>

// PROBLEM: Given an array of numbers and a number ‘k’, find the median of all the ‘k’ sized sub-arrays (or windows) of the array.

// EXAMPLE: Input: nums=[1, 2, -1, 3, 5], k = 2
//          Output: [1.5, 0.5, 1.0, 4.0]

class SlidingWindowMedian {
 public:
  virtual vector<double> findSlidingWindowMedian(const vector<int> &nums, int k) {
    vector<double> result;

    if (nums.empty() || k > nums.size())
      return {};

    int start = 0;
    for (int end = 0; end < nums.size(); end++) {
      if (end > k - 1) {
        start++;
      }

      if (end >= k - 1) {
        priority_queue<int> lo;
        priority_queue<int, vector<int>, greater<int>> hi;

        int left = start;
        while (left <= end) {
          // push subarr elements onto heaps
          if (lo.empty() || lo.top() >= nums[left])
            lo.push(nums[left]);
          else
            hi.push(nums[left]);

          // balance heap where both heaps size are equal or 
          // lo is greater than hi by 1
          if (lo.size() > hi.size() + 1) {
            hi.push(lo.top());
            lo.pop();
          } else if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
          }

          left++;
        }

        // get median and add to result array
        if (lo.size() == hi.size()) {
          result.push_back((lo.top() + hi.top()) / 2.0);
        } else {
          result.push_back(lo.top());
        }
      }
    }

    return result;
  }
};