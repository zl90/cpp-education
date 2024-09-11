using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TopologicalSort {
 public:
  static vector<int> sort(int vertices, const vector<vector<int>>& edges) {
    if (edges.size() == 0) return {};
    vector<int> sorted;
    queue<int> sources;
    unordered_map<int, int> incomingEdges;
    unordered_map<int, vector<int>> children;
    for (int i = 0; i < vertices; i++) {
      incomingEdges[i] = 0;
      children[i] = {};
    }
    for (const auto& edge : edges) {
      const auto parent = edge[0];
      const auto child = edge[1];
      incomingEdges[child]++;
      children[parent].push_back(child);
    }
    for (const auto& [key, value] : incomingEdges) {
      if (value == 0) {
        sources.push(key);
      }
    }
    while (!sources.empty()) {
      int currVertex = sources.front();
      sources.pop();
      auto currChildren = children[currVertex];
      for (const auto& child : currChildren) {
        incomingEdges[child]--;
        if (incomingEdges[child] == 0) {
          sources.push(child);
        }
      }
      sorted.push_back(currVertex);
    }
    return sorted;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = TopologicalSort::sort(
      4, vector<vector<int>>{vector<int>{3, 2}, vector<int>{3, 0},
                             vector<int>{2, 0}, vector<int>{2, 1}});

  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TopologicalSort::sort(
      5, vector<vector<int>>{vector<int>{4, 2}, vector<int>{4, 3},
                             vector<int>{2, 0}, vector<int>{2, 1},
                             vector<int>{3, 1}});

  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
