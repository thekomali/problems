# M - no of words
# N - avg characters in a word
# O(N) - for looping each word
# O(M) - for loopiing all words

# time complexity  - O(M * N)
# space complexity - O(N)



class Solution:
  def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    # dict to hold the freq tuple as key and corerspoinding words
    groups = {}   

    for word in strs:
      # list used to count each characters in words
      freq = [0] * 26

      # counting the character
      for ch in word:
        freq[ord(ch) - ord('a')] += 1
      
      # we use the counting list as key, for grouping words
      # that are anagrams (other way is to use the sorted string)
      key = tuple(freq)
      if key in groups:
        groups[key].append(word)
      else:
        groups[key] = [word]
    
    return list(groups.values())