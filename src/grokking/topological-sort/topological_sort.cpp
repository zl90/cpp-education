using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TopologicalSort {
 public:
  static vector<int> sort(int vertices, const vector<vector<int>>& edges) {
    vector<int> sorted;
    if (edges.size() <= 0) return sorted;
    unordered_map<int, int> incoming;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < vertices; i++) {
      incoming[i] = 0;
      graph[i] = {};
    }
    for (int i = 0; i < edges.size(); i++) {
      int parent = edges[i][0];
      int child = edges[i][1];
      graph[parent].push_back(child);
      incoming[child]++;
    }
    queue<int> sources;
    for (const auto& [key, value] : incoming) {
      if (value == 0) {
        sources.push(key);
      }
    }
    while (!sources.empty()) {
      int vertex = sources.front();
      sources.pop();
      sorted.push_back(vertex);
      vector<int> children = graph[vertex];
      for (const auto& child : children) {
        incoming[child]--;
        if (incoming[child] == 0) {
          sources.push(child);
        }
      }
    }
    if (sorted.size() != vertices) {
      return {};  // cycle found, topological sort not possible
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
