#include "volunteer.h"
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
