#include "client.h"
#include <iostream>

client::client()
{
	Name = "";
	phone = 0;
	address = "";



}

bool client::operator==(client c2)
{
	if ((this->Name == c2.Name) && (this->phone == c2.phone) && (this->address == c2.address))
	{
		return true;
	}
	return false;
}

void client::operator=(const client& c)
{
	Name = c.Name;
	phone = c.phone;
	address = c.address;
	Helped_volunteer = c.Helped_volunteer;
}

istream& operator>>(istream& a, client& v)
{
	cout << "please enter name and phone and address of client\n";
	a >> v.Name;
	a >> v.phone;
	a >> v.address;
	return a;
}

ostream& operator<<(ostream& a, client& v)
{
	a << "Name = " << v.Name << ", " << "Phone = " << v.phone << ", " << "adress = " << v.address << endl;
	return a;
}

int client::HashClient::h1(int key)
{
	//hash function, find the free cell dy order % size of the table

	int i = key % size;
	return i;
}
int client::HashClient::h2(int key)
{
	//another hash function, if h1 found a full place in the table h2 will help to search for the next free place
	//we learnd that the best case for h2 hash is to find prime number and make this operation
	while (!isPrime(key)) {
		key--;
	}
	int ans = key - (size % key);
	return ans;
}

