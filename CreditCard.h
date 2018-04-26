/*
	Name: Zaid Khoury
	04/27/2017
	CS-236 Project 2
	Description: This class inherets from Account and declares its own variable and defines its own methods for the CreditCard.cpp file.
*/

#ifndef CREDITCARD_H
#define CREDITCARD_H
#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

class CreditCard : public Account {

private:
	long cardNumber;
	string last10charges[10];
public:
	CreditCard();
	CreditCard(string nam, long id, double bal);
	void doCharge(string name, double amount);
	void makePayment(double amount); // deposit
	void display();
};
#endif