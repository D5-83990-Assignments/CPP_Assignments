#include <iostream>
using namespace std;

enum Account_type{SAVING=1,CURRENT,DMAT}account_type;

class Account
{
    int id;
    Account_type account_type;
    double balance;
    int acc_type;

    public:
        Account()
        {
            id = 0;
            account_type = SAVING;
            balance = 0;
        }

        Account(int id,int acc_type,double balance)
        {
            this->id = id;
            this->account_type = Account_type(acc_type);
            this->balance = balance;
        }

        void accept()
        {  
            cout<<endl;
            cout<<"Enter id : ";
            cin>>id;
            cout<<"1. SAVINGS"<<endl;
            cout<<"2. CURRRENT"<<endl;
            cout<<"3. DMAT"<<endl;
            cout<<"Enter the account type : ";
            cin>>acc_type;
            switch (acc_type)
            {
            case SAVING:
                account_type = Account_type(acc_type);
                break;

            case CURRENT:
                account_type = Account_type(acc_type);
                break;

            case DMAT:
                account_type = Account_type(acc_type);
                break;
            
            default:
                cout<<"Invalid choice, we make your account SAVING by default"<<endl;
                account_type = Account_type(1);
                break;
            }
            account_type = Account_type(acc_type);
        }

        void setId(int id)
        {
            this->id = id;
        }

        void setType(int acc_type)
        {
            account_type = Account_type(acc_type);
        }

        int getId()
        {
            return this->id;
        }

        Account_type getType()
        {
            return this->account_type;
        }

        double getBalance()
        {
            return this->balance;
        }

        void deposit(double value)
        {
            this->balance = this->balance + value;
        }

        void withdraw(double value)
        {
            this->balance = this->balance - value;
        }

        void display()  // Display the data for user
        {
            cout<<endl;
            cout<<"Account ID : "<<this->id<<endl;
            if(this->acc_type == SAVING)
            {
                cout<<"Account type : SAVING"<<endl;
            }
            else if(this->acc_type == CURRENT)
            {
                cout<<"Account type : CURRENT"<<endl;   
            }
            else if(this->acc_type == DMAT)
            {
                cout<<"Account type : DMAT"<<endl;
            }
            cout<<"Balance = "<<this->balance<<endl;
        }
};

int main()
{
    int type,choice,num,index=0;
    double value;
    cout<<"Enter how many accounts you want to register : ";
    cin>>num;
    Account *ptr = NULL;
    Account *aptr[num];

    do
    {
        cout<<endl;
        cout<<"0. EXIT"<<endl;
        cout<<"1. Register account"<<endl;
        cout<<"2. Deposit Amount"<<endl;
        cout<<"3. Withdraw Amount"<<endl;
        cout<<"4. Display Account"<<endl;
        cout<<"Enter the choice : ";
        cin>>choice;

        switch(choice)
        {
            case 0:
                cout<<endl;
                cout<<"Thank you....Please visit again"<<endl;
                break;

            case 1:
                if(index < num)
                {
                    ptr = new Account;
                    aptr[index] = ptr;
                    aptr[index]->accept();
                    index++;
                }
                else
                {
                    cout<<"Your limit is full"<<endl;
                }
                break;

            case 2:
                if(index>=0 && index<num)
                {
                    cout<<"Enter the deposit amount : ";
                    cin>>value;
                    aptr[index-1]->deposit(value);
                    cout<<"Your balance : "<<aptr[index-1]->getBalance()<<endl;
                }
                else
                {
                    cout<<"Sorry, No customer exist"<<endl;
                }
                break;

            case 3:
                if(index>=0 && index<num)
                {
                    cout<<"Enter the withdraw amount : ";
                    cin>>value;
                    aptr[index-1]->withdraw(value);
                    cout<<"Your balance : "<<aptr[index-1]->getBalance()<<endl;
                }
                else
                {
                    cout<<"Sorry, No customer exist"<<endl;
                }
                break;

            case 4:
                if(index>=0 && index<num)
                {
                    for(int i=0;i<index;i++)
                    {
                        aptr[i]->display();
                    }
                }
        }

    }while(choice != 0);

    

    return 0;
}