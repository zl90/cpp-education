using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class MaxFruitCountOf2Types {
 public:
  static int findLength(const vector<char> &arr) {
    if (arr.size() == 0) return 0;

    int longest = 0, K = 2, a = 0;
    unordered_map<char, int> chars{};

    for (int b = 0; b < arr.size(); b++) {
      if (chars[arr[b]]) {
        chars[arr[b]]++;
      } else {
        chars[arr[b]] = 1;
      }
      while (chars.size() > K) {
        chars[arr[a]]--;
        if (chars[arr[a]] == 0) chars.erase(arr[a]);
        a++;
      }
      longest = max(longest, b - a + 1);
    }

    return longest;
  }
};

int main() {
  vector<char> arr{'A', 'B', 'C', 'A', 'C'};

  int result = MaxFruitCountOf2Types::findLength(arr);

  std::cout << result << "\n";

  arr = {'A', 'B', 'C', 'B', 'B', 'C'};

  result = MaxFruitCountOf2Types::findLength(arr);

  std::cout << result << "\n";

  arr = {};

  result = MaxFruitCountOf2Types::findLength(arr);

  std::cout << result << "\n";

  arr = {
      'A',
      'A',
      'A',
      'A',
  };

  result = MaxFruitCountOf2Types::findLength(arr);

  std::cout << result << "\n";

  arr = {'A', 'B'};

  result = MaxFruitCountOf2Types::findLength(arr);

  std::cout << result << "\n";
}
