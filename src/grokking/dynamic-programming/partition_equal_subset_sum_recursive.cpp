class SolutionRecursive {
 public:
  bool canPartition(vector<int> &nums) { return dfs(0, nums, 0, 0); }

 private:
  bool dfs(int i, vector<int> nums, int leftSum, int rightSum) {
    int size = nums.size() - i;
    if (size <= 0) return leftSum == rightSum;
    return dfs(i + 1, nums, leftSum + nums[i], rightSum) ||
           dfs(i + 1, nums, leftSum, rightSum + nums[i]);
  }
};

class SolutionMemoized {
 public:
  bool canPartition(vector<int> &nums) {
    unordered_map<pair<int, int>, bool, pair_hash> cache;
    return dfs(0, nums, 0, 0, cache);
  }

 private:
  struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &pair) const {
      auto hash1 = hash<T1>()(pair.first);
      auto hash2 = hash<T2>()(pair.second);
      return hash1 ^ hash2;
    }
  };

  bool dfs(int i, vector<int> nums, int leftSum, int rightSum,
           unordered_map<pair<int, int>, bool, pair_hash> &cache) {
    int size = nums.size() - i;
    if (size <= 0) return leftSum == rightSum;
    if (cache.find({leftSum, rightSum}) != cache.end()) {
      return cache[{leftSum, rightSum}];
    } else if (cache.find({rightSum, leftSum}) != cache.end()) {
      return cache[{rightSum, leftSum}];
    }
    cache[{leftSum + nums[i], rightSum}] =
        dfs(i + 1, nums, leftSum + nums[i], rightSum, cache);
    cache[{leftSum, rightSum + nums[i]}] =
        dfs(i + 1, nums, leftSum, rightSum + nums[i], cache);
    return cache[{leftSum + nums[i], rightSum}] ||
           cache[{leftSum, rightSum + nums[i]}];
  }
};

class SolutionDP {
 public:
  bool canPartition(vector<int> &nums) {
    if (nums.size() <= 1) return false;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;
    vector<int> possibleSums = {0};
    for (const auto &num : nums) {
      int size = possibleSums.size();
      for (int i = 0; i < size; i++) {
        if (possibleSums[i] + num == sum / 2) return true;
        possibleSums.push_back(possibleSums[i] + num);
      }
    }
    return false;
  }
};