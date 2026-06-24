#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using namespace std;

class Student
{
private:
    static int nextID;
    string id;
    string name;
    vector<string> courses;

public:
    Student(string name);

    string getID() const;
    string getName() const;
    vector<string> getCourses() const;

    void addCourse(string course);

    bool deleteCourse(int index);
};

#endif