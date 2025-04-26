#pragma once
#include <iostream>
#include <string>
#include <vector>

// forward declaration
struct Patients;

template<typename T>
class HashMap {
  // Vector to store hash table entries
  std::vector<T*> hashmaparr;
  public:
    HashMap();
    static int getIntFromString(std::string);  
    T* get(std::string);
    // string is key, T is value
    void insert(std::string, T*);
    void remove(std::string);
};
