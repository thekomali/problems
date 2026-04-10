// problem - 

// time complexity  - O(max(m, n))
// space complexity - O(max(m, n))

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 typedef struct {
  int top;
  int arr[];
 } Stack;

 Stack* sinit() {
  Stack *s = malloc(sizeof(Stack) + (sizeof(int) * 100));

  s->top = -1;
  return s;
 }

bool isempty(Stack *s) {
  return (s->top == -1);
}

bool isfull(Stack *s) {
  return (s->top == 100);
}

void push(Stack *s, int val) {
  if (isfull(s)) return;

  s->arr[++s->top] = val;
}

int pop(Stack *s) {
  if (isempty(s)) return -1;

  return s->arr[s->top--];
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  if (!l1) return l2;
  if (!l2) return l1;

  // initialize two stacks for pushing values from both the linked list
  Stack *sl1 = sinit();
  Stack *sl2 = sinit();

  // first populate the stack while going though linked list
  while (l1) { push(sl1, l1->val); l1 = l1->next; }
  while (l2) { push(sl2, l2->val); l2 = l2->next; }

  int sum = 0, carry = 0;
  struct ListNode *head = NULL;

  // do addition by popping values from stack and prepent the linked list
  while (!isempty(sl1) || !isempty(sl2) || carry) {
    sum = 0;

    sum += !isempty(sl1) ? pop(sl1) : 0;
    sum += !isempty(sl2) ? pop(sl2) : 0;
    sum += carry;

    carry = sum / 10;

    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = sum % 10;
    node->next = NULL;

    node->next = head;    // prepend the new node before the head, instead of post-append
    head = node;    
  }

  return head;    
}