# problem - https://leetcode.com/problems/plus-one/

# time complexity - O(N)
# space complexity - O(1)

class Solution:
  def plusOne(self, digits: List[int]) -> List[int]:
    # iterate the digits list backwards
    for i in range(len(digits) - 1, -1, -1):
      if digits[i] == 9:
        digits[i] = 0
      else:
        digits[i] += 1
        return digits
    
    # if we reach here, then all the digits are equal to 9
    # which means, we need to add a new element to denote carry
    return [1] + digits