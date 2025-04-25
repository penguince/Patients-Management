#pragma once
#include<iostream>
#include<string>
#include "Hospital.hpp"

// Convert string to int value
// It will take every character, add 127 to it, then square itself, then add it to the final value
template<typename T>
class HashMap {
  // Should just be a bunch of priority queues 
  std::vector<T*> hashmaparr;
  public:
    HashMap();
    static int getIntFromString(std::string);  
    T get(std::string);
    // string is key, T is value
    void insert(std::string, T);
    void remove(std::string);
};
