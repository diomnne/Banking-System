#include <iostream>
#include <fstream>

using namespace std;

void deposit(double amount, ofstream &depositFile, ofstream &balanceFile);
void withdraw(double amount, ofstream &withdrawFile, ofstream &balanceFile);
void checkBalance();

int main()
{
    double amount;
    char key;
    ofstream depositFile, withdrawFile, balanceFile;

    depositFile.open("deposits.txt");
    withdrawFile.open("withdrawals.txt");
    balanceFile.open("balanceInq.txt");

    do
    {
        cout << endl << "[D] Deposit" << endl << "[W] Withdraw" << endl << "[C] Check Balance" << endl << "[E] Exit" << endl;
        cin >> key;
        key = toupper(key);

        switch(key)
        {
            case 'D':
                cout << "Enter amount to deposit: ";
                cin >> amount;
                deposit(amount, depositFile, balanceFile);
                break;

            case 'W':
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdraw(amount, withdrawFile, balanceFile);
                break;

            case 'C':
                checkBalance();
                break;

            case 'E':
                break;

            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
    while(key != 'E');

    depositFile.close();
    withdrawFile.close();
    balanceFile.close();

    return 0;

}

double balance = 0.0;

void deposit(double amount, ofstream &depositFile, ofstream &balanceFile)
{
    balance += amount;

    cout << "Deposit successful! New balance: PHP " << balance << endl;
    depositFile << "Deposit: PHP " << amount << ", New balance: PHP " << balance << endl;
    balanceFile << "Current balance: PHP " << balance << endl;
}

void withdraw(double amount, ofstream &withdrawFile, ofstream &balanceFile)
{
    if(balance < amount)
    {
        cout << "Insufficient funds. Withdrawal unsuccessful." << endl;
        balanceFile << "Current balace: PHP " << balance << endl;
    }

    else
    {
        balance -= amount;

        cout << "Withdrawal successful! New balance: PHP " << balance << endl;
        withdrawFile << "Withdrawal: PHP " << amount << ", New balance: PHP " << balance << endl;
        balanceFile << "Current balance: PHP " << balance << endl;
    }
}

void checkBalance()
{
    cout << "Current balance: PHP " << balance << endl;
}


