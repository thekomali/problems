// problem - 

// time complexity  - O(N)
// space complexity - O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
  struct ListNode* curr = NULL;
  struct ListNode* prev = NULL;

  while (head) {
    curr = head;        // take a ref to current iteration node
    head = head->next;  // update to next node

    curr->next = prev;  // update curr node's next to previous node
    prev = curr;        // update previous node with curr iteration node
  }

  return prev;    
}