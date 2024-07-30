using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode* next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class ReverseSubList {
 public:
  static ListNode* reverse(ListNode* head, int p, int q) {
    if (p == q) {
      return head;
    }

    int iterations = q - p;
    ListNode *a = head, *b = head, *oldSublistHead = head;
    // select a:
    for (int i = 1; i < p; i++) {
      a = a->next;
    }
    oldSublistHead = a;
    b = a->next;

    for (int i = 0; i < iterations; i++) {
      ListNode* c = b->next;
      b->next = a;
      a = b;
      b = c;
    }

    oldSublistHead->next = b;
    if (p > 1) {
      ListNode* last = head;
      for (int i = 1; i < p - 1; i++) {
        last = last->next;
      }
      last->next = a;
    } else {
      head = a;
    }

    return head;
  }
};

int main(int argc, char* argv[]) {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode* result = ReverseSubList::reverse(head, 2, 4);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
  cout << "\n";
}