//Design your implementation of the circular queue. The circular queue is a line
//ar data structure in which the operations are performed based on FIFO (First In 
//First Out) principle and the last position is connected back to the first positi
//on to make a circle. It is also called "Ring Buffer". 
//
// One of the benefits of the circular queue is that we can make use of the spac
//es in front of the queue. In a normal queue, once the queue becomes full, we can
//not insert the next element even if there is a space in front of the queue. But 
//using the circular queue, we can use the space to store new values. 
//
// Implementation the MyCircularQueue class: 
//
// 
// MyCircularQueue(k) Initializes the object with the size of the queue to be k.
// 
// int Front() Gets the front item from the queue. If the queue is empty, return
// -1. 
// int Rear() Gets the last item from the queue. If the queue is empty, return -
//1. 
// boolean enQueue(int value) Inserts an element into the circular queue. Return
// true if the operation is successful. 
// boolean deQueue() Deletes an element from the circular queue. Return true if 
//the operation is successful. 
// boolean isEmpty() Checks whether the circular queue is empty or not. 
// boolean isFull() Checks whether the circular queue is full or not.
// 
//
// 
// Example 1: 
//
// 
//Input
//["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFul
//l", "deQueue", "enQueue", "Rear"]
//[[3], [1], [2], [3], [4], [], [], [], [4], []]
//Output
//[null, true, true, true, false, 3, true, true, true, 4]
//
//Explanation
//MyCircularQueue myCircularQueue = new MyCircularQueue(3);
//myCircularQueue.enQueue(1); // return True
//myCircularQueue.enQueue(2); // return True
//myCircularQueue.enQueue(3); // return True
//myCircularQueue.enQueue(4); // return False
//myCircularQueue.Rear();     // return 3
//myCircularQueue.isFull();   // return True
//myCircularQueue.deQueue();  // return True
//myCircularQueue.enQueue(4); // return True
//myCircularQueue.Rear();     // return 4
// 
//
// 
// Constraints: 
//
// 
// 1 <= k <= 1000 
// 0 <= value <= 1000 
// At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, an
//d isFull.
// 
//
// 
//Follow up: Could you solve the problem without using the built-in queue? Relat
//ed Topics Design Queue 
// 👍 821 👎 117


#include <vector>
#include <memory>
#include <cassert>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MyCircularQueue {
 private:
  vector<int> vec_;
  int curr_size_{0}, front_idx_{-1}, rear_idx_{-1};
 public:
  explicit MyCircularQueue(int k) : vec_(k) {
  }

  bool enQueue(int value) {
    if (isFull()) {
      return false;
    }
    if (isEmpty()) {
      front_idx_ = 0;
      rear_idx_ = 0;
    } else if (rear_idx_ == vec_.size() - 1) {
      rear_idx_ = 0;
    } else {
      rear_idx_++;
    }
    vec_[rear_idx_] = value;
    curr_size_++;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    if (front_idx_ == vec_.size() - 1) {
      front_idx_ = 0;
    } else {
      front_idx_++;
    }
    curr_size_--;
    if (isEmpty()) {
      front_idx_ = -1;
      rear_idx_ = -1;
    }
    return true;
  }

  int Front() {
    if (front_idx_ != -1) {
      return vec_[front_idx_];
    }
    return front_idx_;
  }

  int Rear() {
    if (rear_idx_ != -1) {
      return vec_[rear_idx_];
    }
    return rear_idx_;
  }

  [[nodiscard]] bool isEmpty() const {
    return curr_size_ == 0;
  }

  [[nodiscard]] bool isFull() const {
    return curr_size_ == vec_.size();
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
//leetcode submit region end(Prohibit modification and deletion)

/*
 * dequeue and enqueue simply move the front_idx_ and rear_idx_ as appropriate. The only special case is if front_idx_
 * is at the end in dequeue. Then, it must wrap around to the front. Likewise, if rear_idx_ is at the end in enqueue,
 * we also must wrap to the front. The rest of the code follows trivially: curr_size_ keeps track of the current size
 * of the circular queue.. Additionally, if there is only one element left in the vector, we must set front_idx_ and
 * rear_idx_ to -1.
 */


int main() {
  auto queue = make_unique<MyCircularQueue>(3);
  assert(queue->enQueue(1)); // return True
  assert(queue->enQueue(2)); // return True
  assert(queue->enQueue(3)); // return True
  assert(!queue->enQueue(4)); // return False
  assert(queue->Rear() == 3); // return 3
  assert(queue->isFull()); // return True
  assert(queue->deQueue()); // return True
  assert(queue->enQueue(4)); // return True
  assert(queue->Front() == 2); // return 2
  assert(queue->Rear() == 4); // return 4
}