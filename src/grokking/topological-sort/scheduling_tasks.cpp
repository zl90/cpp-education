using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TaskScheduling {
 public:
  static bool isSchedulingPossible(int tasks,
                                   const vector<vector<int>>& prerequisites) {
    if (prerequisites.size() == 0) return false;
    vector<int> sorted;
    unordered_map<int, int> verticesWithIncomingEdges;
    unordered_map<int, vector<int>> children;
    for (int i = 0; i < tasks; i++) {
      verticesWithIncomingEdges[i] = 0;
      children[i] = {};
    }
    for (int i = 0; i < prerequisites.size(); i++) {
      int parent = prerequisites[i][0];
      int child = prerequisites[i][1];
      verticesWithIncomingEdges[child]++;
      children[parent].push_back(child);
    }
    queue<int> sources;
    for (const auto& [key, value] : verticesWithIncomingEdges) {
      if (value == 0) sources.push(key);
    }
    while (!sources.empty()) {
      int currVertex = sources.front();
      sources.pop();
      vector<int> currChildren = children[currVertex];
      sorted.push_back(currVertex);
      for (const auto& child : currChildren) {
        verticesWithIncomingEdges[child]--;
        if (verticesWithIncomingEdges[child] == 0) sources.push(child);
      }
    }
    return sorted.size() == tasks;
  }
};

int main(int argc, char* argv[]) {
  bool result = TaskScheduling::isSchedulingPossible(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}});
  cout << "Tasks execution possible: " << result << endl;

  result = TaskScheduling::isSchedulingPossible(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2},
                             vector<int>{2, 0}});
  cout << "Tasks execution possible: " << result << endl;

  result = TaskScheduling::isSchedulingPossible(
      6, vector<vector<int>>{vector<int>{2, 5}, vector<int>{0, 5},
                             vector<int>{0, 4}, vector<int>{1, 4},
                             vector<int>{3, 2}, vector<int>{1, 3}});
  cout << "Tasks execution possible: " << result << endl;
}
