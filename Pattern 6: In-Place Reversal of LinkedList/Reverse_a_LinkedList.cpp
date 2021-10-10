using namespace std;

#include <iostream>

// PROBLEM: Given the head of a Singly LinkedList, reverse the LinkedList. Write a function to return the new head 
// of the reversed LinkedList.

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class ReverseLinkedList {
 public:
  static ListNode *reverse(ListNode *head) {
    // 2 -> 4 -> 6 -> null
    // prev -> null. cur->2 
    // 2 -> null
    // 4 -> 2 -> null
    // 6 -> 4 -> 2 -> null

    if (head == NULL)
      return NULL;

    ListNode* prev = NULL;
    ListNode* cur = head;
    while (cur != NULL) {
      ListNode* tempNext = cur->next;
      cur->next = prev;
      prev = cur;
      cur = tempNext;
    }

    return prev;
  }

  // Time: O(N) visit every node once
  // Space: O(1) just using pointers
};