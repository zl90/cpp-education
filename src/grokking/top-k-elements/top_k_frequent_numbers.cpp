#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TopKFrequentNumbers {
  struct valueCompare {
    char operator()(const std::pair<int, int> &a,
                    const std::pair<int, int> &b) const {
      return a.second > b.second;
    }
  };

 public:
  static std::vector<int> findTopKFrequentNumbers(const std::vector<int> &nums,
                                                  int k) {
    std::vector<int> topNumbers;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        valueCompare>
        heap;
    std::unordered_map<int, int> frequencies;
    for (const auto &num : nums) {
      frequencies[num]++;
    }
    for (const auto &frequency : frequencies) {
      if (heap.size() < std::min(k, (int)frequencies.size())) {
        heap.push(frequency);
      } else {
        if (frequency.second >= heap.top().second) {
          heap.pop();
          heap.push(frequency);
        }
      }
    }
    int heapSize = heap.size();
    for (int i = 0; i < heapSize; i++) {
      topNumbers.push_back(heap.top().first);
      heap.pop();
    }
    return topNumbers;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> result = TopKFrequentNumbers::findTopKFrequentNumbers(
      {1, 3, 5, 12, 11, 12, 11}, 2);
  std::cout << "Here are the K frequent numbers: ";
  for (auto num : result) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  result = TopKFrequentNumbers::findTopKFrequentNumbers({5, 12, 11, 3, 11}, 2);
  std::cout << "Here are the K frequent numbers: ";
  for (auto num : result) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
