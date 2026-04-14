// problem - https://leetcode.com/problems/sign-of-the-product-of-an-array/

// time complexity - O(N)
// space complexity - O(1)

int arraySign(int* nums, int numsSize) {
  // XOR - flips the bit (0 to 1 or 1 to 0)
  // even no of negatives encounter, xor results in 0
  // odd no of negatives encounter, xor results in 1
  int neg_parity = 0;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == 0) return 0;

    if (nums[i] < 0) neg_parity ^= 1;
  }

  return neg_parity == 1 ? -1 : 1;   
}