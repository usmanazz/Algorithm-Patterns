using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

// PROBLEM: There is a dictionary containing words from an alien language for which we don’t know the ordering of the alphabets. 
// Write a method to find the correct order of the alphabets in the alien language. It is given that the input is a valid 
// dictionary and there exists an ordering among its alphabets.

// EXAMPLE: Input: Words: ["ba", "bc", "ac", "cab"]
//          Output: bac
//          Explanation: Given that the words are sorted lexicographically by the rules of the alien language, so
//          from the given words we can conclude the following ordering among its characters:
//
//          1. From "ba" and "bc", we can conclude that 'a' comes before 'c'.
//          2. From "bc" and "ac", we can conclude that 'b' comes before 'a'

From the above two points, we can conclude that the correct character order is: "bac"

class AlienDictionary {
 public:
  static string findOrder(const vector<string> &words) {
    // 1. compare 2 adj words and get first mismatch if it exists and 
    //    add relationship to adj list graph and indegree
    // 2. add any char with indegree of 0 to queue to be processed and
    //    added to result
    // 3. process chars and their neighbors in queue
    
    string res = "";
    unordered_map<char, int> indegree;
    unordered_map<char, vector<char>> graph;
    queue<char> q;

    // initialize indegree for all characters
    for (auto& word : words) {
      for (auto& c : word) {
        indegree[c] = 0;
      }
    }

    // create adj list and indegree mapping
    for (int i=0; i < words.size() - 1; i++) {
      string w1 = words[i]; 
      string w2 = words[i + 1];

      int j = 0;
      while (j < w1.length() && j < w2.length()) {
        if (w1[j] != w2[j]) {
          graph[w1[j]].push_back(w2[j]);
          indegree[w2[j]]++;
          break; // only first diff char between 2 words will help us find order
        }

        j++;
      }
    }

    // add any chars to result order that have indegree of 0
    for (auto& entry : indegree) {
      if (entry.second == 0) {
        q.push(entry.first);
      }
    }

    while (!q.empty()) {
      char parent = q.front();
      q.pop();

      res += parent;

      for (auto& child : graph[parent]) {
        indegree[child]--;

        if (indegree[child] == 0) {
          q.push(child);
        }
      }
    }


    return res.length() == indegree.size() ? res : "";
  }

  // Time: O(V + E) where V is number of distinct chars and E is number of words
  //       since worst case each pair of words can give us at most 1 rule
  // Space: O(V + E) to store rules for each character in adj list
};