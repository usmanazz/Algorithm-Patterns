using namespace std;

#include <iostream>
#include <queue>
#include <vector>

// PROBLEM: Given a set of investment projects with their respective profits, we need to find the most profitable projects. 
// We are given an initial capital and are allowed to invest only in a fixed number of projects. Our goal is to choose 
// projects that give us the maximum profit. Write a function that returns the maximum total capital after selecting the 
// most profitable projects. We can start an investment project only when we have the required capital. Once a project is selected, 
// we can assume that its profit has become our capital.

// EXAMPLE: Input: Project Capitals=[0,1,2], Project Profits=[1,2,3], Initial Capital=1, Number of Projects=2
//          Output: 6


class MaximizeCapital {
 public:
  static int findMaximumCapital(const vector<int> &capital, const vector<int> &profits,
                                int numberOfProjects, int initialCapital) {

    if (capital.empty())
      return initialCapital;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cap;
    priority_queue<pair<int, int>> pro;

    // add all capitals to min heap
    for (int i=0; i < capital.size(); i++) {
      cap.push(make_pair(capital[i], i));
    }

    int availableCapital = initialCapital;
    while (numberOfProjects > 0) {

      // add all projects that can be started with current capital
      while (!cap.empty() && availableCapital >= cap.top().first) {
        int capIndex = cap.top().second;
        cap.pop();
        pro.push(make_pair(profits[capIndex], capIndex));
      }

      // if found no projects with current capital, return;
      if (pro.empty())
        return availableCapital;

      availableCapital += pro.top().first;
      pro.pop();
      numberOfProjects--;
    }

    return availableCapital;
  }

  // Time: O(nlogn + klogn), nlogn to create minheap and klogn to process 
  //       k numberOfProjects from maxheap 

  // Space: O(n) to maintain min-heap (maxheap contains max n elements) 
};