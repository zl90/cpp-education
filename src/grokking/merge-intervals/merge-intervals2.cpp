#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MergeIntervals {
 public:
  static vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.size() == 0) return {};
    sort(
        intervals.begin(), intervals.end(),
        [](const Interval &a, const Interval &b) { return a.start < b.start; });
    int start = intervals[0].start, end = intervals[0].end;
    vector<Interval> mergedIntervals;
    for (const auto &interval : intervals) {
      if (interval.start < end) {
        end = max(interval.end, end);
      } else {
        mergedIntervals.push_back(Interval(start, end));
        start = interval.start;
        end = interval.end;
      }
    }
    mergedIntervals.push_back(Interval(start, end));
    return mergedIntervals;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{6, 7}, {2, 4}, {5, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{1, 4}, {2, 6}, {3, 5}, {6, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  return 0;
}
