#include <iostream>
#include <vector>
#include <string>
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

class course
{
    private:
    
    string courseName;
    string courseCode;
    
    public:
    
    course(string name, string code) : courseName(name), courseCode(code) {}

    string getcourseName() const
    {
        return courseName;
    }

    string getcourseCode() const
    {
        return courseCode;
    }
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
    
    void push(string cname, string code)
    {
        Courses.push_back(course(cname, code));
    }

    string getName() const
    {
        return name;
    }

    int getId() const
    {
        return id;
    }

    int getCourseNo() const
    {
        return Courses.size();
    }

    void courseDetails(int index)
    {       
        cout << "Course Name: " << Courses[index].getcourseName() << endl;
        cout << "Course Code: " << Courses[index].getcourseCode() << endl;
    }

    void dropCourse(int index)
    {
        Courses.erase(Courses.begin() + index);
    }
    
};

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

int main()
{
    int choice, id;
    string n, cname, code;

    vector<student> System;
    
    while(true)
    {
        
    menu();
    
    while (true)
    {
        cout << "Enter: ";
        cin >> choice;
        
        if (choice >= 1 && choice <= 4)
        {
            break;
        }
        
        cout << "Invalid input. Enter a valid choice number\n";
    }
    
    
    switch(choice)
    {
        case 1:
        
        cout << "Enter Course Name: ";
        getline(cin >> ws, cname);
           
        cout << "Enter Course Code: ";
        cin >> code;
        
        cout << "Enter Student ID: ";
        cin >> id;
        
        if(!(System.empty()))
        {
            int idx = search(System, id);
            
            if(idx > -1)
            {
                System[idx].push(cname, code);
            }
            else
            {
                cout << "Enter Student Name: ";
                cin >> n;
                
                System.push_back(student(n, id, cname, code));
            }
        }
        else
        {
            cout << "Enter Student Name: ";
            getline(cin >> ws, n);
                
            System.push_back(student(n, id, cname, code));   
        }
        
        break;
        
        case 2:
        
        if(!(System.empty()))
        {
            
            cout << "Enter Student ID: ";
            cin >> id;
        
            int idx = search(System, id);
            
            if(idx > -1)
            {
                cout << "\n==============================\n";
                cout << "         STUDENT DETAILS\n";
                cout << "==============================\n\n";
                
                cout << "Student Name: " << System[idx].getName() << endl;
                cout << "Student ID: " << System[idx].getId() << endl;
                
                if(System[idx].getCourseNo() != 0)
                {
                    for(int i = 0; i < System[idx].getCourseNo(); i++)
                    {
                        cout << "\nCourse Number " << i + 1 << endl;
                        cout << "------------------" << endl << endl;
                    
                     System[idx].courseDetails(i);
                    }
                }
                else
                {
                    cout << "No courses have been registered for.";
                }
                
                
            }
            else
            {
                cout << endl << "Student does not exist on this system" << endl;
            }
        }
        else
        {
            cout << endl << "There is no student currently registered." << endl; 
        }

        break;

        case 3:

        cout << "Enter Student ID: ";
        cin >> id;
        
        if(!(System.empty()))
        {
            int idx = search(System, id);
            
            if(idx > -1)
            {
                cout << "\n==============================\n";
                cout << "         COURSE DETAILS\n";
                cout << "================================\n\n";
                
                for(int i = 0; i < System[idx].getCourseNo(); i++)
                {
                    cout << "Course Number " << i + 1 << endl;
                    cout << "------------------" << endl << endl;
                    
                    System[idx].courseDetails(i);
                }

                while (true)
                {
                    cout << "\n Choose the course number ";
                    cin >> choice;
                    
                    if (choice >= 1 && choice <= System[idx].getCourseNo())
                    {
                        choice--;
                        break;
                    }
                    
                    cout << "\nInvalid input. Enter a valid choice number\n";
                }

                System[idx].dropCourse(choice);

                cout << "\nCourse has been dropped";
            }
            else
            {
                cout << endl << "Student does not exist on this system" << endl;
            }
        }
        else
        {
             cout << endl << "There is no student currently registered." << endl; 
        }
            
        break;

            case 4:

            exit(0);
        }
 
    }
   
}