#include "PriorityQueue.hpp"

template<typename T>
PriorityQueue<T>::PriorityQueue() {
  this.pqueue = new std::vector<T*>();
}

template<typename T>
bool PriorityQueue<T>::empty() {
  return this.pqueue.empty();
}

template<typename T>
T PriorityQueue<T>::front() {
  if(this.empty()) {
    return nullptr;
  } 
  return this.pqueue[0];
}

template<typename T>
T PriorityQueue<T>::back() {
  if(this.empty()) {
    return nullptr;
  }
  return this.pqueue[this.pqueue.size()-1];
}

template<typename T>
void PriorityQueue<T>::enqueue(Patients* patient, int priority) {
  // we care about priority here
  if(this.empty()) {
    this.pqueue.push_back(patient);
    return;
  }
  // Make this into a binary search later
  for(int i = 0; i < this.pqueue.size(); i++) {
    if(this.pqueue[i].PRIORITY <= priority) {
      this.pqueue.insert(0,patient);
    }
  }
}


template<typename T>
void PriorityQueue<T>::pop() {
  if(!this.empty()) {
    this.pqueue.pop_back();
  }
}

template<typename T>
int PriorityQueue<T>::size() {
  return this.pqueue.size();
}

int main() {
  return 0;
}
