#include "Student.h"

int Student::nextID = 1000;

Student::Student(string name)
{
    id = to_string(nextID++);
    this->name = name;
}

string Student::getID() const
{
    return id;
}

string Student::getName() const
{
    return name;
}

vector<string> Student::getCourses() const
{
    return courses;
}

void Student::addCourse(string course)
{
    courses.push_back(course);
}

bool Student::deleteCourse(int index)
{
    if (index < 0 || index >= courses.size())
    {
        return false;
    }

    courses.erase(courses.begin() + index);

    return true;
}