#include <iostream>
using namespace std;

class Address
{
    private : 
        string building;
        string street;
        string city;
        int pin;

    public :
        Address()
        {
            cout<<endl;
            building = "Enter_Building";
            street = "Enter_Street";
            city = "Enter_City";
            pin = 444805;
        }

        Address(string b,string s,string c,int p)
        {
            building = b;
            street = s;
            city = c;
            pin = p;
        }

        void accept()
        {
            cout<<endl;
            cout<<"Enter the building : ";
            cin>>building;
            cout<<"Enter the street : ";
            cin>>street;
            cout<<"Enter the city : ";
            cin>>city;
            cout<<"Enter the pin : ";
            cin>>pin;
        }

        void display()
        {
            cout<<endl;
            cout<<"Enter the building : "<<building<<endl;
            cout<<"Enter the street : "<<street<<endl;
            cout<<"Enter the city : "<<city<<endl;
            cout<<"Enter the pin : "<<pin<<endl;
        }

        string getBuilding()
        {
            return building;
        }

        string getStreet()
        {
            return street;
        }

        string getCity()
        {
            return city;
        }

        int getPin()
        {
            return pin;
        }

        void setBuilding(string building)
        {
            this->building = building;
        }

        void setStreet(string street)
        {
            this->street = street;
        }

        void setCity(string city)
        {
            this->city = city;
        }

        void setPin(int pin)
        {
            this->pin = pin;
        }

};

int main()
{
    Address A1;
    A1.display();

    Address A2("TCG","1st_Street","Pune",444806);
    A2.display();

    A1.accept();
    A1.display();


    return 0;
}