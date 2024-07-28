using namespace std;

#include <iostream>
#include <vector>

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class IntervalsIntersection {
 public:
  static vector<Interval> merge(const vector<Interval> &arr1,
                                const vector<Interval> &arr2) {
    if (arr1.size() == 0) {
      return arr2;
    } else if (arr2.size() == 0) {
      return arr1;
    }
    vector<Interval> result;

    int a = 0, b = 0;
    while (a < arr1.size() && b < arr2.size()) {
      if (isIntersection(arr1[a], arr2[b])) {
        result.push_back(getIntersection(arr1[a], arr2[b]));
      }
      if (arr1[a].end == arr2[b].end) {
        a++, b++;
      } else if (arr1[a].end < arr2[b].end) {
        a++;
      } else {
        b++;
      }
    }
    return result;
  }

 private:
  static bool isIntersection(Interval a, Interval b) {
    return b.start <= a.end && b.end >= a.start;
  }

  static Interval getIntersection(Interval a, Interval b) {
    int start = max(a.start, b.start);
    int end = min(a.end, b.end);
    return {start, end};
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> input1 = {{1, 3}, {5, 6}, {7, 9}};
  vector<Interval> input2 = {{2, 3}, {5, 7}};
  vector<Interval> result = IntervalsIntersection::merge(input1, input2);

  cout << "Intervals Intersection: ";
  for (auto interval : result) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input1 = {{1, 3}, {5, 7}, {9, 12}};
  input2 = {{5, 10}};
  result = IntervalsIntersection::merge(input1, input2);

  cout << "Intervals Intersection: ";
  for (auto interval : result) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  return 0;
}
