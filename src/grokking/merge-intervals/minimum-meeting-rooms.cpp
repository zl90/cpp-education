using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Meeting {
 public:
  int start = 0;
  int end = 0;

  Meeting(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MinimumMeetingRooms {
 public:
  static int findMinimumMeetingRooms(vector<Meeting>& meetings) {
    if (meetings.size() == 0) return 0;
    sort(meetings.begin(), meetings.end(),
         [](const auto& a, const auto& b) { return a.end < b.end; });
    priority_queue<int, vector<int>, greater<int>> meetingEndings;
    meetingEndings.push(meetings[0].end);
    size_t count = 1;
    for (int i = 1; i < meetings.size(); i++) {
      while (!meetingEndings.empty() &&
             meetings[i].start >= meetingEndings.top()) {
        meetingEndings.pop();
      }
      meetingEndings.push(meetings[i].end);
      count = max(count, meetingEndings.size());
    }
    return count;
  }
};

int main() {
  vector<Meeting> meetings = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  int result = MinimumMeetingRooms::findMinimumMeetingRooms(meetings);
  cout << "Minimum meeting rooms required: " << result << endl;

  meetings = {{1, 4}, {2, 5}, {7, 9}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(meetings);
  cout << "Minimum meeting rooms required: " << result << endl;

  meetings = {{6, 7}, {2, 4}, {8, 12}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(meetings);
  cout << "Minimum meeting rooms required: " << result << endl;

  meetings = {{1, 4}, {2, 3}, {3, 6}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(meetings);
  cout << "Minimum meeting rooms required: " << result << endl;

  meetings = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(meetings);
  cout << "Minimum meeting rooms required: " << result << endl;

  return 0;
}
