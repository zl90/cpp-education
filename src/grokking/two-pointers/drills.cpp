#include <iostream>
#include <vector>

int main() {
  std::vector<int> array(10);

  for (int i = 0; i < 10; i++) {
    array[i] = i;
  }

  bool is_palindrome = true;

  int left = 0, right = array.size() - 1;
  while (left < right) {
    if (array[left++] != array[right--]) {
      is_palindrome = false;
      break;
    }
  }

  if (is_palindrome) {
    std::cout << "true\n";
  } else {
    std::cout << "false\n";
  }
}