# time complexity  - O(N)
# space complexity - O(1)

class Solution:
  def removeElement(self, nums: List[int], val: int) -> int:
    lptr = 0

    for rptr in range(len(nums)):
      if nums[rptr] != val:
        nums[lptr] = nums[rptr]
        lptr += 1
    
    return lptr
        