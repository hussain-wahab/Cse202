// Hussain Alabdrabalnabi
// HW-03

#include <iostream>
#include <vector>
using namespace std;


class Person
{
private:

string name;
string address;
string telephoneNumber;
string email;

public:

Person(){}


Person(string na, string add, string telephone, string em)
{
name = na;
address = add;
telephoneNumber = telephone;
email = em;
}

void setName(string na)
{
name = na;
}


void setAddress(string add)
{
address = add;
}

void setTelephoneNumber(string tel)
{
telephoneNumber = tel;
}


void setEmail(string em)
{
email = em;
}

string getName()
{
return name;
}


string getAddress()
{
return address;
}

string getTelephoneNumber()
{
return telephoneNumber;
}


string getEmail()
{
return email;
}

virtual string whatami()
{
return "Person";
}

virtual void show()
{
cout<<"\n Name: "<<name<<"\n Address: "<<address<<"\n Telephone Number: "<<telephoneNumber
<<"\n E-mail: "<<email;
}
};

class Student : virtual public Person
{
private:

string status;

public:

Student(){}


Student(string name, string address, string telephoneNumber, string email, string status)

:Person(name, address, telephoneNumber, email)
{
this->status = status;
}


string getStatus()
{
return status;
}


string whatami()
{
return "Student";
}


void show()
{

Person::show();
cout<<"\n Status: "<<status;
}
};

class Employee : virtual public Person
{
private:

string office;
double salary;
string dateHired;

public:

Employee(){}


Employee(string na, string address, string telephoneNumber, string email,
string office, double salary, string dateHired)

: Person(na, address, telephoneNumber, email)
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
string whatami()
{
return "Employee";
}

void show()
{

Person::show();
cout<<"\n Office: "<<office<<"\n Salary: $"<<salary<<"\n Date Hired: "<<dateHired;
}
};


class Faculty : public Employee
{
private:

string rank;
string status;

public:

Faculty(){}


Faculty(string name, string address, string telephoneNumber, string email,
string office, double salary, string dateHired, string rank, string status)

: Employee(name, address, telephoneNumber, email, office, salary, dateHired)
{
Person::setName(name);
Person::setAddress(address);
Person::setTelephoneNumber(telephoneNumber);
Person::setEmail(email);
cout<<"\n Name: "<<this->getName();
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


string whatami()
{
return "Faculty";
}


void show()
{

Employee::show();
cout<<"\n Rank: "<<rank<<"\n Status: "<<status;
}
};


class Staff : public Employee
{
private:

string position;

public:

Staff(){}


Staff(string name, string address, string telephoneNumber, string email, string office,
double salary, string dateHired, string position)

:Employee(name, address, telephoneNumber, email, office, salary, dateHired)
{
Person::setName(name);
Person::setAddress(address);
Person::setTelephoneNumber(telephoneNumber);
Person::setEmail(email);
this->position = position;
}

string getPosition()
{
return position;
}


string whatami()
{
return "Staff";
}


void show()
{

Employee::show();
cout<<"\n Position: "<<position;
}
};


class StaffST : public Staff, public Student
{
private:

int credithours;
public:


StaffST(string name, string address, string telephoneNumber, string email,
string office, double salary, string dateHired, string position,
string status, int credithours)

:Staff(name, address, telephoneNumber, email, office, salary, dateHired, position)
{
this -> credithours = credithours;
}


int getCreditHours()
{
return credithours;
}


string whatami()
{
return "StaffSt";
}


void show()
{

Staff::show();
cout<<"\n Credit Hours: "<<credithours;
}
};


int main()
{

vector <Person*>v;


v.push_back(new Person("hussain Alabdrabalnabi","7922 DayCreek Blvd, Rancho Cucamonga.","(551)221-9699","husssainwahab3@gmail.com"));


v.push_back(new Student("Manvi Sahu","Boston","617-555-0000","johnq@adams.com","senior"));

v.push_back(new Employee("Tanvi Sahu","6465 street no 2,NYC","987564543","johnsmith@email.com",
"office No 1",5465.00,"January 14,2009"));


v.push_back(new Staff("Sasmita Sahu","Boston","617-555-BEER","sam@adams.com",
"brewhouse 1",1000,"9-15-1764","Brewer"));


v.push_back(new Faculty("Bishnu Prasad","Boston","617-555-BEER","sam@adams.com",
"brewhouse 1",1000,"9-15-1764","Professor", "C"));


v.push_back(new StaffST("Pyari Mohan","Boston","617-555-BEER","samsmith@adams.com",
"brewhouse 5",1000.56,"9-15-1774","Taster", "junior", 12));


for(int i = 0; i < v.size(); i++)
{

cout<<endl<<v[i]->whatami();

v[i]->show();
cout<<endl;
}
}
