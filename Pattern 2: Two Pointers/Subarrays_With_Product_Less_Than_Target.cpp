using namespace std;

#include <deque>
#include <iostream>
#include <vector>
#include <list>

class SubarrayProductLessThanK {
 public:
  static vector<vector<int>> findSubarrays(const vector<int>& arr, int target) {
    vector<vector<int>> result;

    if (arr.empty())
      return {};

    int start = 0;
    int currProduct = 1;
    for (int end=0; end < arr.size(); end++) {
      currProduct *= arr[end];

      // shrink window until product less than target or
      // no such subarry exists at this point (start went pass end of array)
      while (currProduct >= target && start < arr.size()) {
        int startNum = arr[start];
        start++;
        currProduct /= startNum;
      }

      // add all subarrays to answer
      list<int> li;
      for (int i=end; i >= start; i--) {
        li.push_front(arr[i]);

        // convert list to arr and add to answer arr
        vector<int> subarr;
        list<int>::iterator it;
        for (it = li.begin(); it != li.end(); it++) {
          subarr.push_back(*it);
        }

        result.push_back(subarr);
      }
    }

    return result;
  }

  // Time: O(N^3) to iterate thru array and create O(n^2) possible subarrays
  // Space: O(N^3) there are n^2 continuous subarrays in worst case and worst case each subarray
  //        takes up O(N) space
};