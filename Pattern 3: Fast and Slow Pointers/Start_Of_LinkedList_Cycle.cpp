using namespace std;

#include <iostream>

// PROBLEM: Given the head of a Singly LinkedList that contains a cycle, write a function to find the starting node of the cycle.

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class LinkedListCycleStart {
 public:
  static ListNode *findCycleStart(ListNode *head) {

    if (head == nullptr)
      return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    ListNode* node = detectCycle(slow, fast);
    if (node == nullptr)
      return nullptr;

    // distance from ptr1 to start of cycle and ptr2 to start is
    // the same so return when they point to same node
    ListNode* ptr1 = head;
    ListNode* ptr2 = node;
    while (ptr2 != ptr1) {  
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }

    return ptr1;
  }

private:
  // detect node in cycle where slow and fast meet
  static ListNode* detectCycle(ListNode* slow, ListNode* fast) {
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;

      if (slow == fast)
        return slow;
    }

    return nullptr;
  }

  // Time: O(N) to process nodes in LL in linear time
  // Space: O(1) just using pointers
};