// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

struct Cow {
  Cow(int s, int t, int b) {
    start_time = s;
    end_time = t;
    num_buckets_used = b;
  }

  int start_time = 0;
  int end_time = 0;
  int num_buckets_used = 0;
};

int main() {
  int N;
  cin >> N;

  int max_time, min_time = 0;

  vector<Cow> cows{(size_t)N, {0, 0, 0}};

  for (int n = 0; n < N; n++) {
    int s, t, b;
    cin >> s >> t >> b;

    if (min_time == 0) {
      min_time = s;
    }

    min_time = min(min_time, s);
    max_time = max(max_time, t);

    cows[n] = Cow(s, t, b);
  }

  int max_buckets_used = 0;
  vector<vector<int>> timelines{(size_t)N};

  for (int n = 0; n < N; n++) {
    fill_n(back_inserter(timelines[n]), max_time - min_time, 0);
    fill(timelines[n].begin() + cows[n].start_time,
         timelines[n].begin() + cows[n].end_time, cows[n].num_buckets_used);
  }

  for (int i = 0; i < max_time - min_time; i++) {
    int current_buckets_used = 0;

    for (int n = 0; n < N; n++) {
      current_buckets_used += timelines[n][i];
    }

    max_buckets_used = max(max_buckets_used, current_buckets_used);
  }

  cout << max_buckets_used;
}
