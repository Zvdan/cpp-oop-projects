#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <vector>

using namespace std;

class Doctor
{
private:
    static int nextID;

    string id;
    string name;
    string specialization;

    vector<string> patientIDs;

public:
    Doctor(string name,
        string specialization);

    string getID() const;

    string getName() const;

    string getSpecialization() const;

    vector<string> getPatientIDs() const;

    void addPatient(string patientID);

    bool removePatient(string patientID);
};

#endif