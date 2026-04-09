// problem - https://leetcode.com/problems/plus-one/

// time complexity - O(N)
// space complexity - O(1) ; O(N) if all 9s
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
  for (int i = digitsSize - 1; i >= 0; i--) {
    if (digits[i] == 9)
      digits[i] = 0;
    else {
      // increment the digit and return it
      digits[i]++;

      *returnSize = digitsSize;
      return digits;
    }
  }

  // in case all numbers are 9, then the else block will not execute
  // and we reach here. Allocate a new array with one more element to 
  // update the carry.
  int *res = malloc(sizeof(int) * (digitsSize + 1));

  // copy the memory of digits array into res starting from index 1
  memcpy(res+1, digits, digitsSize * sizeof(int));

  res[0] = 1;  // update the carry at the first index

  *returnSize = digitsSize + 1;
  return res;
}