using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

class MergeKSortedLists {
 public:
  static ListNode *merge(const vector<ListNode *> &lists) {
    ListNode *resultHead = nullptr;
    priority_queue<ListNode *, vector<ListNode *>, CompareValue> minHeap;
    for (auto &head : lists) {
      if (head) {
        minHeap.push(head);
      }
    }
    resultHead = minHeap.top();
    ListNode *currNode = minHeap.top();
    minHeap.pop();
    if (currNode->next) {
      minHeap.push(currNode->next);
    }
    while (!minHeap.empty()) {
      currNode->next = minHeap.top();
      currNode = minHeap.top();
      minHeap.pop();
      if (currNode->next) {
        minHeap.push(currNode->next);
      }
    }
    return resultHead;
  }

 private:
  struct CompareValue {
    bool operator()(const ListNode *a, const ListNode *b) {
      return a->value > b->value;
    }
  };
};

int main(int argc, char *argv[]) {
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(6);
  l1->next->next = new ListNode(8);

  ListNode *l2 = new ListNode(3);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(7);

  ListNode *l3 = new ListNode(1);
  l3->next = new ListNode(3);
  l3->next->next = new ListNode(4);

  ListNode *result = MergeKSortedLists::merge(vector<ListNode *>{l1, l2, l3});

  cout << "Here are the elements from the merged list: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }

  cout << "\n";

  return 0;
}
