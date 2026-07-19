#include <iostream>
#include <vector>
#include <string>

using namespace std;

void menu();

class course
{
    private:
    
    string courseName;
    string courseCode;
    
    public:
    
    course(string name, string code) : courseName(name), courseCode(code) {}

    string getcourseName() const;

    string getcourseCode() const;
};

class student
{
    private:
    
    string name;
    int id;
    vector<course> Courses;
    
    public:
    
    student(string n, int i, string cname, string code) : name(n), id(i) 
    {
        Courses.push_back(course(cname, code));
    }
    
    void push(string cname, string code);

    string getName() const;

    int getId() const;

    int getCourseNo() const;

    void courseDetails(int index);

    void dropCourse(int index);
    
};

int search(const vector<student>& s, int id);