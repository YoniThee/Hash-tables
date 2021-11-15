#include "volunteer.h"
#include<math.h>
#include<iostream>
using namespace std;
void volunteer::print()
{
	cout << "volunteer name: " << Name << endl;
	cout << "adress: " << address << "," << city << endl;
	cout << "phone: " << phone << endl;
}

volunteer::volunteer()
{
	Name = "";
	address = "";
	city = "";
	phone = 0;
}

void volunteer::operator=(const volunteer& v)
{
	
	Name = v.Name;
	address = v.address;
	city = v.city;
	phone = v.phone;


}

bool volunteer::operator==(volunteer v)
{
	if (v.Name.compare(Name) != 0)
		return true;
	else
		return false;
}

int volunteer::findNumForH2(int size)
{
	int temp = int(sqrt(double(size)));
	return temp;

}


istream& operator>>(istream& a, volunteer& v)
{
	cout << "Enter volunteer name phone address\n";
	a >> v.Name;
	a >> v.phone;
	a >> v.address;
	return a;
}

ostream& operator<<(ostream& a, volunteer& v)
{
	a << "Name = " << v.Name << endl << "adress = " << v.address << "city = " << v.city << endl << "Phone = " << v.phone << endl;
	return a;
}

int volunteer::HashVolunteer::h1(string key)
{
	int k = int(key[0]);
	k -= 97;
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
