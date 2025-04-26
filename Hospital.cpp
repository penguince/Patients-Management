#include "Hospital.hpp"

Hospital::Hospital() {
    // initialize the hospital with 3 operating rooms
    ORs.resize(3);
    for (int i = 0; i < 3; i++) {
        ORs[i].patientsQueue = new PriorityQueue<Patients>();
    }
    patientRecords = HashMap<Patients>();
}

void Hospital::admitPatient(std::string name, int priority) {
    Patients* patient = patientRecords.get(name);
    
    if (patient == nullptr) {
        // create a new patient
        patient = new Patients{name, priority, true, -1};
        patientRecords.insert(name, patient);
    } else if (!patient->admitted) {
        // update existing patient
        patient->admitted = true;
        patient->PRIORITY = priority;
        patient->OR = -1;
    } else {
        std::cout << "Patient " << name << " is already admitted." << std::endl;
        return;
    }
    
    // find the least filled operating room
    int leastFilled = 0;
    for (int i = 1; i < ORs.size(); i++) {
        if (ORs[i].size() < ORs[leastFilled].size()) {
            leastFilled = i;
        }
    }
    
    // assign patient to the operating room
    patient->OR = leastFilled;
    ORs[leastFilled].patientsQueue->enqueue(patient, priority);
    std::cout << "Patient " << name << " assigned to OR " << leastFilled << std::endl;
}

void Hospital::attendPatient(int OR) {
    if (OR < 0 || OR >= ORs.size()) {
        std::cout << "Invalid operating room number." << std::endl;
        return;
    }
    
    if (ORs[OR].size() == 0) {
        std::cout << "No patients waiting in OR " << OR << std::endl;
        return;
    }
    
    Patients* patient = ORs[OR].patientsQueue->front();
    std::cout << "Attending to patient " << patient->name << " in OR " << OR << std::endl;
    
    patient->admitted = false;
    patient->OR = -1;
    
    ORs[OR].patientsQueue->pop();
}

void Hospital::displayPatients() {
    std::cout << "\nCurrent patients in hospital:" << std::endl;
    for (int i = 0; i < ORs.size(); i++) {
        std::cout << "OR " << i << " - Patients: " << ORs[i].size() << std::endl;
    }
}