using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class AlienDictionary {
 public:
  static string findOrder(const vector<string>& words) {
    string sortedOrder;
    unordered_map<char, int> uniqueLetters;
    vector<vector<char>> edges;
    for (const auto& word : words) {
      for (int i = 1; i < word.size(); i++) {
        if (word[i] != word[i - 1]) {
          bool isUniqueEdge = true;
          for (const auto& edge : edges) {
            if (edge[0] == word[i - 1] && edge[1] == word[i]) {
              isUniqueEdge = false;
            }
          }
          if (isUniqueEdge) {
            edges.push_back({word[i - 1], word[i]});
          }
        }
        uniqueLetters[word[i - 1]]++;
        uniqueLetters[word[i]]++;
      }
    }
    unordered_map<char, int> incoming;
    unordered_map<char, vector<char>> children;
    queue<char> sources;
    for (const auto& [key, value] : uniqueLetters) {
      incoming[key] = 0;
      children[key] = {};
    }
    for (int i = 0; i < edges.size(); i++) {
      const char parent = edges[i][0];
      const char child = edges[i][1];
      children[parent].push_back(child);
      incoming[child]++;
    }
    for (const auto& [key, value] : incoming) {
      if (value == 0) {
        sources.push(key);
      }
    }
    while (!sources.empty()) {
      const char currentVertex = sources.front();
      sources.pop();
      sortedOrder += currentVertex;
      vector<char> currentChildren = children[currentVertex];
      for (const auto& child : currentChildren) {
        incoming[child]--;
        if (incoming[child] == 0) {
          sources.push(child);
        }
      }
    }
    if (sortedOrder.size() != uniqueLetters.size()) {
      return "ERROR - cyclic dependency found";
    }
    return sortedOrder;
  }
};

int main(int argc, char* argv[]) {
  string result = AlienDictionary::findOrder(vector<string>{"ba", "bc", "ac"});
  cout << "Character order: " << result << endl;

  result = AlienDictionary::findOrder(vector<string>{"cab", "aaa", "aab"});
  cout << "Character order: " << result << endl;

  result = AlienDictionary::findOrder(
      vector<string>{"ywx", "wz", "xww", "xz", "zyy", "zwz"});
  cout << "Character order: " << result << endl;
}
