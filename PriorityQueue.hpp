#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Hospital.hpp"

template<typename T>
class PriorityQueue {
  std::vector<T*> pqueue;
  public:
    PriorityQueue();
    bool empty();
    T front();
    T back();
    void enqueue(Patients*, int);
    void pop();
    int size();
};
