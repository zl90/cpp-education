using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

class FrequencySort {
 public:
  struct valueCompare {
    char operator()(const std::pair<char, int> &a,
                    const std::pair<char, int> &b) const {
      return a.second < b.second;
    }
  };

  static string sortCharacterByFrequency(const string &str) {
    string sortedString = "";
    priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare>
        maxHeap;
    unordered_map<char, int> frequencies;
    for (const auto &character : str) {
      frequencies[character]++;
    }
    for (const auto &frequency : frequencies) {
      maxHeap.push(frequency);
    }
    while (!maxHeap.empty()) {
      for (int j = 0; j < maxHeap.top().second; j++) {
        sortedString += maxHeap.top().first;
      }
      maxHeap.pop();
    }
    return sortedString;
  }
};

int main(int argc, char *argv[]) {
  string result = FrequencySort::sortCharacterByFrequency("Programming");
  cout << "Here is the given string after sorting characters by frequency: "
       << result << endl;

  result = FrequencySort::sortCharacterByFrequency("abcbab");
  cout << "Here is the given string after sorting characters by frequency: "
       << result << endl;
}
