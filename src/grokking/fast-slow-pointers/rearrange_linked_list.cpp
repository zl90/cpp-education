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

class RearrangeList {
 public:
  static void reorder(ListNode *head) {
    // handle small/empty lists
    if (!head || !head->next || !head->next->next) {
      return;
    }

    // find the midpoint
    ListNode *a = head, *b = head;
    while (b && b->next) {
      a = a->next;
      b = b->next->next;
    }

    // a is now the midpoint
    ListNode *head2 = reverse(a);

    // interweave
    a = head, b = head2;
    while (a && b && a != b) {
      ListNode *c = b->next;
      b->next = a->next;
      if (b->next == b) {
        b->next = nullptr;
        break;
      }
      a->next = b;
      b = c;
      a = a->next->next;
    }
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
  head->next->next->next = new ListNode(8);
  head->next->next->next->next = new ListNode(10);

  RearrangeList::reorder(head);

  while (head != nullptr) {
    cout << head->value << " ";
    head = head->next;
  }

  return 0;
}
