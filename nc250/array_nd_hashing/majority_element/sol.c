// time complexity - O(N)
// space complexity - O(1)

int majorityElement(int* nums, int numsSize) {
  int maj_ele = nums[0];
  int count = 1;

  for (int i = 1; i < numsSize; i++) {
    // if current element matches majority element, then
    // increment count else decrement count
    if (maj_ele == nums[i]) count++;
    else count--;

    // if count becomes is 0, then update majority element to curr element
    // and set the count to 1
    if (count == 0) {
      maj_ele = nums[i];
      count = 1;
    }
  }

  return maj_ele;    
}