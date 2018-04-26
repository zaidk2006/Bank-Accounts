/*
	Name: Zaid Khoury
	04/27/2017
	CS-236 Project 2
	Description: This class inherets from Account and defines its own methods for the Savings.cpp file.
*/


#ifndef SAVINGS_H
#define SAVINGS_H
#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

class Savings : public Account {

public:
	Savings();
	Savings(string nam, long id, double bal);
	void doWithdraw(double amount);
	void display();

};
#endif