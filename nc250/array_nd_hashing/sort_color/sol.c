// time complexity -> O(N log N)
// space complexity -> O(1)

#define SWAP(a, b) do {     \
  __typeof__(a) tmp = (a);  \
  (a) = (b);                \
  (b) = tmp;                \
} while(0);


int partition_id(int *arr, int low, int high) {
  int pivot = arr[low];
  int i = low;        // start i from the next element after the pivot
  int j = high;

  while (i < j) {
    while (arr[i] <= pivot && i <= high - 1) i++;
    while (arr[j] > pivot && j >= low + 1) j--;

    // if j has not crossed the i, then swap
    if (i < j) {
      SWAP(arr[i], arr[j]);
    }
  }
  SWAP(arr[low], arr[j]);
  return j;
}


void quick_sort(int *arr, int low, int high) {
  if (low < high) {
    int pid = partition_id(arr, low, high);

    quick_sort(arr, low, pid - 1);
    quick_sort(arr, pid + 1, high);
  }
}




// PROBLEM //
void sortColors(int* nums, int numsSize) {
  quick_sort(nums, 0, numsSize - 1);
}