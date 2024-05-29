// Source: https://usaco.org/index.php?page=viewproblem2&cpid=917

#include <bits/stdc++.h>
using namespace std;

struct SensorReading {
  SensorReading() = default;
  SensorReading(int u, int l, string t) : upper(u), lower(l), type(t) {}

  SensorReading& operator=(const SensorReading& that) {
    if (this != &that) {
      upper = that.upper;
      lower = that.lower;
      type = that.type;
    }

    return *this;
  }

  int upper;
  int lower;
  string type;
};

int main() {
  /*
  4
  on 1 1
  none 10 14
  none 11 15
  off 2 3

  // The solution is to find the final speed first.
  // Iterate through each one, ignore all ramps until you find the first hwy
  segment,
  // Then keep cumulative count of upper and lower bound. Initialize the upper
  and lower bounds with the first hwy segment values.
  // If you encounter a hwy segment, find the max of the lower bounds, find the
  min of the upper bounds.
  // If you encounter an on ramp, subtract the upper bound of the ramp from the
  lower bound, subtract the lower bound of the ramp from the upper bound.
  // If you encounter an off ramp, add the lower bound of the ramp from the
  lower bound, add the upper bound of the ramp from the upper bound.
  // When finished iterating, you will be left with the final speed range.

  // Repeat the process above, in the opposite direction to find the initial
  speed range.
  */

  int N;
  cin >> N;

  int initial_upper_speed = 0;
  int initial_lower_speed = 0;
  int final_upper_speed = 0;
  int final_lower_speed = 0;

  vector<SensorReading> readings{N};

  for (int n = 0; n < N; n++) {
    int upper, lower;
    string type;
    cin >> type >> lower >> upper;
    readings[n] = SensorReading(upper, lower, type);
  }

  bool has_found_hwy_segment = false;
  for (const auto& reading : readings) {
    if (reading.type == "none") {
      if (!has_found_hwy_segment) {
        has_found_hwy_segment = true;
        final_lower_speed = reading.lower;
        final_upper_speed = reading.upper;
      } else {
        final_lower_speed = max(final_lower_speed, reading.lower);
        final_upper_speed = min(final_upper_speed, reading.upper);
      }
    } else if (has_found_hwy_segment) {
      if (reading.type == "on") {
        final_lower_speed += reading.upper;
        final_upper_speed += reading.lower;
      } else if (reading.type == "off") {
        final_lower_speed -= reading.upper;
        final_upper_speed -= reading.lower;
      }
    }
  }

  has_found_hwy_segment = false;
  for (int i = readings.size() - 1; i >= 0; i--) {
    const auto& reading = readings[i];
    if (reading.type == "none") {
      if (!has_found_hwy_segment) {
        has_found_hwy_segment = true;
        initial_lower_speed = reading.lower;
        initial_upper_speed = reading.upper;
      } else {
        initial_lower_speed = max(initial_lower_speed, reading.lower);
        initial_upper_speed = min(initial_upper_speed, reading.upper);
      }
    } else if (has_found_hwy_segment) {
      if (reading.type == "on") {
        initial_lower_speed -= reading.upper;
        initial_upper_speed -= reading.lower;
      } else if (reading.type == "off") {
        initial_lower_speed += reading.upper;
        initial_upper_speed += reading.lower;
      }
    }
  }

  cout << initial_lower_speed << " " << initial_upper_speed << '\n';
  cout << final_lower_speed << " " << final_upper_speed;
}
