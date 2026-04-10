# problem - https://leetcode.com/problems/merge-two-sorted-lists/

# time complexity  - O(N)
# space complexity - O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
    merged = ListNode()    # points to the merged linked list
    tail = merged          # just a reference to merged, act as tail for appending nodes

    while (list1 and list2):
      if list1.val <= list2.val:
        tail.next = list1
        list1 = list1.next
      else:
        tail.next = list2
        list2 = list2.next

      # end of every loop update the tail to the last node
      tail = tail.next

    # check for leftover nodes in each linked list
    if list1: tail.next = list1
    else: tail.next = list2

    return merged.next