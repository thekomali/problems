// problem - https://leetcode.com/problems/move-zeroes/

// time complexity - O(N)
// space complexity - O(1)
#define SWAP(a, b) do {      \
  __typeof__(a) _tmp = (a);  \
  (a) = (b);                 \
  (b) = (_tmp);              \
} while(0)                   


void moveZeroes(int* nums, int numsSize) {
  // l - for marking swap positons
  // when r at non-zero value, then swap it with l
  for (int l = 0, r = 0; r < numsSize; r++) {
    if (nums[r] != 0) {
      SWAP(nums[r], nums[l]);
      l++;
    }
  }
}