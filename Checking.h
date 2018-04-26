/*
	Name: Zaid Khoury
	04/27/2017
	CS-236 Project 2
	Description: This class inherets from Account and declares its own variable and defines its own methods for the Checking.cpp file.
*/

#ifndef CHECKING_H
#define CHECKING_H
#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

class Checking : public Account {

private:
	int last10checks[10];
public:
	Checking();
	Checking(string nam, long id, double bal);
	void writeCheck(int chckNum, double Amount); // withdraw
	void display();

};
#endif