#include <iostream>
using namespace std;

class Employee
{
    protected:
        int id;
        double sal;

    public:
        Employee()
        {
            id=0;
            sal=0;
        }

        Employee(int id,double sal)
        {
            this->id = id;
            this->sal = sal;
        }

        virtual void accept()
        {
            cout<<"Enter the id : ";
            cin>>id;
            cout<<"Enter the salary : ";
            cin>>sal;
        }

        void set_id(int id)
        {
            this->id = id;
        }

        void set_salary(double sal)
        {
            this->sal = sal;
        }

        int get_id()
        {
            return this->id;
        }

        double get_sal()
        {
            return this->sal;
        }

        virtual void display()
        {
            cout<<"ID : "<<this->id<<endl;
            cout<<"Salary : "<<this->sal<<endl;
        }
};

class Manager:virtual public Employee
{
    protected:
        double bonus;

    public:
        Manager()
        {
            bonus = 1000;
        }

        Manager(int id,double sal,double bonus)
        {
            this->id = id;
            this->sal = sal;
            this->bonus = bonus;
        }

        void accept()
        {
            Employee::accept();
            cout<<"Enter the bonus : ";
            cin>>bonus; 
        }

        void set_bonus(double bonus)
        {
            this->bonus =  bonus;
        }

        double get_bonus()
        {
            return this->bonus;
        }

        void display()
        {
            Employee ::display();
            cout<<"Bonus : "<<this->bonus<<endl;
        }
};

class Salesman:virtual public Employee
{
    protected:
        double comm;

    public:
        Salesman()
        {
            comm = 100;
        }

        Salesman(int id,double sal,double comm)
        {
            this->id = id;
            this->sal = sal;
            this->comm = comm;
        }

        void accept()
        {
            Employee::accept();
            cout<<"Enter the commision : ";
            cin>>comm;
        }

        void set_comm(double comm)
        {
            this->comm = comm;
        }

        double get_comm()
        {
            return this->comm;
        }

        void display()
        {
            Employee::display();
            cout<<"Commision : "<<comm<<endl;
        }

};

class Sales_Manager : public Manager,public Salesman
{
    public:
        Sales_Manager()
        {
        }

        Sales_Manager(int id,double sal,double bonus,double comm)
        {
            this->id = id;
            this->sal = sal;
            this->bonus = bonus;
            this->comm = comm;
        }

        void accept()
        {
            double b,c;
            Employee::accept();
            cout<<"Enter the bonus : "; 
            cin>>b;
            cout<<"Enter the commission : ";
            cin>>c; 
            set_bonus(b);
            set_comm(c);          
        }

        void display()
        {
            Employee::display();
            cout<<"Bonus : "<<get_bonus()<<endl;
            cout<<"Commission : "<<get_comm()<<endl;
        }
};

int main()
{
    Sales_Manager S;
    S.accept();
    S.display();

    return 0;
}