using namespace std;

#include <iostream>
#include <vector>

class NextLetter {
 public:
  static char searchNextLetter(const vector<char>& letters, char key) {
    if (letters[letters.size() - 1] <= key) return letters[0];
    int start = 0, end = letters.size() - 1;
    while (start <= end) {
      int middle = (start + end) / 2;
      if (letters[middle] > key) {
        end = middle - 1;
      } else {
        start = middle + 1;
      }
    }
    return letters[start];
  }
};

int main(int argc, char* argv[]) {
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'f')
       << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'b')
       << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'm')
       << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'h')
       << endl;
}
