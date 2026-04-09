# problem - https://leetcode.com/problems/valid-anagram/

# time complexity  - O(M * N)
# space compelxity - O(1)
class Solution:
  def isAnagram(self, s: str, t: str) -> bool:
    if len(s) != len(t): return False

    freq = {}
    
    for i, j in zip(s, t):
      freq[i] = freq.get(i, 0) + 1
      freq[j] = freq.get(j, 0) - 1

    return all(f == 0 for f in freq.values())