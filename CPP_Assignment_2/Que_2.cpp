/*
Q2. Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a fifty-cent toll.
Mostly they do, but sometimes a car goes by without paying.
The tollbooth keeps track of the number of cars that have gone by and of the total amount of money
collected. Model this tollbooth with a class called tollbooth.
The two data items are a type unsigned int to hold the total number of cars, and a type double to
hold the total amount of money collected.
A constructor initializes all data members to 0. A member function called payingCar() increments
the car total and adds 0.50 to the cash total. An other function, called nopayCar()
increments the car total but adds nothing to the cash total. Finally, a member function called
printOnConsole() displays the two totals and number of paying as well as non paying cars total.
*/

#include <iostream>
using namespace std;

class Tollbooth
{
    private:
        unsigned int totalCars;
        double totalMoney;
        int payCar=0;
        int nonPayCar=0;

    public:
        Tollbooth()
        {   
            totalCars = 0;
            totalMoney = 0;
        }
        void payingCar()
        {
            payCar++;
            totalCars++;
            totalMoney += 0.5;
        }
        void nopayCar()
        {
            nonPayCar++;
            totalCars++;
        }
        void printOnConsole()
        {
            cout<<endl;
            cout<<"Number of cars paid : "<<payCar<<endl;
            cout<<"Number of cars not paid : "<<nonPayCar<<endl;
            cout<<"Number of total cars : "<<totalCars<<endl;
            cout<<"Total money collected : "<<totalMoney<<endl<<endl;
        }
};


int main()
{
    Tollbooth T1;
    int choice;
    do
    {
        cout<<"1. Paying Car"<<endl;
        cout<<"2. Non-Paying Car"<<endl;
        cout<<"0. EXIT"<<endl<<endl;
        cout<<"Enter the choice : ";
        cin>>choice;

        switch (choice)
        {
        case 0:
            cout<<endl<<"........Thank You........"<<endl;
            break;

        case 1:
            T1.payingCar();
            T1.printOnConsole();
            break;

        case 2:
            T1.nopayCar();
            T1.printOnConsole();
            break;
        
        default:
            cout<<endl<<"........Invalid..........."<<endl<<endl;
            break;
        }

    } while (choice != 0);
    

    return 0;
}