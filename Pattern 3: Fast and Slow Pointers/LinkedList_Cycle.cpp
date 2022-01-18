using namespace std;

#include <iostream>

// PROBLEM: Given the head of a Singly LinkedList, write a function to determine if the LinkedList has a cycle in it or not.

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class LinkedListCycle {
 public:
  static bool hasCycle(ListNode *head) {
    if (head == nullptr)
      return false;

    // initial slow and fast ptrs
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      
      // check after incrementing ptrs since they both start off
      // pointing at head
      if (fast == slow)
        return true;
    }

    return false;
  }

  // Time : O(N) to process N nodes in linkedList even if there is a cycle
  // Space: O(1) 
};