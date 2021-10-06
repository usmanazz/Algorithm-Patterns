using namespace std;

#include <iostream>

// PROBLEM: Given the head of a Singly LinkedList, write a method to return the middle node of the LinkedList.
// If the total number of nodes in the LinkedList is even, return the second middle node.

// EXAMPLE: Input: 1 -> 2 -> 3 -> 4 -> 5 -> null
//          Output: 3

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class MiddleOfLinkedList {
 public:
  static ListNode *findMiddle(ListNode *head) {
    if (head == nullptr)
      return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }

  // Time: O(N) n is number of nodes in list
  // Space: O(1) additional space
};