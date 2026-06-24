#include "Patient.h"

int Patient::nextID = 1000;

Patient::Patient(string name,
    int age,
    string gender)
{
    id = to_string(nextID++);

    this->name = name;
    this->age = age;
    this->gender = gender;
}

string Patient::getID() const
{
    return id;
}

string Patient::getName() const
{
    return name;
}

int Patient::getAge() const
{
    return age;
}

string Patient::getGender() const
{
    return gender;
}