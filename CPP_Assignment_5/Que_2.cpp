#include <iostream>
using namespace std;


class Product
{
    public:
        int id;
        string title;
        double price;
        
        virtual void acceptData() = 0;
        virtual void calculateBill() = 0;
        virtual void display() = 0;
};

double total = 0.0;

class Book:public Product
{
    private:
        string author;

    public:
        void acceptData()
        {
            cout<<"Enter the id : ";
            cin>>id;
            cout<<"Enter the title : ";
            getline(cin>>ws,title);
            cout<<"Enter the author : ";
            getline(cin>>ws,author);
            cout<<"Enter the price : ";
            cin>>price;
        }

        void calculateBill()
        {
            total = total + (price - (price*10/100));
            cout<<"Bill : "<<total<<" Rupees"<<endl;
        }

        void display()
        {
            cout<<endl;
            cout<<"ID : "<<id<<endl;
            cout<<"Title : "<<title<<endl;
            cout<<"Price : "<<price<<endl;
            cout<<endl<<"Total Bill : "<<total<<endl<<endl;
        }
};

class Tape:public Product
{
    private:
        string singer;

    public:
        void acceptData()
        {
            cout<<"Enter the id : ";
            cin>>id;
            cout<<"Enter the title : ";
            getline(cin>>ws,title);
            cout<<"Enter the singer : ";
            getline(cin>>ws,singer);
            cout<<"Enter the price : ";
            cin>>price;
        }

        void calculateBill()
        {
            total = total + (price - (price*5/100));
            cout<<"Bill : "<<total<<" Rupees"<<endl;
        }

        void display()
        {
            cout<<endl;
            cout<<"ID : "<<id<<endl;
            cout<<"Title : "<<title<<endl;
            cout<<"Price : "<<price<<endl;
            cout<<endl<<"Total Bill : "<<total<<endl<<endl;
        }
};

int main()
{
    int num,choice,counter=0;
    cout<<"How many product you want to buy : ";
    cin>>num;
    Product *arrProduct[num];
    do
    {
        cout<<endl;
        cout<<"0. EXIT"<<endl;
        cout<<"1. Buy Book"<<endl;
        cout<<"2. Buy Tape"<<endl;
        cout<<"3. Total Bill Details"<<endl;
        cout<<endl<<"Enter the choice : ";
        cin>>choice;

        switch(choice)
        {
            case 0:
                cout<<"................Thank you................"<<endl;
                break;

            case 1: 
                if(counter >= 0 && counter < num)
                {
                    arrProduct[counter] = new Book;
                    arrProduct[counter]->acceptData();
                    arrProduct[counter]->calculateBill();
                    counter++;
                }
                else
                {
                    cout<<"Sorry, your cart is full"<<endl;
                }
                break;

            case 2:
                if(counter >= 0 && counter < num)
                {
                    arrProduct[counter] = new Tape;
                    arrProduct[counter]->acceptData();
                    arrProduct[counter]->calculateBill();
                    counter++;
                }
                else
                {
                    cout<<"Sorry, your cart is full"<<endl;
                }
                break;

            case 3:
                for(int i=0;i<counter;i++)
                {
                    arrProduct[i]->display();
                }
                break;
        }

    }while(choice != 0);
    

    
    return 0;
}