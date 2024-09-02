using namespace std;

#include <iostream>
#include <unordered_map>

class HappyNumber {
 public:
  static bool find(int num) {
    int a = num, b = getNext(num);
    while (a != b) {
      a = getNext(a);
      b = getNext(getNext(b));
    }
    return a == 1;
  }

 private:
  static int getNext(int num) {
    int sum = 0;
    while (num > 0) {
      sum += (num % 10) * (num % 10);
      num /= 10;
    }
    return sum;
  }
};

int main() {
  cout << HappyNumber::find(23) << endl;
  cout << HappyNumber::find(12) << endl;
  cout << HappyNumber::find(100) << endl;
  cout << HappyNumber::find(111) << endl;
  cout << HappyNumber::find(4) << endl;
  cout << HappyNumber::find(5) << endl;
}
