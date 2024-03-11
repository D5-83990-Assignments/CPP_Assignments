#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    const int SIZE;
    int top;

    public: 
        Stack():Stack(5){}

        Stack(int size) : SIZE(size)
        {
            arr = new int[size];
            top = -1;
        }

        bool isEmpty()
        {
            if(top == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool isFull()
        {
            if(top == SIZE-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        int peek()
        {
            return arr[top];
        }

        void push(int data)
        {
            top++;
            arr[top] = data;
        }

        int pop()
        {
            return arr[top--];
        }

        void print()
        {
            for(int i=0;i<=top;i++)
            {
                cout<<arr[i]<<"->";
            }
        }
};
      
int main()
{
    int size,data,choice;
    cout<<"Enter the size of stack : ";
    cin>>size;
    Stack s(size);

    do
    {
        cout<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Is stack full"<<endl;
        cout<<"5. Is stack empty"<<endl;
        cout<<"0. EXIT"<<endl;
        cout<<"Enter the choice : ";
        cin>>choice;

        switch(choice)
        {
            case 0:
                cout<<"..............Thank You................."<<endl;
                break;

            case 1:
                if(s.isFull())
                {
                    cout<<"Stack is full"<<endl;
                }
                else
                {
                    cout<<"Enter the data you want to push : ";
                    cin>>data;
                    s.push(data);
                }
                break;

            case 2:
                if(s.isEmpty())
                {
                    cout<<"Stack is empty"<<endl;
                }
                else
                {
                    cout<<"Poped data : "<<s.pop()<<endl;
                }
                break;

            case 3:
                if(s.isEmpty())
                {
                    cout<<"Stack is empty"<<endl;
                }
                else
                {
                    cout<<"Peek element is : "<<s.peek()<<endl;
                }
                break;

            case 4: 
                if(s.isFull())
                {
                    cout<<"Stack is full"<<endl;
                }
                else
                {
                    cout<<"Stack is not full"<<endl;
                }
                break;

            case 5:
                if(s.isEmpty())
                {
                    cout<<"Stack is Empty"<<endl;
                }
                else
                {
                    cout<<"Stack is not empty"<<endl;
                }
                break;

            default:
                cout<<"............Invalid............."<<endl;
                break;
        }
    }while(choice != 0);
      

    return 0;
}