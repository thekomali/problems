# time complexity  - O(N * M^2); N - strs size, M - length of shortest string (2 - due to startwith - which does slicing)
# space complexity - O(1) 


# Horizontal scanning - we check the entire char of a string and move on to another
class Solution:
  def longestCommonPrefix(self, strs: List[str]) -> str:
    if len(strs) == 1: return strs[0]

    # consider the first word as common prefix
    common = strs[0]

    for s in strs[1:]:
      # remove one letter at a time in common to see if it matches
      # if match found, move to next string and check with common
      while not s.startswith(common):
        common = common[:-1]
        if not common:
          return ""
    
    return common