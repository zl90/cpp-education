using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthLargestNumberInStream {
 private:
  int k;
  priority_queue<int, vector<int>, greater<int>> minHeap;

 public:
  KthLargestNumberInStream(const vector<int> &nums, int k) {
    this->k = k;
    for (int i = 0; i < nums.size(); i++) {
      add(nums[i]);
    }
  }

  virtual int add(int num) {
    if (minHeap.size() < k) {
      minHeap.push(num);
    } else if (num > minHeap.top()) {
      minHeap.pop();
      minHeap.push(num);
    }
    return minHeap.top();
  }
};

int main(int argc, char *argv[]) {
  KthLargestNumberInStream kthLargestNumber({3, 1, 5, 12, 2, 11}, 4);
  cout << "4th largest number is: " << kthLargestNumber.add(6) << endl;
  cout << "4th largest number is: " << kthLargestNumber.add(13) << endl;
  cout << "4th largest number is: " << kthLargestNumber.add(4) << endl;
}
