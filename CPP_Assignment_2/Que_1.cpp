#include <iostream>
using namespace std;

class Volume
{
    private:
        double length;
        double width;
        double height;
        double volume;

    public:
        Volume()
        {
            length=1;
            width=1;
            height=1;
        }

        Volume(double l,double w,double h)
        {
            length=l;
            width=w;
            height=h;
        }

        void displayVolume()
        {
            volume  = length*width*height;
            cout<<endl;
            cout<<"Volume of box : "<<volume<<endl<<endl;
        }
};

int main()
{
    int choice;
    Volume v1;
    Volume *vptr = NULL;
    double l,w,h;
    do
    {
        cout<<endl;
        cout<<"1. Display Default Volume"<<endl;
        cout<<"2. Accept and Display Volume"<<endl;
        cout<<"0. EXIT"<<endl<<endl;
        cout<<"Enter the choice : ";
        cin>>choice;
        switch (choice)
        {
        case 0:
            cout<<endl<<"Thank You"<<endl;
            break;

        case 1:
            v1.displayVolume();
            break;

        case 2:
            cout<<endl;
            cout<<"Enter the length : ";
            cin>>l;
            cout<<"Enter the width : ";
            cin>>w;
            cout<<"Enter the height : ";
            cin>>h;
            vptr = new Volume(l,w,h);
            vptr->displayVolume();

        default:
            cout<<"Invalid Command"<<endl;
            break;
        }
    } while (choice != 0);
    delete vptr;
    vptr = NULL;
    
    return 0;
}