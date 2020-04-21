// Hussain Alabdrabalnabi
// Lab-08
// PasswordFile.h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef PASSWORDFILE_H
#define PASSWORDFILE_H

class PasswordFile
{
public:
   PasswordFile();
   PasswordFile(string filename);// opens the file and reads the names/passwords in the vector entry
   void addpw(string u, string p); //this adds a new user/password to entry and writes entry to the file filename
   void delpw(string u); //this deletes the user u from the password file
   bool checkpw(string u, string p); // returns true if user exists and password matches
private:
   string filename; // the file that contains password information
   vector<string> user; // the list of usernames/passwords
   vector<string> password; // the list of usernames/passwords
};

#endif 

