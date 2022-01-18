using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// PROBLEM: Given two integer arrays to represent weights and profits of ‘N’ items, we need to find a subset of these items which 
// will give us maximum profit such that their cumulative weight is not more than a given number ‘C.’ Each item can only be selected 
// once, which means either we put an item in the knapsack or we skip it.

class Knapsack {
 public:
  int solveKnapsack(const vector<int> &profits, vector<int> &weights, int capacity) {
    unordered_map<string, int> memo;
    return maxProfit(profits, weights, capacity, 0, memo);
  }

 private:
  int maxProfit(const vector<int> &profits, vector<int> &weights, int capacity, int idx, 
  unordered_map<string, int>& memo) {
    if (capacity == 0 || idx >= weights.size())
     return 0;

    string prevData = to_string(idx) + "," + to_string(capacity);
    if (memo.find(prevData) != memo.end())
      return memo[prevData];

    int profit1 = 0;
    if (weights[idx] <= capacity)
      profit1 = profits[idx] + maxProfit(profits, weights, capacity - weights[idx], idx+1, memo);
    int profit2 = maxProfit(profits, weights, capacity, idx+1, memo);

    string currProfit = to_string(idx) + "," + to_string(capacity);
    memo[currProfit] = max(profit1, profit2);
    return memo[currProfit];
  }


  // n = number of items
  // c = capacity
  // Time: O(n*c) because at worst case we go thru n items and for each item, go thru c capacities
};
												