//Hussain Alabdrabalnabi
// Lab-07
// Class.cpp

#include<iostream>

#include<fstream>

#include<vector>

#include<string>

using namespace std;

class Person   
{
private:
string name;
string address;
string telNum;
string email;
  
public:
Person(){}
Person(string name,string address,string telNum,string email)
{
this->name = name ;
this->address = address;
this->telNum = telNum;
this->email = email;
}
  
string getName()
{
return name;
}
string getAddress()
{
return address;
}
string getTelNum()
{
return telNum;
}
string getEmail()
{
return email;
}
  
};

class Student :public Person
{
private:
string status;
  
public:
Student(){}
  
Student(string name,string address,string telNum,string email,string status):Person(name,address,telNum,email)
{
this->status = status;
}
string getStatus()
{
return status;
}
  
};

class Employee :public Person
{
private:
string office;
double salary;
string dateHired;
  
public:
Employee(){}
  
Employee(string name,string address,string telNum,string email,string office,double salary,string dateHired):Person(name,address,telNum,email)
{
this->office = office;
this->salary = salary;
this->dateHired = dateHired;
}
string getOffice()
{
return office;
}
double getSalary()
{
return salary;
}
string getDateHired()
{
return dateHired;
}
};

class Faculty :public Employee
{
private:
string rank;
string status;
  
public:
Faculty(){}
  
Faculty(string name,string address,string telNum,string email,string office,double salary,string dateHired,string rank,string status):Employee(name,address,telNum,email,office,salary,dateHired)
{
this->rank =rank;
this->status = status;
}
string getRank()
{
return rank;
}
string getStatus()
{
return status;
}
  
  
};

class Staff : public Employee
{
private :
string position;
  
  
public:
Staff(){}
Staff(string name,string address,string telNum,string email,string office,double salary,string dateHired,string position):Employee(name,address,telNum,email,office,salary,dateHired)
{
this->position = position;
}
string getPosition()
{
return position;
}
  
};

int main()
{
Person person1("Hussain Alabdrabalnabi","25082 prospect ave , Loma Linda","9096747375","Hussainwahab3@gmail.com");
cout<<"Person Address : "<<person1.getAddress();
  
Student student1(person1.getName(),person1.getAddress(),person1.getTelNum(),person1.getEmail(),"sophomore");
cout<<"\nStudent Name : "<<student1.getName();
  
Employee employee1(person1.getName(),person1.getAddress(),person1.getTelNum(),person1.getEmail(),"Build office",2000.00,"March 14,19");
cout<<"\nEmployee telephone : "<<employee1.getTelNum();
  
Staff
 staff1("jb-359",person1.getAddress(),person1.getTelNum(),"staff@gmail.com",employee1.getAddress(),employee1.getSalary(),employee1.getDateHired(),"assistant");
cout<<"\nStaff address: "<<staff1.getOffice();
cout<<"\nStaff email : "<<staff1.getEmail();
cout<<"\nStaff office : "<<staff1.getName();
cout<<"\nStaff dateHired : "<<staff1.getDateHired();


Faculty faculty1(person1.getName(),person1.getAddress(),person1.getTelNum(),person1.getEmail(),employee1.getAddress(),employee1.getSalary(),employee1.getDateHired(),staff1.getPosition(),"tenured");
  
cout<<"\nFaculty Name : "<<faculty1.getName()<<"\nAddress : "<<faculty1.getAddress()<<"\nStatus : "<<faculty1.getStatus();
  
cout<<"\nSalary : "<<faculty1.getSalary();
return 0;
}
