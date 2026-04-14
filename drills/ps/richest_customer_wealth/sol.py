# problem - https://leetcode.com/problems/richest-customer-wealth/

# time complexity - O(N)
# space complexity - O(1)
class Solution:
  def maximumWealth(self, accounts: List[List[int]]) -> int:
    return max(sum(account) for account in accounts)