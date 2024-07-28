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

class InsertInterval {
 public:
  static vector<Interval> insert(const vector<Interval> &intervals,
                                 Interval newInterval) {
    if (intervals.size() == 0) {
      return {newInterval};
    }

    vector<Interval> mergedIntervals;

    bool hasMerged = false;
    for (const auto &interval : intervals) {
      if (newInterval.start < interval.end &&
          newInterval.end > interval.start) {
        newInterval.start = min(interval.start, newInterval.start);
        newInterval.end = max(interval.end, newInterval.end);
        hasMerged = true;
      } else {
        if (hasMerged) {
          mergedIntervals.push_back(newInterval);
          hasMerged = false;
        }
        mergedIntervals.push_back(interval);
      }
    }

    if (hasMerged) {
      mergedIntervals.push_back(newInterval);
    }

    return mergedIntervals;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {5, 7}, {8, 12}};
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {4, 6})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {4, 10})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{2, 3}, {5, 7}};
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {1, 4})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  return 0;
}
