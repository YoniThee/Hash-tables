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

void volunteer::operator=( volunteer& v)
{
	//volunteer temp;
	name = v.name;
	address = v.address;
	city = v.city;
	phone = v.phone;
	//return this;
	
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
	double temp = sqrt(double(size));
	return temp;
	
}


istream& operator>>(istream& a, volunteer& v)
{
	cout << "Enter Name, address, city and phone\n";
	a >> v.name;
	a >> v.address;
	a >> v.city;
	a >> v.phone;
	return a;
}

ostream& operator<<(ostream& a, volunteer& v)
{
	a << "Name = " << v.name << endl << "adress = " << v.address << "city = " << v.city << endl <<"Phone = " << v.phone << endl;
	return a;
}

int volunteer::HashVolunteer::h1(string key)
{
	int k = int(key[0]);
	int i = k % size;
	return i;
}

int volunteer::HashVolunteer::h2(string key)
{
	int i = int(key[0]);
	while (!isPrime(i)) {
		i--;
	}
	int ans = i - (size % i);
	return i;
}
