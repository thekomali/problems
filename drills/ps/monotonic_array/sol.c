// problem - https://leetcode.com/problems/monotonic-array/

// time complexity - O(N)
// space complexity - O(1)
bool isMonotonic(int* nums, int numsSize) {
  if (numsSize <= 2) return true;

  bool not_increasing = true;
  bool not_decreasing = true;

  int prev = nums[0], curr = 0;

  for (int i = 1; i < numsSize; prev = curr, i++) {
    curr = nums[i];

    if (curr > prev) not_decreasing = false;
    if (curr < prev) not_increasing = false;

    // if both of them are false then the sequence is not monotonic
    // so just return false and no need to continue with other elements
    if (!not_decreasing && !not_increasing) return false;
  }

  return not_decreasing || not_increasing;    
}