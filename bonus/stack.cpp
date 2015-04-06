#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

template <typename T>

class Stack {

private:
  vector<T> queue;

public:

  Stack(int size) {
    queue.reserve(size);
  }

  void push(T item) {
    queue.push_back(item);
  }

  void pushFront(T item) {
    queue.insert(queue.begin(), item);
  }

  void pop() {
    queue.pop_back();
  }

  void popFront() {
    queue.erase(queue.begin());
  }

  T operator[] (int index) const {
    return queue[index];
  }

  int size() const {
    return queue.size();
  }

};

template <typename T> ostream& operator<< (ostream& os, const Stack<T> &stack) {
  for (int i = 0; i < stack.size(); i++) {
    os << stack[i] << " ";
  }
  return os;
}

int main () {
  Stack<char> queue_char(3);
  queue_char.push('b');
  queue_char.push('c');
  queue_char.pushFront('a');
  cout << "First element of queue_char is " << queue_char[0] << endl;
  cout << "The whole queue_char is " << queue_char << endl;

  Stack<int> queue_int(1);
  queue_int.push(3);
  queue_int.push(1);
  queue_int.push(2);
  queue_int.popFront();
  queue_int.pop();
  queue_int.pushFront(0);


  cout << "The whole queue_int is " << queue_int << endl;
  return 0;
}
