using namespace std;

#include <iostream>
#include <unordered_map>

class HappyNumber {
 public:
  static bool find(int num) {
    int a = calculateNext(num);
    int b = calculateNext(a);

    while (a != b) {
      a = calculateNext(a);
      b = calculateNext(b);
      b = calculateNext(b);
    }

    return a == 1;
  };

 private:
  static int calculateNext(int x) {
    int sum = 0;
    while (x > 0) {
      int y = x % 10;
      x = x / 10;
      sum += y * y;
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
