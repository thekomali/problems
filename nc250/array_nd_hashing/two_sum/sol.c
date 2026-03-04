// time complexity  - O(N log N) ; due to sorting
// space complexity - O(N)

typedef struct {
  int val;
  int id;
} node_t;

int comp(const void *a, const void *b) {
  return ((node_t *)a)->val - ((node_t *)b)->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  // allocate array of node_t
  node_t *snums = malloc(sizeof(node_t) * numsSize);

  // populate struct to compact the value and it's associated index
  for (int i = 0; i < numsSize; i++) {
    snums[i].val = nums[i];
    snums[i].id = i;
  }


  // sort the array
  qsort(snums, numsSize, sizeof(node_t), comp);

  int lptr = 0, rptr = numsSize - 1, sum = 0;
  while (lptr < rptr) {
    sum = snums[lptr].val + snums[rptr].val;

    if (sum == target) {
      // allocate memory for answer
      int *ans = malloc(2 * sizeof(int));
      *returnSize = 2;

      ans[0] = snums[lptr].id;
      ans[1] = snums[rptr].id;
      return ans;
    }
    
    if (sum > target) rptr--;
    else lptr++;
  }

  // if we reach here, no pair is present that sums equals target
  *returnSize = 0;
  free(snums);
  return NULL;    
}