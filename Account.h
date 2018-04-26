/*
	Name: Zaid Khoury
	04/27/2017
	CS-236 Project 2
	Description: this is the Parent class that all the other classes will inheret from. This class declares the necessary variables and arrays and defines
	the methods for the Account.cpp file.
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account{
private:
	string name;
	long taxID;
	double balance;
protected:
	double last10withdraws[10];
	double last10deposits[10];
	int numDeposits;
	int numWithdraws;
public:
	Account();
	Account(string nam, long id, double bal);
	void setName(string nam);
	void setTaxID(long id);
	void setBalance(double bal);
	string getName();
	long getTaxID();
	double getBalance();
	void makeDeposit(double amount);
	int getNumWithdraws();
	void display();
	int checkString(string s);
};
#endif 