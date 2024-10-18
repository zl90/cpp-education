class SolutionBruteForce {
public:
  int countPrimes(int n) {
    if (n <= 2)
      return 0;
    int count = 1;
    for (int i = 3; i < n; i++) {
      if (isPrime(i))
        count++;
    }
    return count;
  }

  bool isPrime(int n) {
    if (n <= 1)
      return false;
    if (n == 2)
      return true;
    if (n % 2 == 0)
      return false;
    unordered_map<int, bool> primes;
    primes[2] = true;
    for (int i = 2; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (primes.find(i) != primes.end() || primes.find(j) != primes.end())
          continue;
        if (j * i == n) {
          return false;
        }
      }
    }
    return true;
  }
};