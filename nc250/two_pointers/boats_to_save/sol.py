# time complexity - O(N log N)  ; for sorting
# space complexity - O(1)

class Solution:
  def numRescueBoats(self, people: List[int], limit: int) -> int:
    # sort the people weight 
    people.sort()

    boats = 0
    l = 0
    r = len(people) - 1

    while l <= r:
      if people[l] + people[r] <= limit:
        l += 1
      
      boats += 1
      r -= 1

    return boats 