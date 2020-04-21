//Hussain Alabdrabalnabi
// Lab-08
// main.cpp

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "PasswordFile.h"

using namespace std;

int main()
{
	string filename = "password.txt";
	PasswordFile passfile(filename.c_str());
	string input = "";
	cout << "To add user enter (1), to delete user enter (2), to find user, press (3), " << endl;
	cout << "to exit, enter (0): " << endl;
	getline(cin, input);
	
	if (input == "1")
	{
		cout << "Enter the name and password you want to enter: " << endl;
		string n, p;
		cout << "Name: ";
		getline(cin, n);
		cout << "Password: ";
		getline(cin, p);
		passfile.addpw(n, p);
	}
	
	if (input == "2")
	{
		cout << "Enter the name you want to delete: " << endl;
		string n;
		cout << "Name: ";
		getline(cin, n);
		passfile.delpw(n);
	}
	
	if (input == "3")
	{
		cout << "Enter the name and password you want to check: " << endl;
		string n, p;
		cout << "Name: ";
		getline(cin, n);
		cout << "Password: ";
		getline(cin, p);
		passfile.checkpw(n, p);
	}
	
	else
	{
		cout << "Exiting program. Goodbye!" << endl;
	}
	
	return 0;
}

