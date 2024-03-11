#include <iostream>
using namespace std;

class Time
{
    int hr;
    int min;
    int sec;

    public:
        Time()
        {
            hr = 0;
            min = 0;
            sec = 0;
        }

        Time(int hr,int min,int sec)
        {
            this->hr = hr;
            this->min = min;
            this->sec = sec;
        }

        void printTime()
        {
            cout<<"Time :- "<<hr<<" : "<<min<<" : "<<sec<<endl;
        }

        int getHour()
        {
            return hr;
        }

        int getMinute()
        {
            return min;
        }

        int getSeconds()
        {
            return sec;
        }

        void setHour(int hr)
        {
            this->hr = hr;
            cout<<"Hour is updated"<<endl;
        }

        void setMinute(int min)
        {
            this->min = min;
            cout<<"Minutes is updated"<<endl;
        }

        void setSeconds(int sec)
        {
            this->sec = sec;
            cout<<"Seconds is updated"<<endl;
        }
};

int main()
{
    int n;
    cout<<"Enter how many objects you want: ";
    cin>>n;
    int hr,min,sec;
    int i=0;
    Time *arr[n];
    int choice;

    for(int i=0;i<n;i++)
    {
        cout<<endl<<"1. Update Time"<<endl;
        cout<<"2. Take Default Time"<<endl;
        cout<<endl<<"Enter the choice : ";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter the hr : ";
            cin>>hr;
            cout<<"Enter the min : ";
            cin>>min;
            cout<<"Enter the sec : ";
            cin>>sec;
            arr[i] = new Time(hr,min,sec);
            cout<<endl<<"Updated Time"<<endl;
            arr[i]->printTime();
        }
        else if(choice==2)
        {
            arr[i] = new Time;
            cout<<endl<<"Default Time"<<endl;
            arr[i]->printTime();
        }
        else
        {
            cout<<"Invalid Choice"<<endl;
            cout<<endl<<"We have to take default time"<<endl;
            arr[i] = new Time;
        }
    }

    for(int i=0;i<n;i++)
    {
        delete arr[i];
        arr[i] = NULL;
    }

    return 0;
}