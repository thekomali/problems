// problem - https://leetcode.com/problems/merge-two-sorted-lists/

// time complexity  - O(N)
// space complexity - O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
  struct ListNode merged;            // node used to hold the head of merged linked list
  struct ListNode* tail = &merged;   // node reference used to form the merged linked list

  while (list1 && list2) {
    if (list1->val <= list2->val) {
      tail->next = list1;
      list1 = list1->next;
    }
    else {
      tail->next = list2;
      list2 = list2->next;
    }

    // end of every loop update the tail to the last node
    tail = tail->next;
  }

  // check for leftover nodes
  if (list1) tail->next = list1;
  else tail->next = list2;

  return merged.next;
}