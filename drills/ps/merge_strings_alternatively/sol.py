# time complexity  - O(N + M)
# space complexity - O(N + M)

class Solution:
  def mergeAlternately(self, word1: str, word2: str) -> str:
    min_word = min(len(word1), len(word2))

    # merge alternately till the min size
    merged = [word1[i] + word2[i] for i in range(min_word)]
    
    # grab the leftovers and update merged
    merged += word1[min_word:] + word2[min_word:]

    return "".join(merged)