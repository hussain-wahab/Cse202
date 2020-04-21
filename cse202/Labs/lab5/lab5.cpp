//Hussain Alabdrabalnabi
//Lab-05


#include <cassert>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

string get(string askfor, int numchars);
string get_password(string name);

int main()
{


string name; string pwd; string passwd;
cout << "Address of name =" <<  &name <<"\n";
cout << "Address of pwd =" <<  &pwd <<"\n";
cout << "Address of passwd =" <<  &passwd <<"\n";
string Name="Name";
string Password="Password";

bool authenticated=false;
while(! authenticated)
{


 name = get(Name, 7 );

 passwd = get_password(name);

 pwd= get(Password, 7 );


 authenticated= pwd == passwd;

 if(!authenticated)
  cout << "Please try again\n";
}
cout << "Welcome "<<name<<"\n";


return 0;
}
string get(string askfor, int numchars)
{
string input;

cout << askfor<<"("<<numchars<<" characters): ";
cin>>input;
return input;
}
string get_password(string name)
{



if(name =="botting")
 return "123456";
else if(name =="ernesto")
 return "765432";
else if(name == "tong")
 return "234567";
else
  return "qwert";

};
