#ifndef PATIENT_H
#define PATIENT_H

#include <string>

using namespace std;

class Patient
{
private:
    static int nextID;

    string id;
    string name;
    int age;
    string gender;

public:
    Patient(string name,
        int age,
        string gender);

    string getID() const;

    string getName() const;

    int getAge() const;

    string getGender() const;
};

#endif