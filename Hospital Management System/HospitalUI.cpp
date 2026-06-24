#include <iostream>
#include <vector>

#include "HospitalUI.h"

using namespace std;

void HospitalUI::displayMenu()
{
    cout << "\n===== Hospital Management System =====\n";

    cout << "1. Add Patient\n";
    cout << "2. Remove Patient\n";
    cout << "3. Add Doctor\n";
    cout << "4. Assign Patient To Doctor\n";
    cout << "5. Cancel Appointment\n";
    cout << "6. View All Patients\n";
    cout << "7. View All Doctors\n";
    cout << "8. View Doctor Patients\n";
    cout << "9. Exit\n";
}

void HospitalUI::addPatientUI()
{
    string name;
    int age;
    string gender;

    cout << "Enter Patient Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter Gender: ";
    getline(cin, gender);

    string id =
        controller.addPatient(
            name,
            age,
            gender);

    cout << "\nPatient Added Successfully.\n";

    cout << "Generated Patient ID: "
        << id << endl;
}

void HospitalUI::removePatientUI()
{
    string patientID;

    cout << "Enter Patient ID: ";
    getline(cin, patientID);

    if (controller.removePatient(
        patientID))
    {
        cout << "Patient Removed Successfully.\n";
    }
    else
    {
        cout << "Patient Not Found.\n";
    }
}

void HospitalUI::addDoctorUI()
{
    string name;
    string specialization;

    cout << "Enter Doctor Name: ";
    getline(cin, name);

    cout << "Enter Specialization: ";
    getline(cin, specialization);

    string id =
        controller.addDoctor(
            name,
            specialization);

    cout << "\nDoctor Added Successfully.\n";

    cout << "Generated Doctor ID: "
        << id << endl;
}

void HospitalUI::assignPatientUI()
{
    string patientID;
    string doctorID;

    cout << "Enter Patient ID: ";
    getline(cin, patientID);

    cout << "Enter Doctor ID: ";
    getline(cin, doctorID);

    if (controller.assignPatientToDoctor(
        patientID,
        doctorID))
    {
        cout << "Appointment Created Successfully.\n";
    }
    else
    {
        cout << "Patient or Doctor Not Found.\n";
    }
}

void HospitalUI::cancelAppointmentUI()
{
    string doctorID;

    cout << "Enter Doctor ID: ";
    getline(cin, doctorID);

    vector<Patient> patients =
        controller.getDoctorPatients(
            doctorID);

    if (patients.empty())
    {
        cout << "No Patients Found.\n";
        return;
    }

    cout << "\nDoctor Patients:\n";

    for (int i = 0;
        i < patients.size();
        i++)
    {
        cout << i + 1
            << ". "
            << patients[i].getName()
            << endl;
    }

    int choice;

    cout << "Choose Patient Number: ";
    cin >> choice;
    cin.ignore();

    if (choice < 1 ||
        choice > patients.size())
    {
        cout << "Invalid Choice.\n";
        return;
    }

    string patientID =
        patients[choice - 1]
        .getID();

    if (controller.cancelAppointment(
        patientID,
        doctorID))
    {
        cout << "Appointment Cancelled Successfully.\n";
    }
    else
    {
        cout << "Operation Failed.\n";
    }
}

void HospitalUI::viewAllPatientsUI()
{
    vector<Patient> patients =
        controller.getAllPatients();

    if (patients.empty())
    {
        cout << "No Patients Found.\n";
        return;
    }

    cout << "\n===== Patients =====\n";

    for (int i = 0;
        i < patients.size();
        i++)
    {
        cout << "\nPatient ID: "
            << patients[i].getID()
            << endl;

        cout << "Name: "
            << patients[i].getName()
            << endl;

        cout << "Age: "
            << patients[i].getAge()
            << endl;

        cout << "Gender: "
            << patients[i].getGender()
            << endl;
    }
}

void HospitalUI::viewAllDoctorsUI()
{
    vector<Doctor> doctors =
        controller.getAllDoctors();

    if (doctors.empty())
    {
        cout << "No Doctors Found.\n";
        return;
    }

    cout << "\n===== Doctors =====\n";

    for (int i = 0;
        i < doctors.size();
        i++)
    {
        cout << "\nDoctor ID: "
            << doctors[i].getID()
            << endl;

        cout << "Name: "
            << doctors[i].getName()
            << endl;

        cout << "Specialization: "
            << doctors[i]
            .getSpecialization()
            << endl;
    }
}

void HospitalUI::viewDoctorPatientsUI()
{
    string doctorID;

    cout << "Enter Doctor ID: ";
    getline(cin, doctorID);

    vector<Patient> patients =
        controller.getDoctorPatients(
            doctorID);

    if (patients.empty())
    {
        cout << "No Patients Found.\n";
        return;
    }

    cout << "\n===== Doctor Patients =====\n";

    for (int i = 0;
        i < patients.size();
        i++)
    {
        cout << "\nPatient ID: "
            << patients[i].getID()
            << endl;

        cout << "Name: "
            << patients[i].getName()
            << endl;
    }
}

void HospitalUI::run()
{
    int choice;

    do
    {
        displayMenu();

        cout << "\nEnter Choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            addPatientUI();
            break;

        case 2:
            removePatientUI();
            break;

        case 3:
            addDoctorUI();
            break;

        case 4:
            assignPatientUI();
            break;

        case 5:
            cancelAppointmentUI();
            break;

        case 6:
            viewAllPatientsUI();
            break;

        case 7:
            viewAllDoctorsUI();
            break;

        case 8:
            viewDoctorPatientsUI();
            break;

        case 9:
            cout << "Goodbye.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 9);
}