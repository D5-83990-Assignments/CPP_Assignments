/*
Q2. Write a menu driven program for Student management.
In main(), create Array of Objects and provide facility for accept, print, search and sort.
For student accept name, gender, rollNumber and marks of three subjects from user and print name,
rollNumber, gender and percentage.
Provide global functions void sortRecords(Studuent[] arr) and int searchRe
*/

#include <iostream>
using namespace std;

class Student
{

private:
    string name;
    string gender;
    int rollNo;
    float marks[3];

public:
    Student()
    {
        name = "ABC";
        gender = "Male";
        rollNo = 0;
        marks[3] = {0};
    }

    Student(string name, string gender, int rollNo, float marks[3])
    {
        this->name = name;
        this->gender = gender;
        this->rollNo = rollNo;
        this->marks[3] = marks[3];
    }

    void acceptData()
    {
        cout << endl;
        cout << "Enter Name : ";
        getline(cin >> ws, name);
        cout << "Enter Gender [Male/Female]: ";
        cin >> gender;
        cout << "Enter RollNo. : ";
        cin >> rollNo;
        cout << "Enter '3' Subject Marks : " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Enter Subject " << i + 1 << " Marks : ";
            cin >> marks[i];
        }
        cout << endl;
    }

    void printData()
    {

        cout << "Name : " << name << endl;
        cout << "Gender [Male/Female] : " << gender << endl;
        cout << "RollNo. : " << rollNo << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Subject " << i + 1 << " Marks : " << marks[i] << endl;
        }
        cout << "Percentage(%) : " << ((marks[0] + marks[1] + marks[2]) / 300) * 100 << "%" << endl;
        cout << endl;
    }

    string getName()
    {
        return name;
    }

    string getGender()
    {
        return gender;
    }

    int getRollNo()
    {
        return rollNo;
    }

    float getMarks()
    {
        return marks[3];
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setGender(int gender)
    {
        this->gender = gender;
    }

    void setRollNo(int rollNo)
    {
        this->rollNo = rollNo;
    }

    void setMarks(float marks[3])
    {
        this->marks[3] = marks[3];
    }
};

int searchStudent(int number, Student *sptr[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (number == sptr[i]->getRollNo())
        {
            cout << "RollNo Present In Record : " << number << endl;

            cout << endl;
            sptr[i]->printData();
            return 1;
        }
    }    
    cout << "RollNo Not Present In Record" << endl;
    return -1;
}

void sortStudents(Student *sptr[], int size, int count)
{
    int sel_pos;
    int pos;

    for (sel_pos = 0; sel_pos < size - 1; sel_pos++) 
    {

        for (pos = sel_pos + 1; pos < size; pos++) 
        {
            
            if (sptr[sel_pos]->getRollNo() > sptr[pos]->getRollNo())
                swap(sptr[sel_pos], sptr[pos]);
        }
    }
    cout << "......Student Records Are Sorted According To RollNo......" << endl;
    cout << endl;
    for (int i = 0; i < count; i++)
    {
        sptr[i]->printData();
    }
}

int main()
{
    int i;
    int size;
    cout << "Enter No. of Students : ";
    cin >> size;
    int choice;
    int count = 0;
    Student *sptr[size];

    do
    {
        cout << "0. EXIT " << endl;
        cout << "1. Enter Student Data." << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Sort Students By RollNo" << endl;
        cout << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 0:
            cout << "..........Thank You.........." << endl;
            break;
        case 1:
            if (count < size)
            {
                sptr[count] = new Student();
                sptr[count]->acceptData();
                count++;
            }
            else
                cout << ".........Student Capacity is FUll........." << endl;
            cout << endl;
            break;
        case 2:
            for (int i = 0; i < count; i++)
            {
                sptr[i]->printData();
            }
            break;

        case 3:
            int number;
            cout << "Enter RollNo That You Want To Search : ";
            cin >> number;
            searchStudent(number, sptr, count);
            break;

        case 4:
            sortStudents(sptr, size, count);
            break;

        default:
            cout << "..........Invalid Choice........." << endl;
            cout << endl;
        }
    } while (choice != 0);
    
    for (int i = 0; i < count; i++)
    {
        delete sptr[i];
        sptr[i] = NULL;
    }

    return 0;
}