#ifndef HOSPITALUI_H
#define HOSPITALUI_H

#include "HospitalController.h"

class HospitalUI
{
private:
    HospitalController controller;

public:
    void displayMenu();

    void addPatientUI();

    void removePatientUI();

    void addDoctorUI();

    void assignPatientUI();

    void cancelAppointmentUI();

    void viewAllPatientsUI();

    void viewAllDoctorsUI();

    void viewDoctorPatientsUI();

    void run();
};

#endif