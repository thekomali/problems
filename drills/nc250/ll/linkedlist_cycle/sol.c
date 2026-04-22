// problem - https://leetcode.com/problems/linked-list-cycle/

// time complexity - O(N)
// space complexity - O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // Use Floyd's Cycle method to detect cycle in linked list
bool hasCycle(struct ListNode *head) {
  struct ListNode *slow = head, *fast = head;

  while (fast && fast->next) {
    // update the pointers
    slow = slow->next;
    fast = fast->next->next;

    // if two pointers match, then it's a cycle
    if (slow == fast) return true;
  }

  return false;    
}