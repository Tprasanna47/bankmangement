#include<iostream>
#include<algorithm>
using namespace std;

template < class X, class Y > void withdrawal (X &savingsbalance, Y &withdraw)                             //TEMPLATE
{
    savingsbalance = savingsbalance - withdraw;
    cout << "After Withdrawal, your Remaining Balance: "<<savingsbalance<<endl;
}

void interest_(int savingsbalance)
{
    float interest_amount;
    interest_amount = (savingsbalance * 4) / 100;
    cout<<"Total Interest: "<<interest_amount<<endl;
}

void interest_(float savingsbalance)                                                                     //OVERLOADING
{
    float interest_amount;
    interest_amount = (savingsbalance * 4) / 100;
    cout<<"Total Interest: "<<interest_amount<<endl;
}

class account                                                                                            //CLASS
{
    char customer_name[200];
    int account_number;
    char account_type[200];
    public:
    void get_accountinfo ()
    {
        cout << "\nEnter Customer Name: ";
        cin >> customer_name;
        cout << "Enter Account Number: ";
        cin >> account_number;
        cout << "Enter Account Type: ";
        cin >> account_type;
    }
    void display_accountinfo ()
    {
        cout << "\nCustomer Name: " << customer_name;
        cout << "\nAccount Number: " << account_number;
        cout << "\nAccount Type: " << account_type;
    }
};


class current_account:public account                                                                     //INHERITANCE
{
    static float balance;
    public:
    void display_currentbalance ()
    {
        cout << "Balance: " << balance << "\n";
    }
    void deposit_currentbalance ()
    {
        float deposit;
        cout << "\nEnter amount to be Deposited: ";
        cin >> deposit;
        balance = balance + deposit;
    }
    void withdraw_currentbalance ()
    {
        float penalty, withdraw;
        cout << "\n\nBalance: " << balance;
        cout << "\nEnter amount to be Withdrawn: ";
        cin >> withdraw;
        if(balance < 500)
        {
            float penalty_charged;
            float minimum=500;
            penalty=(500-balance)/10;
            penalty_charged=min(penalty,minimum);                                                        //USING STL
            balance=balance-penalty;
            cout<<"\nBalance is below 500.\nPenalty charged: "<<penalty_charged<<"\n";
        }
        else if (withdraw > balance)
        {
	        cout <<"\n\nInsufficient Balance.\nYou have to take permission for Bank Overdraft Facility.\n";
        }
        else
        {
            balance = balance - withdraw;
            cout << "After Withdrawal, your Remaining Balance: " << balance << "\n";
        }
    }
};

class savings_account:public account
{
    float withdraw;
    static float savingsbalance;
    public:
    void display_savingsbalance ()
    {
        cout << "Balance: "<<savingsbalance<<endl;
    }
    void deposit_savingsbalance ()
    {
        float deposit;
        cout << "\nEnter amount to be Deposited: ";
        cin >> deposit;
        savingsbalance = savingsbalance + deposit;
        interest_(savingsbalance);
        savingsbalance = savingsbalance + (savingsbalance * 4) / 100;
        cout << "Total Balance: " << savingsbalance << "\n";
    }
    void withdraw_savingsbalance ()
    {
        cout << "\nBalance: " << savingsbalance;
        cout << "\nEnter amount to be Withdrawn: ";
        cin >> withdraw;
        if (withdraw > savingsbalance)
        {
	        cout <<"\n\nInsufficient balance.\nYou have to take permission for Bank Overdraft Facility\n";
        }
        else
        {
            withdrawal (savingsbalance, withdraw);
           // savingsbalance = savingsbalance - withdraw;
        }
    }
};


float current_account::balance;
float savings_account::savingsbalance;


int main ()
{

    current_account c1;
    savings_account s1;
    cout << "----BANK MANAGEMENT SYSTEM----\n";
    cout << "\nEnter Account type: (S/C)\n";
    char type;
    cin >> type;
    int choice;
    if (type == 's' || type == 'S')
    {
        s1.get_accountinfo ();
        while (1)
	    {
	        cout << "\n--MAIN MENU--\n";
	        cout << "1) Deposit\n";
	        cout << "2) Withdraw\n";
	        cout << "3) Balance Enquiry\n";
	        cout << "4) Display Account Details\n";
	        cout << "5) Exit\n";
	        cout << "Enter Your choice: ";
	        cin >> choice;
  	        switch (choice)
	        {
	            case 1:
	                s1.deposit_savingsbalance ();
	                break;
                case 2:
                    s1.withdraw_savingsbalance ();
                    break;
	            case 3:
	                cout << "\n";
                    s1.display_savingsbalance ();
                    break;
                case 4:
                    s1.display_accountinfo ();
	                cout << "\n";
	                s1.display_savingsbalance ();
	                break;
	            case 5:
                    exit (0);
                default:
	                cout << "\n\nEntered choice is invalid!\nTRY AGAIN\n";
	        }
	    }
    }
    else
    {
        {
            c1.get_accountinfo ();
	        while (1)
	        {
	            cout << "\n--MAIN MENU--\n";
	            cout << "1) Deposit\n";
	            cout << "2) Withdraw\n";
	            cout << "3) Balance Enquiry\n";
	            cout << "4) Display Account Details\n";
                cout << "5) Exit\n";
	            cout << "Enter Your choice: ";
	            cin >> choice;
	            switch (choice)
	            {
	                case 1:
	                    c1.deposit_currentbalance ();
	                    c1.display_currentbalance ();
		                break;
	                case 2:
		                c1.withdraw_currentbalance ();
		                break;
                    case 3:
	             	    cout << "\n";
	                	c1.display_currentbalance ();
                        break;
	                case 4:
		                c1.display_accountinfo ();
		                cout << "\n";
		                c1.display_currentbalance ();
                        break;
	                case 5:
                        exit (0);
	                default:
		                cout << "\n\nEntered choice is invalid!\nTRY AGAIN\n";
	            }
	        }
        }
    }
}
