// problem - https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

// time complexity - O(N)
// space complexity - O(1)
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  struct ListNode res;
  res.next = head;

  struct ListNode *slow = &res, *fast = &res;

  // first move the fast pointer to n nodes apart from slow pointer
  for (int i = 0; i <= n; i++) {
    if (fast == NULL) return head;
  
    fast = fast->next;
  }

  // move both the pointers until fast reach the end
  // when that happens, slow will point to the previous node of 
  // node to be removed
  while (fast) {
    slow = slow->next;
    fast = fast->next;
  }

  // remove the element
  if (slow->next != NULL)
    slow->next = slow->next->next;

  return res.next;    
}
