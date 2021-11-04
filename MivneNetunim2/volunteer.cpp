#include "volunteer.h"
#include<math.h>
#include<iostream>
using namespace std;
void volunteer::print()
{
	cout << "volunteer name: " << name << endl;
	cout << "adress: " << address << "," << city << endl;
	cout << "phone: " << phone << endl;
}

volunteer::volunteer()
{
	name = "";
	address = "";
	city = "";
	phone = 0;
}

volunteer& volunteer::operator=(const volunteer& v)
{
	name = v.name;
	address = v.address;
	city = v.city;
	phone = v.phone;
}

bool volunteer::operator==(volunteer v)
{
	if (v.name.compare(name) !=0)
		return true;
	else
		return false;
}

int volunteer::findNumForH2(int size)
{
	int temp = sqrt(double(size));

	
}


istream& operator>>(istream& a, volunteer& v)
{
	cout << "Enter Name, address, city and phone\n";
	a >> v.name;
	a >> v.address;
	a >> v.city;
	a >> v.phone;
}

ostream& operator<<(ostream& a, volunteer& v)
{
	a << "Name = " << v.name << endl << "adress = " << v.address << "city = " << v.city << endl <<"Phone = " << v.phone << endl;
}

int volunteer::HashVolunteer::h1(string key)
{
	int k = int(key[0]);
	int i = k % size;
	return i;
}

int volunteer::HashVolunteer::h2(string key)
{
	int i = ((1 + int(key[0])) % size);
	return i;
}
