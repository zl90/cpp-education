using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class MedianOfAStream {
 public:
  virtual void insertNum(int num) {
    if (maxLowest.empty()) {
      cout << "pushing " << num << " to maxLowest\n";
      maxLowest.push(num);
      return;
    }
    if (num < maxLowest.top()) {
      cout << "pushing " << num << " to maxLowest\n";
      maxLowest.push(num);
    } else {
      cout << "pushing " << num << " to minHighest\n";
      minHighest.push(num);
    }
    if (maxLowest.size() > minHighest.size() + 1) {
      int top = maxLowest.top();
      maxLowest.pop();
      minHighest.push(top);
    } else if (minHighest.size() > maxLowest.size() + 1) {
      int top = minHighest.top();
      minHighest.pop();
      maxLowest.push(top);
    }
  }

  virtual double findMedian() {
    if (maxLowest.empty()) return minHighest.top();
    if (minHighest.empty()) return maxLowest.top();
    if (maxLowest.size() == minHighest.size()) {
      return (maxLowest.top() + minHighest.top()) / 2.0;
    } else if (maxLowest.size() > minHighest.size()) {
      return maxLowest.top();
    } else {
      return minHighest.top();
    }
  }

 private:
  priority_queue<int> maxLowest;
  priority_queue<int, vector<int>, greater<int>> minHighest;
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
