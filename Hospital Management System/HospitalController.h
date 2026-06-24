#ifndef HOSPITALCONTROLLER_H
#define HOSPITALCONTROLLER_H

#include <vector>
#include <string>

#include "Patient.h"
#include "Doctor.h"

using namespace std;

class HospitalController
{
private:
    vector<Patient> patients;
    vector<Doctor> doctors;

    int findPatientByID(string patientID);

    int findDoctorByID(string doctorID);

public:
    string addPatient(string name,
        int age,
        string gender);

    bool removePatient(string patientID);

    string addDoctor(string name,
        string specialization);

    bool assignPatientToDoctor(
        string patientID,
        string doctorID);

    bool cancelAppointment(
        string patientID,
        string doctorID);

    vector<Patient> getDoctorPatients(
        string doctorID);

    vector<Patient> getAllPatients();

    vector<Doctor> getAllDoctors();
};

#endif