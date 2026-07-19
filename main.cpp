#include <iostream>
#include <vector>
#include <string>
#include "header.h"

using namespace std;

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