# M - no of words in list
# N - avg len of each word
# O(N log N) - for sorting each word
# O(M) - for looping through all words

# time compelxity  - O(M * N log N)
# space compelxity - O(N)

class Solution:
  def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    # sort the string, the string that has common word after 
    # sorting are anagrams
    sorted_words = {}

    for s in strs:
      arranged = "".join(sorted(s))

      if arranged in sorted_words:
        sorted_words[arranged].append(s)
      else:
        sorted_words[arranged] = [s]
      

    # create list of lists
    return list(sorted_words.values())
      
        