# time complexity  - O(N)
# space complexity - O(k)  ; k - no of unique characters

from collections import Counter

class Solution:
  def isAnagram(self, s: str, t: str) -> bool:
    return Counter(s) == Counter(t)