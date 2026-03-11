# time complexity -> O(N)
# space complexity -> O(N)

class Solution(object):
  def reverseString(self, s):
    s[:] = s[::-1]