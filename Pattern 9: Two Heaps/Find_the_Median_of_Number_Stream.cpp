using namespace std;

#include <iostream>
#include <queue>
#include <vector>
#include <queue>

class MedianOfAStream {
  priority_queue<int> maxQ;
  priority_queue<int, vector<int>, greater<int>> minQ;
 public:
  virtual void insertNum(int num) {
    // TODO: Write your code here
    if (maxQ.empty() || maxQ.top() >= num)
      maxQ.push(num);
    else
      minQ.push(num);

    // check first half of numbers size is greater than second half by at max 1
    if (maxQ.size() > minQ.size() + 1) {
      minQ.push(maxQ.top());
      maxQ.pop();
    } else if (maxQ.size() < minQ.size()) {
      maxQ.push(minQ.top());
      minQ.pop();
    }
  }

  virtual double findMedian() {
    if (maxQ.size() == minQ.size()) {
      // we have even number of elements, take the average of middle two elements
      return (maxQ.top() + minQ.top()) / 2.0;
    }
    // because max-heap will have one more element than the min-heap
    return maxQ.top();
  }

  // Time: O(logn) to insert and delete from both heaps
  // Space: O(N) to store all numbers in total
};