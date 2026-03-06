// time complexity  -> O(N)
// space complexity -> O(1)

int removeElement(int* nums, int numsSize, int val) {
  int lptr = 0, rptr = 0, swp = 0;

  while (rptr < numsSize) {
    if (nums[rptr] != val) {
      swp = nums[rptr];
      nums[rptr] = nums[lptr];
      nums[lptr] = swp;

      lptr++;
    }

    rptr++;
  }

  return lptr;
    
}