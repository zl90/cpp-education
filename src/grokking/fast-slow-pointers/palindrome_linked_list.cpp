using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class PalindromicLinkedList {
 public:
  static bool isPalindrome(ListNode *head) {
    if (!head || !head->next) return true;

    ListNode *a = head, *b = head;
    while (b && b->next) {
      a = a->next;
      b = b->next->next;
    }
    // a is now the midpoint
    ListNode *head2 = reverse(a);
    a = head;
    b = head2;
    while (b) {
      if (a->value != b->value) {
        reverse(head2);
        return false;
      }
      a = a->next;
      b = b->next;
    }
    reverse(head2);
    return true;
  }

 private:
  static ListNode *reverse(ListNode *head) {
    ListNode *a = nullptr, *b = head, *c = head->next;
    while (c) {
      b->next = a;
      a = b;
      b = c;
      c = c->next;
    }
    b->next = a;
    return b;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(6);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(2);

  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head)
       << endl;

  head->next->next->next->next->next->next = new ListNode(2);

  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head)
       << endl;
}
