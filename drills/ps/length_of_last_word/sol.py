# problem - https://leetcode.com/problems/length-of-last-word/

# time complexity  - O(N)
# space complexity - O(1)
class Solution:
  def lengthOfLastWord(self, s: str) -> int:
    last_part = s.rstrip().rsplit(" ", 1)
    return len(last_part[-1]) if last_part else 0
        