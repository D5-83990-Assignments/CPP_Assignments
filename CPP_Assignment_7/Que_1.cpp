#include <iostream>
using namespace std;

class Employee
{
    int id;
    double sal;

public:
    Employee()
    {
        this->id = 0;
        this->sal = 0;
    }

    Employee(int id,double sal)
    {
        this->id = id;
        this->sal = sal;
    }

    virtual void accept()
    {
        cout<<"Enter the ID - ";
        cin>>this->id;
        cout<<"Enter the salary : ";
        cin>>this->sal;
    }

    void set_id(int id)
    {
        this->id = id;
    }

    void set_sal(double sal)
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

    virtual ~Employee()
    {
        cout<<"Employee Destructor"<<endl;
    }
};

class Manager:virtual public Employee
{
    double bonus;

public:
    Manager()
    {
        this->bonus = 0;
    }

    Manager(int id,double sal,double bonus):Employee(id,sal)
    {
        this->bonus = bonus;
    }

    void accept()
    {
        Employee::accept(); // IF we use accept() then it GIVE : Segmentation fault
        // IF we use [Employee::accept()] then it GIVE CORRECT OUTPUT
        accept_manager();
    }

    void accept_manager()
    {
        cout<<"Enter the bonus : ";
        cin>>this->bonus;
    }

    void set_bonus(double bonus)
    {
        this->bonus = bonus;
    }

    double get_bonus()
    {
        return this->bonus;
    }

    void display()
    {
        Employee::display();  // IF we use display() then it GIVE : Segmentation fault
        // IF we use [Employee::display()] then it GIVE CORRECT OUTPUT
        display_manager();
    }

    void display_manager()
    {
        cout<<"Bonus : "<<this->bonus<<endl;
    }

    ~Manager()
    {
        cout<<"Manager Destructor"<<endl;
    }
};

class Salesman:virtual public Employee
{
    double comm;

public:
    Salesman()
    {
        this->comm = 0;
    }

    Salesman(int id,double sal,double comm) : Employee(id,sal)
    {
        this->comm = comm;
    }

    void accept()
    {
        Employee::accept();
        accept_salesman();
    }

    void accept_salesman()
    {
        cout<<"Enter the commission : ";
        cin>>this->comm;
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
        display_salesman();
    }

    void display_salesman()
    {
        cout<<"Commission : "<<this->comm<<endl;
    }

    ~Salesman()
    {
        cout<<"Salesman Destructor"<<endl;
    }
};

class SalesManager:public Manager,public Salesman
{
    public:
        SalesManager()
        {

        }

        SalesManager(int id,double sal,double bonus,double comm)
        {
            this->set_id(id); // If we NOT make our BASE class virtual then it will give ERROR
            this->set_sal(sal);
            this->set_bonus(bonus);
            this->set_comm(comm);
        }

        void accept()
        {
            Employee::accept();
            this->accept_manager();
            this->accept_salesman();
        }

        void display()
        {
            Employee::display();
            this->display_manager();
            this->display_salesman();
        }

        ~SalesManager()
        {
            cout<<"Salesmanager Destructor"<<endl;
        }
};

int main()
{
    // Manager M;
    // M.accept();
    // M.display();

    // Salesman S;
    // S.accept();
    // S.display();

    // SalesManager S;
    // S.accept();
    // S.display();

    Employee *ptr[10];
    int choice,index=0;
    do
    {
        cout<<endl;
        cout<<"0. EXIT"<<endl;
        cout<<"1. Register Manager"<<endl;
        cout<<"2. Register Salesman"<<endl;
        cout<<"3. Register Sales Manager"<<endl;
        cout<<"4. Display All Employee"<<endl;
        cout<<"5. Display All Managers"<<endl;
        cout<<"6. Display All Salesman"<<endl;
        cout<<"7. Display All SalesManagers"<<endl;
        cout<<endl<<"Enter the choice : ";
        cin>>choice;

        switch(choice)
        {
            case 0:
                cout<<"Thank You"<<endl;
                break;

            case 1:
                if(index<10)
                {
                    ptr[index] = new Manager;
                    ptr[index]->accept();
                    index++;
                }
                else
                {
                    cout<<"Sorry, No more reqruitment"<<endl;
                }
                break;

            case 2:
                if(index<10)
                {
                    ptr[index] = new Salesman;
                    ptr[index]->accept();
                    index++;
                }
                else
                {
                    cout<<"Sorry, No more reqruitment"<<endl;
                }
                break;

            case 3:
                if(index<10)
                {
                    ptr[index] = new SalesManager;
                    ptr[index]->accept();
                    index++;
                }
                else
                {
                    cout<<"Sorry, No more reqruitment"<<endl;
                }
                break;

            case 4:
                for(int i=0;i<index;i++)
                {
                    cout<<endl;
                    if(typeid(*ptr[i]) == typeid(Manager)) // Here we have to use "typeid()" on both condition // Here we have to use *ptr[i] NOT ptr[i]
                    {
                        cout<<endl<<"Manager:"<<endl;
                        ptr[i]->display();
                        cout<<endl;
                    }
                    else if(typeid(*ptr[i])== typeid(Salesman))
                    {
                        cout<<endl<<"Salesman:"<<endl;
                        ptr[i]->display();
                        cout<<endl;
                    }
                    else if(typeid(*ptr[i])==typeid(SalesManager))
                    {
                        cout<<endl<<"Sales Manager:"<<endl;
                        ptr[i]->display();
                        cout<<endl;
                    }
                }
                break;

            case 5:
                for(int i=0;i<index;i++)
                {
                    cout<<endl;
                    if(typeid(*ptr[i]) == typeid(Manager)) // Here we have to use "typeid()" on condition
                    {
                        cout<<endl<<"Manager:"<<endl;
                        ptr[i]->display();
                        cout<<endl;
                    }
                }
                break;
            
            case 6:
                for(int i=0;i<index;i++)
                {
                    cout<<endl;
                    if(typeid(*ptr[i]) == typeid(Salesman)) // Here we have to use "typeid()" on condition
                    {
                        cout<<endl<<"Salesman:"<<endl;
                        ptr[i]->display();
                        cout<<endl;
                    }
                }
                break;

            case 7:
                for(int i=0;i<index;i++)
                {
                    cout<<endl;
                    if(typeid(*ptr[i]) == typeid(SalesManager)) // Here we have to use "typeid()" on condition
                    {
                        cout<<endl<<"Sales Manager:"<<endl;
                        ptr[i]->display();
                        cout<<endl;
                    }
                }
                break;

        }

    } while (choice != 0);
    

    return 0;
}