/*
	Name: Zaid Khoury
	04/27/2017
	CS-236 Project 2
	Description: this class includes the source code for the methods defined in the Checking.h file. The methods and variables in this class 
	are unique to the Checking Class only. Only this class has access to the methods defined in the Checking.h.
*/

#include "Checking.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;

Checking::Checking(){
	setName("Bob");
	setTaxID(123456789);
	setBalance(100);
}

Checking::Checking(string nam, long id, double bal){
	setName(nam);
	setTaxID(id);
	setBalance(bal);
}

void Checking::writeCheck(int chckNum, double amount){
	int c;
	if(getBalance() == 0){
		cout << "No balance in your Checking account\n" << endl;
	}else{
		while(amount > getBalance()){
			cout << "Insufficient Funds! Do you want to choose another amount?" << endl;
			cout << "Press 0: NO, Cancel Transaction" << endl;
			cout << "Press 1: YES" << endl;
			cin >> c;
			while(cin.fail()){
				cout << "Invalid Entry, Choose either '0' or '1': " << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> c;
			}
			if(c == 0){
				amount = 0;
			}else if(c == 1){
				cout << "Input check amount: ";
				cin >> amount;
			}else{
				cout << "Invalid Entry\n" << endl;
			}
		}
		if(amount == 0){
		}else{
			setBalance((getBalance() - amount));
			last10checks[numWithdraws] = chckNum;
			last10withdraws[numWithdraws] = amount;
			numWithdraws++;
		}
	}
}

void Checking::display(){
	cout << "Name: " << getName();
	cout << "\tTax ID: " << getTaxID() << endl;;
	cout << "------------------------------------------------------------------" << endl;
	cout << numWithdraws << " Checks were written." << endl;
	for(int i = 0; i < numWithdraws; i++){
		cout << (i+1) << ") " "Check Number: " << last10checks[i] << " had an amount of: $" << last10withdraws[i] << endl;	
	}
	cout << endl;
	cout << numDeposits << " Deposits were made." << endl;
	for(int i = 0; i < numDeposits; i++){
		cout << (i+1) << ") " "Deposit: " << (i+1) << " had an amount of: $" << last10deposits[i] << endl;
	}
	cout << endl;
}
