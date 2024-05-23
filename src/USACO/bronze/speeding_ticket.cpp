// https://usaco.org/index.php?page=viewproblem2&cpid=568

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("shell.in", "r", stdin);

	int result = 0;

	vector<int> N = {};
	vector<int> M = {};

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int miles, speed_limit;
		cin >> miles >> speed_limit;

		for (int j = 0; j < miles; j++) {
			N.emplace_back(speed_limit);
		}
	}

	for (int i = 0; i < m; i++) {
		int miles, speed;
		cin >> miles >> speed;

		for (int j = 0; j < miles; j++) {
			M.emplace_back(speed);
		}
	}

	for (size_t i = 0; i < N.size(); i++) {
		int speed_difference = M[i] - N[i];

		result = max(speed_difference, result);
	}

	freopen("shell.out", "w", stdout);

	cout << result;
}
