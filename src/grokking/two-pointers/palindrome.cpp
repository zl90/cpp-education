#include <iostream>
#include <string>
#include <vector>

bool is_palindrome(std::string input) {
  int left = 0;
  int right = input.size() - 1;
  while (left < right) {
    if (input[left++] != input[right--]) return false;
  }
  return true;
}

int main() {
  std::vector<std::string> test_cases{"abab", "aabbaa", "A", "ABa", "kaYak"};

  for (const auto& test_case : test_cases) {
    if (is_palindrome(test_case)) {
      std::cout << test_case << "\t\tis a palindrome\n";
    } else {
      std::cout << test_case << "\t\tis not a palindrome\n";
    }
  }
}