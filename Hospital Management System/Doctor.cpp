#include "Doctor.h"

int Doctor::nextID = 5000;

Doctor::Doctor(string name,
    string specialization)
{
    id = to_string(nextID++);

    this->name = name;
    this->specialization = specialization;
}

string Doctor::getID() const
{
    return id;
}

string Doctor::getName() const
{
    return name;
}

string Doctor::getSpecialization() const
{
    return specialization;
}

vector<string> Doctor::getPatientIDs() const
{
    return patientIDs;
}

void Doctor::addPatient(string patientID)
{
    patientIDs.push_back(patientID);
}

bool Doctor::removePatient(string patientID)
{
    for (int i = 0; i < patientIDs.size(); i++)
    {
        if (patientIDs[i] == patientID)
        {
            patientIDs.erase(
                patientIDs.begin() + i);

            return true;
        }
    }

    return false;
}