# time complexity  - O(N)
# space complexity - O(1)

class Solution:
  def containsDuplicate(self, nums: List[int]) -> bool:
    seen = set()

    for num in nums:
      if num in seen: return True
      seen.add(num)
    
    return False



class Solution:
  def containsDuplicate(self, nums: List[int]) -> bool:
    return len(nums) != len(set(nums))