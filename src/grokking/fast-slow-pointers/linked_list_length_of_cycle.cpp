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

class LinkedListCycleLength {
 public:
  static int findCycleLength(ListNode *head) {
    ListNode *a = head, *b = head;
    while (true) {
      a = a->next;
      b = b->next->next;
      if (a == b) {  // cycle found
        // pause a
        int length = 1;
        b = b->next;
        while (a != b) {
          length++;
          b = b->next;
        }
        return length;
      }
    }
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next =
      head->next->next;  // creating a cycle

  cout << "Length of Cycle: " << LinkedListCycleLength::findCycleLength(head)
       << endl;

  head->next->next->next->next->next->next = head->next->next->next;

  cout << "Length of Cycle: " << LinkedListCycleLength::findCycleLength(head)
       << endl;
  return 0;
}
