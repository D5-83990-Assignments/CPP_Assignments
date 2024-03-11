/*
Create a namespace NStudent. Create the Student class(created as per assignment-1 Q3) inside
namespace. Test the functionalities.
*/

#include <iostream>
using namespace std;

namespace NStudent
{
    class Student
    {
        int rollNo;
        string name;
        int marks;

        public:
            void initStudent()
            {
                rollNo = 83990;
                name = "Abhishek";
                marks = 100;
            }

            void printStudentOnConsole()
            {
                cout<<endl<<"Student details"<<endl;
                cout<<"Roll No :- "<<rollNo<<endl;
                cout<<"Name :- "<<name<<endl;
                cout<<"Marks :- "<<marks<<endl<<endl;
            }

            void acceptStudentFromConsole()
            {
                cout<<"Enter the roll number :- ";
                cin>>rollNo;
                cout<<"Enter the name :- ";
                getline(cin>>ws,name);
                cout<<"Enter the marks :- ";
                cin>>marks;
            }

    };
}

using namespace NStudent;

int main()
{
    Student S1;
    S1.initStudent();
    int choice;
    do
    {
        cout<<endl;
        cout<<"1. Accept Data"<<endl;
        cout<<"2. Display Data"<<endl;
        cout<<"0. EXIT"<<endl;
        cout<<"Enter the choice : ";
        cin>>choice;

        switch(choice)
        {
            case 0:
                cout<<"Thank You"<<endl;
                break;

            case 1:
                S1.acceptStudentFromConsole();
                break;
            
            case 2:
                S1.printStudentOnConsole();
                break;

            default:
                cout<<"Invalid.......";
                break;
        }

    }while(choice != 0);

    return 0;
}