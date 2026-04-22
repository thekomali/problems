// problem - 


typedef struct {
  int top;
  struct ListNode **nodes;
} Stack;


Stack* init() {
  Stack *s = malloc(sizeof(Stack));

  s->top = -1;
  s->nodes = malloc(50000 * sizeof(struct ListNode *));
  return s;
}

void push(Stack *s, struct ListNode *node) {
  s->nodes[++s->top] = node;
}

struct ListNode* pop(Stack *s) {
  if (s->top == -1) return NULL;
  return s->nodes[s->top--];
}

struct ListNode* peek(Stack *s) {
  if (s->top == -1) return NULL;
  return s->nodes[s->top];
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// WAY 01: using stacks
// time complexity - O(N)
// space complexity - O(N)
void reorderList(struct ListNode* head) {
  // for single element linked list, just return
  if (head->next == NULL) return;

  Stack *s = init();

  // populate the stack with linkedlist (this reverses the linkedlist)
  struct ListNode *n = head;
  while (n) { push(s, n); n = n->next; }

  struct ListNode *left =  head;
  while (true) {
    struct ListNode *right = pop(s);

    // check if we reached the mid point
    // first condition for odd no of nodes and second for even number of nodes
    if (left == right || left->next == right) {
      right->next = NULL;
      break;
    }

    right->next = left->next;
    left->next = right;
    left = left->next->next;
  } 
}



// WAY 01: using two pointer approch (slow & fast pointer)
// time complexity - O(N)
// space complexity - O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
  struct ListNode *slow = head, *fast = head;

  // identify the mid point (slow points to end of first half)
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  struct ListNode *second = slow->next;       // isolate the second half
  slow->next = NULL;                          // terminate the first half
  
  // reverse the linked list slow -> tail
  struct ListNode *curr = second, *prev = NULL, *next = NULL;
  while (curr) {
    next = curr->next;

    curr->next = prev;
    prev = curr;

    curr = next;
  }

  // merge the linked list first & second half
  struct ListNode *f = head, *s = prev;
  while (s) {
    struct ListNode *fn = f->next;
    struct ListNode *sn = s->next;

    f->next = s;
    s->next = fn;

    s = sn;
    f = fn;
  }
}