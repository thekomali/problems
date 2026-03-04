# time complexity  - O(N)
# space complexity - O(N)

class Solution:
  def twoSum(self, nums: List[int], target: int) -> List[int]:
    seen = {}

    for i, a in enumerate(nums):
      if (b := target - a) in seen:
        return [seen[b], i]

      seen[a] = i
        