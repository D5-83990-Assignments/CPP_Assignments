#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Stack
{
    T element;
    vector<T> arr;

public:
    bool isEmpty()
    {
        if(arr.size() == 0)
        {
            return true;
        }
        return false;
    }

    void pushBack(T element)
    {
        arr.push_back(element);
    }

    void popBack()
    {
        if(isEmpty())
        {
            cout<<"Sorry your stack is empty"<<endl;
        }
        else
        {
            arr.pop_back();
        }
    }

    void display()  // Display the data for user
    {
        for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i]<<endl;
        }
    }
};

int main()
{
    Stack<int> A;
    A.pushBack(10);
    A.pushBack(20);
    A.pushBack(30);
    A.pushBack(40);
    A.pushBack(50);
    cout<<"Before pop out : "<<endl;
    A.display();

    A.popBack();
    A.popBack();
    cout<<"After pop out : "<<endl;
    A.display();

    return 0;
}