// problem - 

// time complexity - O(N log(N))
// space complexity - O(1)

// Comparison function for ascending order
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


int largestPerimeter(int* nums, int numsSize) {
  int a, b, c;

  // sort the array
  qsort(nums, numsSize, sizeof(int), compare);

  // scan from largest elements towards smallest
  for (int i = numsSize-1; i >= 2; i--) {
    c = nums[i];
    b = nums[i - 1];
    a = nums[i - 2];

    if (a + b > c) {
      // found a triangle, so the curr perimeter is the largest
      return a + b + c;
    } 
  }

  return 0;  // no valid triangles found   
}