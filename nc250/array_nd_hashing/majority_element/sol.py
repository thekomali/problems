# time complexity - O(N)
# space complexiyt - O(1)

class Solution:
  def majorityElement(self, nums: List[int]) -> int:
    maj_ele = None
    count = 0

    for num in nums:
      if count == 0:
        maj_ele = num
      
      count = count + 1 if maj_ele == num else count - 1
    
    return maj_ele