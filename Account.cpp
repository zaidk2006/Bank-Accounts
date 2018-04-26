/*
	Name: Zaid Khoury
	04/27/2017
	CS-236 Project 2
	Description: This class has the source code for the methods defined in the Account.h file. The source code that is written here
	is inhereted to the other classes and they all have access to these methods. The methods have error checking for bad input values
	and lets the user know when a bad value is inputted. If a bad value is inputted for a variable, the variable value does not change.
*/

#include "Account.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;


Account::Account(){
	numDeposits = 0;
	numWithdraws = 0;
	setName("Bob");
	setTaxID(123456789);
	setBalance(100);
}

Account::Account(string nam, long id, double bal){
	numDeposits = 0;
	numWithdraws = 0;
	setName(nam);
	setTaxID(id);
	setBalance(bal);
}

void Account::setName(string nam){
	while(checkString(nam) == -1){
		cout << "invalid Entry, Try again: ";
		cin >> nam;
	}
	name = nam;
}

void Account::setTaxID(long id){
	int length = 1;
	int y = id;
	while ( y /= 10 ){
		length++;
	}
	while(length < 7 || length > 9){
		cout << "Invalid Entry, Try again with an ID that is 7-9 numbers long: ";
		cin >> id;
		length = 1;
		while ( y /= 10 ){
			length++;
		}
		cout << "Length: " << length << endl;
	}
	taxID = id;
}

void Account::setBalance(double bal){

	while(bal < 0){
		cout << "Invalid Entry, Enter a value that is not less than 0: ";
		cin >> bal;
	}
	balance = bal;
}

string Account::getName(){
	return name;
}

long Account::getTaxID(){
	return taxID;
}

double Account::getBalance(){
	return balance;
}

void Account::makeDeposit(double amount){
	if(amount > 999999){
		cout << "Amount too high!" << endl;
	}else{
		balance += amount;
		last10deposits[numDeposits] = amount;
		numDeposits++;
	}
}

void Account::display(){
	cout << "Name: " << name << endl;
	cout << "tax ID: " << taxID << endl;
	cout << "Balance: " << balance << endl;
}

int Account::checkString(string s){
	bool x = true;
	for(int i = 0; i < s.length(); i++){
		s[i] = tolower(s[i]);
	}
	for(int i = 0; i < s.length(); i++){
		s[i] = isalpha(s[i]);
	}
	for(int i = 0; i < s.length(); i++){
		if(s[i] ==0){
			x = false;
		}	
	}
	if(x == false){
		return -1;
	}else {
		return 1;
	}
}