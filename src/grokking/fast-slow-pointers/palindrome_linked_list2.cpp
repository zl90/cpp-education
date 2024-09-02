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
    if (!head) return false;
    if (!head->next) return true;
    ListNode *a = head, *b = head;
    while (b && b->next) {
      a = a->next;
      b = b->next->next;
    }
    ListNode *midPoint = a;
    ListNode *newHead = reverse(midPoint);
    a = head;
    b = newHead;
    while (a && b) {
      if (a->value != b->value) {
        reverse(newHead);
        return false;
      }
      a = a->next;
      b = b->next;
    }
    reverse(newHead);
    return true;
  }

 private:
  static ListNode *reverse(ListNode *head) {
    ListNode *a = nullptr, *b = head;
    while (b) {
      ListNode *c = b->next;
      b->next = a;
      a = b;
      b = c;
    }
    return a;
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
