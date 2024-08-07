using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class MedianOfAStream {
 public:
  priority_queue<int> maxSmallest;
  priority_queue<int, vector<int>, greater<int>> minLargest;

  virtual void insertNum(int num) {
    if (maxSmallest.empty() || num <= maxSmallest.top()) {
      maxSmallest.push(num);
    } else {
      minLargest.push(num);
    }
    if (maxSmallest.size() > minLargest.size() + 1) {
      minLargest.push(maxSmallest.top());
      maxSmallest.pop();
    } else if (minLargest.size() > maxSmallest.size() + 1) {
      maxSmallest.push(minLargest.top());
      minLargest.pop();
    }
  }

  virtual double findMedian() {
    if (minLargest.empty()) return maxSmallest.top();
    if (maxSmallest.empty()) return minLargest.top();
    if (minLargest.size() == maxSmallest.size()) {
      return (minLargest.top() + maxSmallest.top()) / 2.0;
    } else if (minLargest.size() > maxSmallest.size()) {
      return minLargest.top();
    } else {
      return maxSmallest.top();
    }
  }
};

int main(int argc, char *argv[]) {
  MedianOfAStream medianOfAStream;
  medianOfAStream.insertNum(3);
  medianOfAStream.insertNum(1);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(5);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(4);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
}
