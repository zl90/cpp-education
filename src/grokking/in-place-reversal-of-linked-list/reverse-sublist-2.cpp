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
  static ListNode* reverse2(ListNode* head, int n) {
    if (n <= 3) return head;
    bool isOdd = n % 2 != 0;
    ListNode *a = head, *b = head, *oldHead = head, *oldMiddle = head,
             *newMiddle = head, *newHead = head;
    while (b && b->next) {
      a = a->next;
      b = b->next->next;
    }
    oldMiddle = a;
    if (isOdd) a = a->next;
    newMiddle = reverse(a, n / 2);
    if (isOdd) oldMiddle->next = newMiddle;
    newHead = reverse(head, n / 2);
    if (isOdd) {
      oldHead->next = oldMiddle;
    } else {
      oldHead->next = newMiddle;
    }
    return newHead;
  }

 private:
  static ListNode* reverse(ListNode* head, int n) {
    ListNode *a = nullptr, *b = head;
    while (n > 0) {
      ListNode* c = b->next;
      b->next = a;
      a = b;
      b = c;
      n--;
    }
    return a;
  }
};

int main(int argc, char* argv[]) {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode* result = ReverseSubList::reverse2(head, 5);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
  cout << "\n";
}