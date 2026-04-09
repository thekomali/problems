# problem - https://leetcode.com/problems/repeated-substring-pattern

# time complexity  - O(N)
# space complexity - O(N)
class Solution:
  def repeatedSubstringPattern(self, s: str) -> bool:
    return s in (s * 2)[1:-1]
        