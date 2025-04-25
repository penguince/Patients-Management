#pragma once
#include<iostream>
#include<string>
#include "PriorityQueue.hpp"
#include "HashMap.hpp"


struct Patients {
  std::string name;
  int PRIORITY;
  bool admitted;
  int OR;
};
struct OperationRoom {
  PriorityQueue<Patients>* patientsQueue;
  int size() {
    return patientsQueue->size();
  }
};
class Hospital {
  HashMap<Patients> patientRecords;
  std::vector<OperationRoom> ORs;
  public:
    Hospital();
    void admitPatient(std::string , int);
    void attendPatient(int);
};
