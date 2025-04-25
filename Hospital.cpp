#include "Hospital.hpp"

Hospital::Hospital(): ORs(3) {;
  HashMap<Patients> patientRecords = HashMap<Patients>();
}


void Hospital::admitPatient(std::string name, int priority) {
  Patients* patient = this->patientRecords.get(name);
  if(patient != null && patient->admitted) {
    return;
  }
  patient = new Patients(name, priority, true);
  patientRecords.insert(name, patient); 
  int leastFilled = 0;
  for(int i = 1; i < ORs.size(); i++) {
    if(ORs[i].size() > ORs[leastFilled].size() && ORs[i].size() != 10) {
      leastFilled = i;
    }
  }
  if(ORs[leastFilled].size() != 10) {
    patient->OR = leastFilled;
    ORs[leastFilled].insert(patient->name, patient);
  }
}

void Hospital::attendPatient(int OR) {
  ORs[OR].patientsQueue->pop();
}
