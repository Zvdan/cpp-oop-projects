#include "HospitalController.h"

int HospitalController::findPatientByID(
    string patientID)
{
    for (int i = 0; i < patients.size(); i++)
    {
        if (patients[i].getID() == patientID)
        {
            return i;
        }
    }

    return -1;
}

int HospitalController::findDoctorByID(
    string doctorID)
{
    for (int i = 0; i < doctors.size(); i++)
    {
        if (doctors[i].getID() == doctorID)
        {
            return i;
        }
    }

    return -1;
}

string HospitalController::addPatient(
    string name,
    int age,
    string gender)
{
    Patient patient(name,
        age,
        gender);

    patients.push_back(patient);

    return patient.getID();
}

bool HospitalController::removePatient(
    string patientID)
{
    int patientIndex =
        findPatientByID(patientID);

    if (patientIndex == -1)
    {
        return false;
    }

    for (int i = 0; i < doctors.size(); i++)
    {
        doctors[i].removePatient(
            patientID);
    }

    patients.erase(
        patients.begin() +
        patientIndex);

    return true;
}

string HospitalController::addDoctor(
    string name,
    string specialization)
{
    Doctor doctor(name,
        specialization);

    doctors.push_back(doctor);

    return doctor.getID();
}

bool HospitalController::assignPatientToDoctor(
    string patientID,
    string doctorID)
{
    int patientIndex =
        findPatientByID(patientID);

    int doctorIndex =
        findDoctorByID(doctorID);

    if (patientIndex == -1 ||
        doctorIndex == -1)
    {
        return false;
    }

    doctors[doctorIndex]
        .addPatient(patientID);

    return true;
}

bool HospitalController::cancelAppointment(
    string patientID,
    string doctorID)
{
    int doctorIndex =
        findDoctorByID(doctorID);

    if (doctorIndex == -1)
    {
        return false;
    }

    return doctors[doctorIndex]
        .removePatient(patientID);
}

vector<Patient>
HospitalController::getDoctorPatients(
    string doctorID)
{
    vector<Patient> doctorPatients;

    int doctorIndex =
        findDoctorByID(doctorID);

    if (doctorIndex == -1)
    {
        return doctorPatients;
    }

    vector<string> patientIDs =
        doctors[doctorIndex]
        .getPatientIDs();

    for (int i = 0;
        i < patientIDs.size();
        i++)
    {
        int patientIndex =
            findPatientByID(
                patientIDs[i]);

        if (patientIndex != -1)
        {
            doctorPatients.push_back(
                patients[patientIndex]);
        }
    }

    return doctorPatients;
}

vector<Patient>
HospitalController::getAllPatients()
{
    return patients;
}

vector<Doctor>
HospitalController::getAllDoctors()
{
    return doctors;
}