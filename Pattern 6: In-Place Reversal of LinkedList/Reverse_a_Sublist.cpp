using namespace std;

#include <iostream>

// PROBLEM: Given the head of a LinkedList and two positions ‘p’ and ‘q’, reverse the LinkedList from position ‘p’ to ‘q’.

// EXAMPLE: 1-> 2 -> 3 -> 4 -> 5 -> null
//          1-> 4 -> 3 -> 2 -> 5 -> null

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class ReverseSubList {
 public:
  static ListNode *reverse(ListNode *head, int p, int q) {
    // 1 2 3 4 5 null
    // p=2, q=4, beforeP = 1, afterQ = 5, prev = afterQ, cur = p
    // 2->5->null
    // 3->2->5->null
    // 4->3->...
    // 1->4->3->...

    if (head == NULL)
      return NULL;

    // get node right before p
    ListNode* beforeP = head;
    int i = 1;
    while (i < p - 1) {
      beforeP = beforeP->next;
      i++;
    }

    ListNode* afterQ = head;
    int j = 1;
    while (j < q + 1) {
      afterQ = afterQ->next;
      j++;
    }

    ListNode* prev = afterQ;
    ListNode* cur = beforeP->next;
    while (cur != afterQ) {
      ListNode* tempNext = cur->next;
      cur->next = prev;
      prev = cur;
      cur = tempNext;
    }

    // link up nodes before p thru q nodes to rest of list
    beforeP->next = prev;

    return head;
  }

  // Time: O(N) to process N nodes in worst case
  // Space: O(1) just using pointers
};