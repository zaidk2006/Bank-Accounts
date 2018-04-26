/*
	Name: Zaid Khoury
	04/27/2017
	CS-236 Project 2
	Description: The main class instantiates a Checking object, a Savings object, and a CreditCard object. The user will see a menu with different
	options on it and the program functions as the user wishes with the use of a do-while loop and switch statements. There are error checking for
	bad values for every option and the program will not function until a good input is entered.
*/

#include <iostream>
#include <array>
#include <string>
#include "Account.h"
#include "Checking.h"
#include "CreditCard.h"
#include "Savings.h"

using namespace std;

int main(){
	int choice;
	double amount;
	int checkNum;
	long id;
	string chargeName;
	string name;

	Checking c;
	Savings s;
	CreditCard b;

	//cout << "Checking Account Name: ";
	//cin >> name;
	//c.setName(name);
	//cout << "Savings Account Name: ";
	//cin >> name;
	//s.setName(name);
	//cout << "Credit Card Account Name: ";
	//cin >> name;
	//b.setName(name);

	do{
		cout << "Checking Balance: $" << c.getBalance();
		cout << "\tSavings Balance: $" << s.getBalance();
		cout << "\tCredit Card Balance: $" << b.getBalance() << endl;
		cout << endl;
		cout << "1. Savings Deposit" << endl;
		cout << "2. Savings Withdrawel" << endl;
		cout << "3. Checking Deposit" << endl;
		cout << "4. Write A Check" << endl;
		cout << "5. Credit Card Payment" << endl;
		cout << "6. Make A Charge" << endl;
		cout << "7. Display Savings" << endl;
		cout << "8. Display Checking" << endl;
		cout << "9. Display Credit Card" << endl;
		cout << "0. Exit" << endl;
		cin >> choice;

		while(cin.fail()){
			cout << "Invalid Entry, Try again!\n" << endl;
			cin.clear();
			cin.ignore(256,'\n');
			cout << "Checking Balance: $" << c.getBalance();
			cout << "\tSavings Balance: $" << s.getBalance();
			cout << "\tCredit Card Balance: $" << b.getBalance() << endl;
			cout << endl;
			cout << "1. Savings Deposit" << endl;
			cout << "2. Savings Withdrawel" << endl;
			cout << "3. Checking Deposit" << endl;
			cout << "4. Write A Check" << endl;
			cout << "5. Credit Card Payment" << endl;
			cout << "6. Make A Charge" << endl;
			cout << "7. Display Savings" << endl;
			cout << "8. Display Checking" << endl;
			cout << "9. Display Credit Card" << endl;
			cout << "0. Exit" << endl;
			cin >> choice;
		}

		switch(choice){
		case 1: 
			cout << "Enter deposit amount: ";
			cin >> amount;
			while(cin.fail()){
				cout << "Invalid Entry, Enter another deposit amount: ";
				cin.clear();
				cin.ignore(256,'\n');
				cin >> amount;
			}
			s.makeDeposit(amount);
			break;
		case 2:
			cout << "Enter withdrawel amount: ";
			cin >> amount;
			while(cin.fail()){
				cout << "Invalid Entry, Enter another withdrawel amount: ";
				cin.clear();
				cin.ignore(256,'\n');
				cin >> amount;
			}
			s.doWithdraw(amount);
			break;
		case 3: 
			cout << "Enter deposit amount: ";
			cin >> amount;
			while(cin.fail()){
				cout << "Invalid Entry, Enter another deposit amount: ";
				cin.clear();
				cin.ignore(256,'\n');
				cin >> amount;
			}
			c.makeDeposit(amount);
			break;
		case 4: 
			cout << "Enter check number: ";
			cin >> checkNum;
			while(cin.fail()){
				cout << "Invalid Entry, Enter another check number: ";
				cin.clear();
				cin.ignore(256,'\n');
				cin >> checkNum;
			}
			cout << "Enter check amount: ";
			cin >> amount;
			while(cin.fail()){
				cout << "Invalid Entry, Enter another check amount: ";
				cin.clear();
				cin.ignore(256,'\n');
				cin >> amount;
			}
			c.writeCheck(checkNum, amount);
			break;
		case 5: 
			cout << "Enter payment amount: ";
			cin >> amount;
			while(cin.fail()){
				cout << "Invalid Entry, Enter another payment amount: " << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> amount;
			}
			b.makePayment(amount);
			break;
		case 6: 
			cout << "Enter charge name: ";
			cin >> chargeName;
			cout << "Enter charge amount: ";
			cin >> amount;
			while(cin.fail()){
				cout << "Invalid Entry, Enter another charge amount: " << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> amount;
			}
			b.doCharge(chargeName, amount);
			break;
		case 7: 
			cout << "**SAVINGS SUMMARY**" << endl;
			s.display();
			break;
		case 8:
			cout << "**CHECKING SUMMARY**" << endl;
			c.display();
			break;
		case 9: 
			cout << "**CREDIT CARD SUMMARY**" << endl;
			b.display();
			break;
		default:
			cout << "Invalid Entry! Try again\n" << endl;
			break;
		}


	}while(choice != 0);


	return 0;
}