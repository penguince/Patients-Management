#pragma once
#include<iostream>
#include<string>
#include "PriorityQueue.hpp"
#include "HashMap.hpp"


struct Patients {
  std::string FNAME;
  std::string LNAME;
  int PRIORITY;
};
struct OperationRoom {
  PriorityQueue<Patients>* patientsQueue;
};
class Hospital {
  
};
