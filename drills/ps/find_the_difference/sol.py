# problem - https://leetcode.com/problems/find-the-difference/
# time complexity  - O(M + N)
# space compelxity - O(1)

class Solution:
  def findTheDifference(self, s: str, t: str) -> str:
    diff = 0

    for ch in (s + t):
      diff ^= ord(ch)

    return chr(diff)