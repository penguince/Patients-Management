#include "PriorityQueue.hpp"
#include "Hospital.hpp" // Include Hospital.hpp to get the full Patients definition

template<typename T>
PriorityQueue<T>::PriorityQueue() {
    pqueue = std::vector<T*>();
}

template<typename T>
bool PriorityQueue<T>::empty() {
    return pqueue.empty();
}

template<typename T>
T* PriorityQueue<T>::front() {
    if(empty()) {
        return nullptr;
    } 
    return pqueue[0];
}

template<typename T>
T* PriorityQueue<T>::back() {
    if(empty()) {
        return nullptr;
    }
    return pqueue[pqueue.size()-1];
}

template<typename T>
void PriorityQueue<T>::enqueue(T* patient, int priority) {
    if(empty()) {
        pqueue.push_back(patient);
        return;
    }
    
    // Insert based on priority 
    for(size_t i = 0; i < pqueue.size(); i++) {
        Patients* patientObj = static_cast<Patients*>(patient);
        Patients* queuePatient = static_cast<Patients*>(pqueue[i]);
        
        if(queuePatient->PRIORITY <= priority) {
            pqueue.insert(pqueue.begin() + i, patient);
            return;
        }
    }

    pqueue.push_back(patient);
}

template<typename T>
void PriorityQueue<T>::pop() {
    if(!empty()) {
        pqueue.erase(pqueue.begin()); // highest priority
    }
}

template<typename T>
int PriorityQueue<T>::size() {
    return pqueue.size();
}

template class PriorityQueue<Patients>;
