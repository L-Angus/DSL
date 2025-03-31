#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
  vector<vector<int>> result;
  if (nums.size() < 3)
    return result;

  // 先对数组排序
  std::sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 2; ++i) {
    // 跳过重复的第一个数
    if (i > 0 && nums[i] == nums[i - 1])
      continue;

    int left = i + 1;
    int right = nums.size() - 1;

    while (left < right) {
      int sum = nums[i] + nums[left] + nums[right];

      if (sum == 0) {
        result.push_back({nums[i], nums[left], nums[right]});
        // 跳过重复的第二个数和第三个数
        while (left < right && nums[left] == nums[left + 1])
          left++;
        while (left < right && nums[right] == nums[right - 1])
          right--;
        left++;
        right--;
      } else if (sum < 0) {
        left++;
      } else {
        right--;
      }
    }
  }

  return result;
}