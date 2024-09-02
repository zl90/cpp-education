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

class LinkedListCycleStart {
 public:
  static ListNode *findCycleStart(ListNode *head) {
    ListNode *a = head, *b = head;
    int length = 1;
    while (true) {
      a = a->next;
      b = b->next->next;
      if (a == b) {
        b = b->next;
        while (a != b) {
          b = b->next;
          length++;
        }
        break;
      }
    }
    a = head;
    b = head;
    for (int i = 0; i < length; i++) {
      b = b->next;
    }
    while (b != a) {
      a = a->next;
      b = b->next;
    }
    return a;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList cycle start: "
       << LinkedListCycleStart::findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList cycle start: "
       << LinkedListCycleStart::findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head;
  cout << "LinkedList cycle start: "
       << LinkedListCycleStart::findCycleStart(head)->value << endl;
}
