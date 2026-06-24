#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H

#include "Student.h"
#include <vector>

class StudentController
{
private:
    vector<Student> students;

    int findStudentByID(string id);

public:
    string addStudent(string name);

    bool deleteStudent(string id);

    bool addCourseToStudent(string id,
        string course);

    vector<string> getStudentCourses(string id);

    bool deleteCourseFromStudent(string id,
        int courseIndex);

    vector<Student> getAllStudents();
};

#endif