//Given the head of a linked list, rotate the list to the right by k places. 
//
// 
// Example 1: 
//
// 
//Input: head = [1,2,3,4,5], k = 2
//Output: [4,5,1,2,3]
// 
//
// Example 2: 
//
// 
//Input: head = [0,1,2], k = 4
//Output: [2,0,1]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range [0, 500]. 
// -100 <= Node.val <= 100 
// 0 <= k <= 2 * 109 
// 
// Related Topics Linked List Two Pointers 
// 👍 2134 👎 1134

#include <cassert>
#include <vector>
#include <string>
#include <memory>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  static ListNode *rotateRight(ListNode *head, int k) {
    if (!head) {
      return head;
    }
    auto size = 1;
    auto last_node = head;
    for (; last_node->next; last_node = last_node->next) {
      size++;
    }
    k %= size;
    if (!k) {
      return head;
    }
    last_node->next = head;
    auto iterations = size - k;
    while (--iterations) {
      head = head->next;
    }
    auto prev_head = head;
    head = head->next;
    prev_head->next = nullptr;
    return head;
  }

/*
 * My approach is to first get the size of the list by looping through it (with O(N) time). Then, since k can be more
 * than the length of the list, I mod k with size. Then, if k is 0, nothing is to be done, so I return head.
 * Otherwise, I first set the last ListNode's next to head. Then, I calculate the head offset by subtracting k from the
 * head. Then, I shift the head by that amount. All that remains is to set the ListNode immediately before the head to
 * have a next of null.
 */

};
//leetcode submit region end(Prohibit modification and deletion)

ListNode *VectorToList(vector<int> v) {
  auto *head = new ListNode();
  auto ptr = head;
  for (int i = 0; i < v.size(); i++) {
    ptr->val = v[i];
    if (i != v.size() - 1) {
      ptr->next = new ListNode();
      ptr = ptr->next;
    }
  }
  return head;
}

string ListToString(ListNode *head) {
  auto first = true;
  string str;
  for (auto ptr = head; ptr; ptr = ptr->next) {
    if (!first) {
      str += "->";
    }
    str += to_string(ptr->val);
    first = false;
  }
  return str;
}

int main() {
  auto list = VectorToList({3, 6, 3, 1, 2});
  list = make_unique<Solution>()->rotateRight(list, 2);
  assert(ListToString(list) == "1->2->3->6->3");
  return 0;
}