// Source: https://usaco.org/index.php?page=viewproblem2&cpid=664

// The solution boils down to: what is the minimum letters needed to represent
// both words? Then you just do that for the rest of the lines, and add them all
// up.

#include <bits/stdc++.h>
using namespace std;

int main() {
  map<char, int> max_letters{
      {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0},
      {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0},
      {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0}, {'u', 0},
      {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0},
  };

  int N;
  cin >> N;

  vector<pair<string, string>> words{N};
  for (int n = 0; n < N; n++) {
    cin >> words[n].first >> words[n].second;
  };

  for (const auto& word_pair : words) {
    string word1 = word_pair.first;
    string word2 = word_pair.second;

    map<char, int> freq1{
        {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0},
        {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0},
        {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0}, {'u', 0},
        {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0},
    };
    map<char, int> freq2{
        {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0},
        {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0},
        {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0}, {'u', 0},
        {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0},
    };

    for (const auto& character : word1) {
      freq1[character] += 1;
    }
    for (const auto& character : word2) {
      freq2[character] += 1;
    }

    for (const auto& [key, value] : max_letters) {
      max_letters[key] += max(freq1[key], freq2[key]);
    }
  }

  for (const auto& [key, value] : max_letters) {
    cout << value << '\n';
  }
}
