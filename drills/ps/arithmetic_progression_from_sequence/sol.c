// problem - https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

// time complexity - O(N log(N))
// space complexity - O(1)

int compare_ints(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    if (ia < ib) return -1;
    if (ia > ib) return 1;
    return 0;
}



bool canMakeArithmeticProgression(int* arr, int arrSize) {
  if (arrSize <= 2) return true;

  // sort the array
  qsort(arr, arrSize, sizeof(int), compare_ints);

  // get the difference b/w the first two 
  int diff = arr[1] - arr[0];

  // check the difference matches the above diff
  for (int i = 2; i < arrSize; i++) {
    if (diff != (arr[i] - arr[i - 1])) return false;
  }

  return true;    
}