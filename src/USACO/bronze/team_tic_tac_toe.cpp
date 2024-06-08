// https://usaco.org/index.php?page=viewproblem2&cpid=831

#include <bits/stdc++.h>
using namespace std;

int main() {
  int num_single_winners = 0;
  int num_double_winners = 0;

  // Read input
  vector<vector<char>> grid(3, vector<char>(3));
  for (auto& row : grid) {
    string input;
    cin >> input;

    row[0] = input[0];
    row[1] = input[1];
    row[2] = input[2];
  }

  // Check all rows
  for (auto row : grid) {
    unordered_map<char, int> cow_initials;

    for (auto column : row) {
      cow_initials[column]++;
    }

    for (auto initial : cow_initials) {
      if (initial.second == 3) {
        num_single_winners++;
        break;
      }

      if (initial.second == 2) {
        num_double_winners++;
        break;
      }
    }
  }

  // Check all columns
  for (int col = 0; col < 3; col++) {
    unordered_map<char, int> cow_initials;

    for (int row = 0; row < 3; row++) {
      auto character = grid[row][col];
      cow_initials[character]++;
    }

    for (auto initial : cow_initials) {
      if (initial.second == 3) {
        num_single_winners++;
        break;
      }

      if (initial.second == 2) {
        num_double_winners++;
        break;
      }
    }
  }

  // Check diagonals
  unordered_map<char, int> cow_initials;
  cow_initials[grid[0][0]]++;
  cow_initials[grid[1][1]]++;
  cow_initials[grid[2][2]]++;

  for (auto initial : cow_initials) {
    if (initial.second == 3) {
      num_single_winners++;
      break;
    }

    if (initial.second == 2) {
      num_double_winners++;
      break;
    }
  }

  cow_initials.clear();
  cow_initials[grid[0][2]]++;
  cow_initials[grid[1][1]]++;
  cow_initials[grid[2][0]]++;

  for (auto initial : cow_initials) {
    if (initial.second == 3) {
      num_single_winners++;
      break;
    }

    if (initial.second == 2) {
      num_double_winners++;
      break;
    }
  }

  cout << num_single_winners << '\n' << num_double_winners;
}
