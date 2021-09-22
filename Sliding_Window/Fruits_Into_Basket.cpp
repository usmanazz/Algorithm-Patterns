using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

// PROBLEM: Given an array of characters where each character represents a fruit tree, you are given two baskets, and your goal 
// is to put maximum number of fruits in each basket. The only restriction is that each basket can have only one type of fruit.
// You can start with any tree, but you can’t skip a tree once you have started. You will pick one fruit from each tree until 
// you cannot, i.e., you will stop when you have to pick from a third fruit type.
// Write a function to return the maximum number of fruits in both baskets.

// EXAMPLE: Input: Fruit=['A', 'B', 'C', 'A', 'C']
//          Output: 3
//          Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']

class MaxFruitCountOf2Types {
 public:
  static int findLength(const vector<char>& arr) {
    if (arr.empty())
    return 0;

    int maxLength = 0;
    unordered_map<char, int> map;
    int currLength = 0;
    int start = 0;
    
    for (int end = 0; end < arr.size(); end++) {
      currLength++;

      // add char to map
      if (map.find(arr[end]) == map.end()) {
        map[arr[end]] = 0;
      }
      map[arr[end]]++;

      // exceeded number of trees so update start ptr
      while (map.size() > 2) {
        int startChar = arr[start];
        map[startChar]--;
        currLength--;
        
        if (map[startChar] == 0) {
          map.erase(startChar);
        }
        start++;
      }

      // update max
      maxLength = max(maxLength, currLength);
    }
    return maxLength;
  }

  // Time: O(n) to iterate thru array
  // Space: O(1) since map will contain worst case 3 types of fruit
};