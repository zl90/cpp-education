using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TaskSchedulingOrder {
public:
  static vector<int> findOrder(int tasks,
                               const vector<vector<int>> &prerequisites) {
    vector<int> sorted;
    queue<int> sources;
    unordered_map<int, int> incoming;
    unordered_map<int, vector<int>> children;
    for (int i = 0; i < tasks; i++) {
      incoming[i] = 0;
      children[i] = {};
    }
    for (int i = 0; i < prerequisites.size(); i++) {
      const int parent = prerequisites[i][0];
      const int child = prerequisites[i][1];
      incoming[child]++;
      children[parent].push_back(child);
    }
    for (const auto &[key, value] : incoming) {
      if (value == 0)
        sources.push(key);
    }
    while (!sources.empty()) {
      const int currVertex = sources.front();
      sources.pop();
      sorted.push_back(currVertex);
      vector<int> currChildren = children[currVertex];
      for (const auto &child : currChildren) {
        incoming[child]--;
        if (incoming[child] == 0)
          sources.push(child);
      }
    }
    if (sorted.size() != tasks)
      return {}; // cyclic dependency found

    return sorted;
  }
};

int main(int argc, char *argv[]) {
  vector<int> result = TaskSchedulingOrder::findOrder(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}});

  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TaskSchedulingOrder::findOrder(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2},
                             vector<int>{2, 0}});

  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TaskSchedulingOrder::findOrder(
      6, vector<vector<int>>{vector<int>{2, 5}, vector<int>{0, 5},
                             vector<int>{0, 4}, vector<int>{1, 4},
                             vector<int>{3, 2}, vector<int>{1, 3}});

  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
