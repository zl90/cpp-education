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

    vector<Interval> mergedIntervals, insertedIntervals;

    // insertion
    bool isInserted = false;
    for (const auto &interval : intervals) {
      if (!isInserted && newInterval.start <= interval.start) {
        insertedIntervals.push_back(newInterval);
        isInserted = true;
      }
      insertedIntervals.push_back(interval);
    }

    // merge intervals
    int start = insertedIntervals[0].start, end = insertedIntervals[0].end;
    for (const auto &interval : insertedIntervals) {
      if (interval.start <= end) {
        // merge
        end = max(end, interval.end);
      } else {
        // start new interval
        mergedIntervals.push_back({start, end});
        start = interval.start;
        end = interval.end;
      }
    }

    mergedIntervals.push_back({start, end});

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
