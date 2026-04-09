# problem - 

# time complexity - O(M * N)
# space compexity - O(1)
class Solution:
  def strStr(self, haystack: str, needle: str) -> int:
    h = 0
    n = 0

    while h <= (len(haystack) - len(needle)):
      while (n < len(needle)) and (haystack[h] == needle[n]):
        n += 1
        h += 1

      if n == len(needle): return h - n

      h = h - n + 1
      n = 0

    return -1