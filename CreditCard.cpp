/*
	Name: Zaid Khoury
	04/27/2017
	CS-236 Project 2
	Description: this class includes the source code for the methods defined in the CreditCard.h file. The methods and variables in this class 
	are unique to the CreditCard Class only. Only this class has access to the methods defined in the CreditCard.h
*/


#include "CreditCard.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;

CreditCard::CreditCard(){
	setName("Bob");
	setTaxID(123456789);
	setBalance(100);
}


CreditCard::CreditCard(string nam, long id, double bal){
	setName(nam);
	setTaxID(id);
	setBalance(bal);
}

void CreditCard::doCharge(string name, double amount){
	if(amount > 999999){
		cout << "Amount too high!" << endl;
	}else{
		setBalance((getBalance() + amount));
		last10charges[numWithdraws] = name;
		last10withdraws[numWithdraws] = amount;
		numWithdraws++;
	}
}

void CreditCard::makePayment(double amount){
	int c;
	if(getBalance() == 0){
		cout << "You do not have any balance!\n" << endl;
	}else{
		while(amount > getBalance()){
			cout << "Your payment is higher than the amount you owe. Would you like to pay off your balance";
			cout << " of: $" << getBalance() << "?" << endl;
			cout << "Press 0: NO, Cancel Payment" << endl;
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
				amount = getBalance();
			}else{
				cout << "Invalid Entry" << endl;
			}
		}
		if(amount == 0){
		}else{
			setBalance((getBalance() - amount));
			last10deposits[numDeposits] = amount;
			numDeposits++;
		}
	}
}

void CreditCard::display(){
	cout << "Name: " << getName();
	cout << "\tTax ID: " << getTaxID() << endl;;
	cout << "------------------------------------------------------------------" << endl;
	cout << numWithdraws << " charges were made." << endl;
	for(int i = 0; i < numWithdraws; i++){
		cout << (i+1) << ") " << "Charge name: " << last10charges[i] << "\t\tCharge amount: $" << last10withdraws[i] << endl;
	}
	cout << endl;
	cout << numDeposits << " payments were made." << endl;
	for(int i = 0; i < numDeposits; i++){
		cout << (i+1) << ") " << "Payment amount: $" << last10deposits[i] << endl;
	}
	cout << endl;
}
