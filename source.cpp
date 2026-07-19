#include <iostream>
#include <vector>
#include <string>
#include "header.h"

using namespace std;

void menu()
{
    cout << "\n\n========================================\n";
    cout << "     COURSE REGISTRATION SYSTEM\n";
    cout << "========================================\n\n";
    
    cout << "1. Register for a new course \n";
    cout << "2. See student details \n";
    cout << "3. Drop registered course \n";
    cout << "4. Exit \n\n";
}

string course::getcourseName() const 
{
    return courseName;   
}

string course::getcourseCode() const 
{
    return courseCode;   
}

void student::push(string cname, string code)
{
    Courses.push_back(course(cname, code));
}

string student::getName() const
{
    return name;
}

int student::getId() const
{
    return id;
}

int student::getCourseNo() const
{
    return Courses.size();
}

void student::courseDetails(int index)
{       
    cout << "Course Name: " << Courses[index].getcourseName() << endl;
    cout << "Course Code: " << Courses[index].getcourseCode() << endl;
}

void student::dropCourse(int index)
{
    Courses.erase(Courses.begin() + index);
}

int search(const vector<student>& s, int id)
{
    for(size_t i = 0; i < s.size(); i++)
    {
        if(s[i].getId() == id)
        {
            return static_cast<int>(i);
        }
    }
    
    return -1;
    
}