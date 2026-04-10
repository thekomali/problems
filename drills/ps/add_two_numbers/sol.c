// problem - 

/** WAY 01: USING A INPUT LINKED LIST TO STORE THE ADDITION RESULTS */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 // time complexity - O(max(N, M))
// space complecity - O(1)
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  if (!l1) return l2;
  if (!l2) return l1;

  struct ListNode* res = l1;     // using one input list to store addition result
  struct ListNode* tail = NULL;  // track the tail node of linked list
  int carry = 0, sum = 0, digit = 0;

  while (l1 || l2) {
    sum = 0;

    sum += l1 ? l1->val : 0;
    sum += l2 ? l2->val : 0;
    sum += carry;

    digit = sum % 10;
    carry = sum / 10;

    if (l1) {
      l1->val = digit;

      tail = l1;        // make a note of last node
      l1 = l1->next;    // update l1 to next node

      if (l2) l2 = l2->next;
    }
    else {
      // l1 linked list chain has exhausted, so 
      // using nodes in l2 to store the additon results
      l2->val = digit;

      tail->next = l2;   // update the original l1 list with node from l2
      tail = tail->next; // update tail to last node
      l2 = l2->next;
    }
  }


  if (carry) {
    // if we carry, then create a new node
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = carry;
    node->next = NULL;

    tail->next = node;
  }

  return res;    
}



/** WAY 02: CREATE A NEW LINKED LIST FOR ADDITION RESULTS */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 // time complexity  - O(max(N, M))
// space complecity  - O(max(N, M))
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  if (!l1) return l2;
  if (!l2) return l1;

  // instead of creating two references - one for continuing the chain
  // another for refering to the head, use the below way to make the code cleaner
  struct ListNode dummy = {0, NULL};
  struct ListNode *res  = &dummy; 

  int carry = 0, sum = 0;

  while (l1 || l2 || carry) {
    sum = 0;

    sum += l1 ? l1->val : 0;
    sum += l2 ? l2->val : 0;
    sum += carry;    

    // create new node to add the added value
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val  = sum % 10;
    node->next = NULL;

    // attach new node to the res linked list
    res->next = node;
    res = res->next;

    // update the pointers to continue the loop
    carry = sum / 10;
    if (l1) l1 = l1->next;
    if (l2) l2 = l2->next;
  }

  return dummy.next;
}