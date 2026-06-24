#include "StudentController.h"

int StudentController::findStudentByID(string id)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getID() == id)
        {
            return i;
        }
    }

    return -1;
}

string StudentController::addStudent(string name)
{
    Student student(name);

    students.push_back(student);

    return student.getID();
}

bool StudentController::deleteStudent(string id)
{
    int index = findStudentByID(id);

    if (index == -1)
    {
        return false;
    }

    students.erase(students.begin() + index);

    return true;
}

bool StudentController::addCourseToStudent(
    string id,
    string course)
{
    int index = findStudentByID(id);

    if (index == -1)
    {
        return false;
    }

    students[index].addCourse(course);

    return true;
}

vector<string> StudentController::getStudentCourses(
    string id)
{
    int index = findStudentByID(id);

    if (index == -1)
    {
        return {};
    }

    return students[index].getCourses();
}

bool StudentController::deleteCourseFromStudent(
    string id,
    int courseIndex)
{
    int index = findStudentByID(id);

    if (index == -1)
    {
        return false;
    }

    return students[index].deleteCourse(
        courseIndex);
}

vector<Student> StudentController::getAllStudents()
{
    return students;
}