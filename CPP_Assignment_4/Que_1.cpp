#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

    public: 
        Date()
        {
            day = 1;
            month = 1;
            year = 2001;
        }

        Date(int d,int m,int y)
        {
            day = d;
            month = m;
            year = y;
        }

        void acceptDate()
        {
            cout<<"Enter the day : ";
            cin>>day;
            cout<<"Enter the month : ";
            cin>>month;
            cout<<"Enter the year : ";
            cin>>year;
        }

        void set_day(int d)
        {
            day = d;
        }

        void set_month(int m)
        {
            month = m;
        }

        void set_year(int y)
        {
            year = y;
        }

        int get_day()
        {
            return day;
        }

        int get_month()
        {
            return month;
        }

        int get_year()
        {
            return year;
        }

        void displayDate()
        {
            cout<<"Date :- "<<day<<"/"<<month<<"/"<<year<<endl;
        }

        bool is_leap_year()
       
        {
            if(year%400 == 0 )
            {
                return true;
            }
            else if(year%100 == 0)
            {
                return false;
            }
            else if(year%4 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

};

class Person
{
    string name;
    string addr;
    Date Birth_Date;

    public:
        Person()
        {
            name = "Abhishek";
            addr = "TCG";
            Birth_Date.set_day(10);
            Birth_Date.set_month(6);
            Birth_Date.set_year(2001);
        }

        Person(string n,string a,int d,int m,int y) : Birth_Date(d,m,y)
        {
            name = n;
            addr = a;
        }

        void accept()
        {
            cout<<"Enter the name : ";
            cin>>name;
            cout<<"Enter the address : ";
            cin>>addr;
            Birth_Date.acceptDate();
        }

        void set_name(string name)
        {
            this->name = name;
        }

        void set_addr(string addr)
        {
            this->addr = addr;
        }

        void set_birth_date(int day,int month,int year)
        {
            Birth_Date = Date(day,month,year);
        }

        string get_name()
        {
            return this->name;
        }

        string get_addr()
        {
            return this->addr;
        }

        Date get_bith_date()
        {
            return Birth_Date;
        }

        void display()
        {
            cout<<"Name : "<<name<<endl;
            cout<<"Address : "<<addr<<endl;
            Birth_Date.displayDate();
        }

};

class Employee
{
    int id;
    double sal;
    string dep;
    Date Joining_Date;

    public:
        Employee()
        {
            id = 83990;
            sal = 10000;
            dep = "Electrical";
            Joining_Date = Date();
        }

        Employee(int id,double sal,string dep,int day,int month,int year) : Joining_Date(day,month,year)
        {
            this->id = id;
            this->sal = sal;
            this->dep = dep;
        }

        void accept_Employee()
        {
            cout<<"Enter the id : ";
            cin>>id;
            cout<<"Enter the department : ";
            cin>>dep;
            cout<<"Enter the salary : ";
            cin>>sal;
            cout<<"Enter the date of joining : "<<endl;
            Joining_Date.acceptDate();
        }

        void setId(int id)
        {
            this->id = id;
        }

        void setSalary(double sal)
        {
            this->sal = sal;
        }

        void setJoinDate(int d,int m,int y)
        {
            Joining_Date = Date(d,m,y);
        }
        
        int getId()
        {
            return this->id;
        }

        double getSalary()
        {
            return this->sal;
        }

        string getDep()
        {
            return this->dep;
        }

        Date getJoinDate()
        {
            return Joining_Date;
        }

        void displayEmp()
        {
            cout<<"Employee id : "<<id<<endl;
            cout<<"Employee department : "<<dep<<endl;
            cout<<"Employee salary : "<<sal<<endl;
            Joining_Date.displayDate();
        }

};

int main()
{
    Employee E1;
    
    E1.displayEmp();
    E1.getJoinDate().displayDate();

    return 0;
}