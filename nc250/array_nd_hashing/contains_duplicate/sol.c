// time complexity  - O(N)
// space complexity - O(1)

// Comparator function for ascending order of integers
int compare_integers(const void *a, const void *b) {
  // Cast the void pointers to int pointers and dereference them
  int int_a = *((const int*)a);
  int int_b = *((const int*)b);

  if (int_a == int_b) return 0;
  else if (int_a < int_b) return -1;
  else return 1;
}



bool containsDuplicate(int* nums, int numsSize) {
  // sort the array
  qsort(nums, numsSize, sizeof(nums[0]), compare_integers);

  for (int i = 1; i < numsSize; i++) {
    if (nums[i - 1] == nums[i]) return true;
  }

  return false;
}