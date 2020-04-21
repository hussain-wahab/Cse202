// Hussain Alabdrabalnabi
// Lab-08
// PasswordFile.cpp

#include"PasswordFile.h"
#include<fstream>

	PasswordFile::PasswordFile(string fname)

	{


	ifstream in;

	in.open(fname);

	filename = fname;


	string str;

	while (!in.eof())

	{

	in >> str;

	user.push_back(str);

	in >> str;

	password.push_back(str);

	}

	in.close();

	}

	void PasswordFile::addpw(string u, string p) 

	{


	ofstream out;

	out.open(filename);

	user.push_back(u);

	password.push_back(p);

	if (!out)

	{

	cout << "Not able to open "<<filename<<" for writing" << endl;

	return;

	}

	for (int i = 0; i < user.size(); i++)

	{

	out << user[i]<< " " << password[i] << endl;

	}

	out.close();

	}

	void PasswordFile::delpw(string u) 

	{

	ofstream out;

	out.open(filename);

	int pos = -1;
	if (!out)
	{

	cout << "Not able to open " << filename << " for writing" << endl;
	return;

	}

	for (int i = 0; i < user.size(); i++)
	{
  	 if (user[i] == u)
   	{
    	pos = i;
   	}
	}

	user.erase(user.begin()+pos);
	password.erase(password.begin()+pos);

	for (int j = 0; j < user.size(); j++)
	{
	out << user[j] << " " << password[j] << endl;
	}
	out.close();

	}

	bool PasswordFile::checkpw(string u, string p) 

	{

	for (int i = 0; i < user.size(); i++)

	{

	if (user[i] == u && password[i] == p)

	{

	return true;

	}

	}

	return false;

	}
