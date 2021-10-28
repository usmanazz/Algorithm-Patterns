using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

// PROBLEM: Topological Sort of a directed graph (a graph with unidirectional edges) is a linear ordering of its vertices such 
// that for every directed edge (U, V) from vertex U to vertex V, U comes before V in the ordering. Given a directed graph, 
// find the topological ordering of its vertices.

// EXAMPLE: Input: Vertices=4, Edges=[3, 2], [3, 0], [2, 0], [2, 1]
//          Output: Following are the two valid topological sorts for the given graph:
//          1) 3, 2, 0, 1
//          2) 3, 2, 1, 0

class TopologicalSort {
 public:
  static vector<int> sort(int vertices, const vector<vector<int>>& edges) {
    vector<int> res;

    vector<int> inDegree(vertices, 0);
    unordered_map<int, vector<int>> graph;
    queue<int> q;

    // initialize indegree and create adj list
    for (auto& edge: edges) {
      graph[edge[0]].push_back(edge[1]);
      inDegree[edge[1]]++;
    }

    // add any nodes with indegree of 0 to queue to be processed
    for (int node=0; node < vertices; node++) {
      if (inDegree[node] == 0)
        q.push(node);
    }

    // process all nodes and its neighbors with bfs
    while (!q.empty()) {
      int node = q.front();
      q.pop();

      res.push_back(node);

      for (auto& neighbor : graph[node]) {
        inDegree[neighbor]--;

        if (inDegree[neighbor] == 0)
          q.push(neighbor);
      }
    }

    return res.size() == vertices ? res : vector<int>();
  }

  // Time: O(V + E) to process all nodes and their edges
  // Space: O(V + E) to maintain adj list and indegree vector
};