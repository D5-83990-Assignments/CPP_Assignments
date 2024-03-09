#include <iostream>
using namespace std;

    
struct Date 
{
    private:
        int day;
        int month;
        int year;

    public:
        void initDate()
        {
            day = 7;
            month = 3;
            year = 2024;
        }

        void acceptDateFromConsole()
        {
            cout<<"Enter the day : ";
            cin>>day;
            cout<<"Enter the month : ";
            cin>>month;
            cout<<"Enter the year : ";
            cin>>year;
        }

        void printDateOnConsole()
        {
            cout<<"Date :- "<<day<<"/"<<month<<"/"<<year<<endl;
        }

        bool isLeapYear()
        {
            if(year%400 == 0 || year%4 == 0 && year%100 != 0) 
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    
};

class ClassDate 
{
        int day;
        int month;
        int year;

    public:
        void initDate()
        {
            day = 7;
            month = 3;
            year = 2024;
        }

        void acceptDateFromConsole()
        {
            cout<<"Enter the day : ";
            cin>>day;
            cout<<"Enter the month : ";
            cin>>month;
            cout<<"Enter the year : ";
            cin>>year;
        }

        void printDateOnConsole()
        {
            cout<<"Date :- "<<day<<"/"<<month<<"/"<<year<<endl;
        }

        bool isLeapYear()
        {
            if(year%400 == 0 || year%4 == 0 && year%100 != 0)
                return true;
            else
                return false;
            
        }
    
};

void menuForStruct(struct Date *Date1)
{
    int choice;
    Date1->initDate();
    do
    {
        cout<<endl;
        cout<<"USING STRUCTURE"<<endl;
        cout<<"1. Accept Date"<<endl;
        cout<<"2. Display Date"<<endl;
        cout<<"3. Check Leap Year"<<endl;
        cout<<"0. EXIT"<<endl;
        cout<<"Enter the choice : ";
        cin>>choice;
        cout<<endl;
        switch (choice)
        {
        case 0:
            cout<<"Thank You......."<<endl;
            break;

        case 1:
            Date1->acceptDateFromConsole();
            break;

        case 2:
            Date1->printDateOnConsole();
            break;

        case 3:
            if(Date1->isLeapYear())
            {
                cout<<"This year is leap year"<<endl;
            }
            else
            {
                cout<<"This year is not leap year"<<endl;
            }
            break;
        
        default:
            printf("Invalid.....\n");
            break;
        }

    }while(choice  != 0);
}

void menuForClass(ClassDate *Date1)
{
    int choice;
    Date1->initDate();
    do
    {
        cout<<endl;
        cout<<"USING CLASS"<<endl;
        cout<<"1. Accept Date"<<endl;
        cout<<"2. Display Date"<<endl;
        cout<<"3. Check Leap Year"<<endl;
        cout<<"0. EXIT"<<endl;
        cout<<"Enter the choice : ";
        cin>>choice;
        cout<<endl;
        switch (choice)
        {
        case 0:
            cout<<"Thank You......."<<endl;
            break;

        case 1:
            Date1->acceptDateFromConsole();
            break;

        case 2:
            Date1->printDateOnConsole();
            break;

        case 3:
            if(Date1->isLeapYear())
            {
                cout<<"This year is leap year"<<endl;
            }
            else
            {
                cout<<"This year is not leap year"<<endl;
            }
            break;
        
        default:
            printf("Invalid.....\n");
            break;
        }

    }while(choice  != 0);
}

int main()
{
    int select;
    cout<<"1. Using structure"<<endl;
    cout<<"2. Using Classes"<<endl;
    cout<<"0. EXIT"<<endl;
    cout<<"Enter the choice : ";
    cin>>select;
    switch(select)
    {
        case 1:
            struct Date D1;
            menuForStruct(&D1);
            break;
        
        case 2:
            ClassDate D2;
            menuForClass(&D2);
            break;

        default:
            cout<<"Sorry we cannot move further"<<endl;
    }
    return 0;

}