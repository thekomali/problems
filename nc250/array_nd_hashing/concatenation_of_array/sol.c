// time complexity  - O(N)
// space complexity - O(N)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
  int *ans = malloc(sizeof(int) * (numsSize * 2));
  if (!ans) return NULL;

  memcpy(ans, nums, numsSize * sizeof(int));            // copy first part
  memcpy(ans + numsSize, nums, numsSize * sizeof(int)); // copy second part

  *returnSize = numsSize * 2;
  return ans;    
}