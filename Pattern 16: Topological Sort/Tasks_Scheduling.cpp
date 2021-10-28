using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

// PROBLEM: There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’. Each task can have some prerequisite tasks which need to be completed 
// before it can be scheduled. Given the number of tasks and a list of prerequisite pairs, find out if it is possible to schedule 
// all the tasks.

// EXAMPLE: Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
//          Output: true
//          Explanation: To execute task '1', task '0' needs to finish first. Similarly, task '1' needs 
//          to finish before '2' can be scheduled. One possible scheduling of tasks is: [0, 1, 2] 

class TaskScheduling {
 public:
  static bool isSchedulingPossible(int tasks, const vector<vector<int>>& prerequisites) {
    if (tasks == 0 || prerequisites.empty())
      return false;

    vector<int> res;
    vector<int> indegree(tasks, 0);
    unordered_map<int, vector<int>> graph;
    queue<int> q;

    // initalize indegree and create adj list
    for (auto& prereq : prerequisites) {
      graph[prereq[0]].push_back(prereq[1]);
      indegree[prereq[1]]++;
    }

    // add any tasks with no prereqs to queue
    for (int task=0; task < tasks; task++) {
      if (indegree[task] == 0)
        q.push(task);
    }

    // process all nodes with indegree of 0 and their neighbors
    while (!q.empty()) {
      int prereq = q.front();
      q.pop();

      res.push_back(prereq);

      for (auto& req : graph[prereq]) {
        indegree[req]--;

        if (indegree[req] == 0)
          q.push(req);
      }
    }


    return res.size() == tasks;
  }

  // Time: O(V + E) for number of vertices and edges
  // Space: O(V + E) to create adj list
};