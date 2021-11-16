#include "volunteer.h"
#include<math.h>
#include<iostream>
using namespace std;
void volunteer::print()
{
	cout << "volunteer name: " << Name << endl;
	cout << "adress: " << address << endl;
	cout << "phone: " << phone << endl;
}

volunteer::volunteer()
{
	Name = "";
	address = "";
	phone = 0;
}

void volunteer::operator=(const volunteer& v)
{
	
	Name = v.Name;
	address = v.address;
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
	a << "Name = " << v.Name << ", " << "adress = " << v.address << ", " << "Phone = " << v.phone << endl;
	return a;
}

int volunteer::HashVolunteer::h1(string key)
{
	//hash function, find the free cell dy the abc order % size of the table
	int k = int(key[0]);
	k -= 97;
	int i = k % size;
	return i;
}

int volunteer::HashVolunteer::h2(string key)
{
	//another hash function, if h1 found a full place in the table h2 will helo to search for the next free place
	int i = int(key[0]);
	//we learnd that the best case for h2 hash is to find prime number and make this operation
	while (!isPrime(i)) {
		i--;
	}
	int ans = i - (size % i);
	return i;
}
