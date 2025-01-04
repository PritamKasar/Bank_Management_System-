#include <iostream>
#include <conio.h>
#include <limits>  
using namespace std;

class bank {
    char name[100], add[100], y;
    int balance, amount;
public:
    void open_account();
    void deposite_money();
    void withdraw_money();
    void display_account();
};

void bank::open_account() {
    system("cls");
    cout << "\n============================== OPEN ACCOUNT ==============================\n";
    cout << "Enter your full name: ";
    cin.ignore();
    cin.getline(name, 100);
    cout << "Enter your address: ";
    cin.ignore();
    cin.getline(add, 100);
    cout << "What type of account you want to open? (saving (s) or current (c)): ";
    cin >> y;

    while (y != 's' && y != 'c') {
        cout << "Invalid input. Please choose 's' for savings or 'c' for current: ";
        cin >> y;
    }

    cout << "Enter amount for deposit: ";
    while (!(cin >> balance) || balance <= 0) {
        cout << "Invalid amount. Please enter a positive number: ";
        cin.clear();  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
    }

    cout << "Your account is created with balance: " << balance << endl;
}

void bank::deposite_money() {
    int a;
    cout << "\n============================= DEPOSIT MONEY ==============================\n";
    cout << "Enter how much money you want to deposit: ";
    while (!(cin >> a) || a <= 0) {
        cout << "Invalid amount. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    balance += a;
    cout << "Your new balance is: " << balance << endl;
}

void bank::withdraw_money() {
    cout << "\n============================ WITHDRAW MONEY ==============================\n";
    cout << "Enter the amount you want to withdraw: ";
    while (!(cin >> amount) || amount <= 0 || amount > balance) {
        if (amount <= 0) {
            cout << "Invalid amount. Please enter a positive number: ";
        } else {
            cout << "Insufficient funds. Your current balance is: " << balance << ". Enter a smaller amount: ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    balance -= amount;
    cout << "Your new balance is: " << balance << endl;
}

void bank::display_account() {
    cout << "\n============================== DISPLAY ACCOUNT ===========================\n";
    cout << "Name: " << name << endl;
    cout << "Address: " << add << endl;
    cout << "Account Type: " << y << endl;
    cout << "Balance: " << balance << endl;
}

void display_menu() {
    cout << "\n============================== BANK SYSTEM ==============================\n";
    cout << "01) Open account \n";
    cout << "02) Deposit money \n";
    cout << "03) Withdraw money \n";
    cout << "04) Display account\n";
    cout << "05) Exit\n";
    cout << "Please select an option from above: ";
}

int main() {
    int ch, x;
    bank obj;
    do {
        system("cls");
        display_menu();
        cin >> ch;

        switch (ch) {
            case 1:
                obj.open_account();
                break;
            case 2:
                obj.deposite_money();
                break;
            case 3:
                obj.withdraw_money();
                break;
            case 4:
                obj.display_account();
                break;
            case 5:
                cout << "Exiting... Goodbye!\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }

        cout << "\nDo you want to select another option? Press 'y' for yes, 'N' for exit: ";
        x = getch();
        if (x == 'n' || x == 'N')
            cout << "Exiting... Goodbye!\n";
    } while (x == 'y' || x == 'Y');

    getch();
    return 0;
}


