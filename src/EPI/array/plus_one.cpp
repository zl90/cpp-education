class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    bool carry = true;
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (carry) {
        if (digits[i] == 9) {
          digits[i] = 0;
        } else {
          digits[i]++;
          carry = false;
        }
      }
    }
    if (carry) {
      digits.push_back(0);
      digits[0] = 1;
    }
    return digits;
  }
};