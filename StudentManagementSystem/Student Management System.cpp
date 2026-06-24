#include <iostream>
#include <string>
#include <vector>

#include "StudentController.h"

using namespace std;

int main()
{
    StudentController controller;

    int choice;

    do
    {
        cout << "\n===== Student Management System =====\n";

        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Add Course To Student\n";
        cout << "4. Delete Course From Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string name;

            cout << "Enter Student Name: ";
            getline(cin, name);

            string id =
                controller.addStudent(name);

            cout << "Student Added.\n";
            cout << "Generated ID: "
                << id << endl;

            break;
        }

        case 2:
        {
            string id;

            cout << "Enter Student ID: ";
            getline(cin, id);

            if (controller.deleteStudent(id))
            {
                cout << "Student Deleted.\n";
            }
            else
            {
                cout << "Student Not Found.\n";
            }

            break;
        }

        case 3:
        {
            string id;
            string course;

            cout << "Enter Student ID: ";
            getline(cin, id);

            cout << "Enter Course Name: ";
            getline(cin, course);

            if (controller.addCourseToStudent(
                id,
                course))
            {
                cout << "Course Added.\n";
            }
            else
            {
                cout << "Student Not Found.\n";
            }

            break;
        }

        case 4:
        {
            string id;

            cout << "Enter Student ID: ";
            getline(cin, id);

            vector<string> courses =
                controller.getStudentCourses(id);

            if (courses.empty())
            {
                cout << "No Courses Found "
                    "or Student Not Found.\n";
                break;
            }

            cout << "\nCourses:\n";

            for (int i = 0; i < courses.size(); i++)
            {
                cout << i + 1
                    << ". "
                    << courses[i]
                    << endl;
            }

            int courseChoice;

            cout << "Choose Course Number: ";
            cin >> courseChoice;
            cin.ignore();

            if (controller.deleteCourseFromStudent(
                id,
                courseChoice - 1))
            {
                cout << "Course Deleted.\n";
            }
            else
            {
                cout << "Invalid Choice.\n";
            }

            break;
        }

        case 5:
        {
            vector<Student> students =
                controller.getAllStudents();

            if (students.empty())
            {
                cout << "No Students Found.\n";
                break;
            }

            for (int i = 0; i < students.size(); i++)
            {
                cout << "\n-------------------\n";

                cout << "ID: "
                    << students[i].getID()
                    << endl;

                cout << "Name: "
                    << students[i].getName()
                    << endl;

                cout << "Courses: ";

                vector<string> courses =
                    students[i].getCourses();

                if (courses.empty())
                {
                    cout << "None";
                }
                else
                {
                    for (int j = 0;
                        j < courses.size();
                        j++)
                    {
                        cout << courses[j];

                        if (j != courses.size() - 1)
                        {
                            cout << ", ";
                        }
                    }
                }

                cout << endl;
            }

            break;
        }

        case 6:
            cout << "Goodbye.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 6);

    return 0;
}