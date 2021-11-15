#pragma once
#include<iostream>
#include"client.h"
#include"volunteer.h"
#include"HashTable.h"
#include"item.h"


using namespace std;

class HashTabels {
public:

	client::HashClient* clients;
	volunteer::HashVolunteer* volunteers;

	HashTabels() {
		clients = new client::HashClient(100);
		volunteers = new volunteer::HashVolunteer(100);
	}
	HashTabels(int size) {
		clients = new client::HashClient(size);
		volunteers = new volunteer::HashVolunteer(size);
	};

	void addVolunteer(volunteer v);
	void delVolunteer(volunteer v);
	void addClient(client c);
	void addVolunteerToClient(volunteer& v, client& c);
	void listOfVolunteers(client c);
	void listOfClients(volunteer v);
};



void HashTabels::addVolunteer(volunteer v)
{
	volunteers->add(v.Name, v);
}

void HashTabels::delVolunteer(volunteer v)
{
	volunteers->del(v.Name, v);
}

void HashTabels::addClient(client c)
{
	clients->add(c.phone, c);
}
void HashTabels::addVolunteerToClient(volunteer& v, client& c)
{
	bool v_Name = false, c_Phone = false;
	int index = clients->search(c.phone);
	if (index == -1) {
		cout << "ERROR"<<endl;
	}
	else
	{		
		list<string>::iterator iter = c.Helped_volunteer.begin();
		for (iter; iter != c.Helped_volunteer.end(); iter++)
		{
			if (*iter == v.Name)
			{
				v_Name = true;
			}
		}
		if (v_Name == false)
		{
			c.Helped_volunteer.push_back(v.Name);
		}
		list<int>::iterator itera = v.Used_client.begin();
		for (itera; itera != v.Used_client.end(); itera++)
		{
			if (*itera == c.phone)
			{
				c_Phone = true;
			}
		}
		if (c_Phone == false)
		{
			v.Used_client.push_back(c.phone);
		}

	}






}

void HashTabels::listOfClients(volunteer v)
{
	cout<< "The clients that were helped by volunteer " << v.Name<<": ";
	list<int>::iterator iter = v.Used_client.begin();
	for (iter; iter != v.Used_client.end(); iter++) {
		cout << *iter<<" ";
	}
}

void HashTabels::listOfVolunteers(client c)
{
	cout << "The volunteers that helped to client "<<c.phone<<": ";
	list<string>::iterator iter = c.Helped_volunteer.begin();
	for (iter; iter != c.Helped_volunteer.end(); iter++) {
		cout << *iter<<" ";
	}
}
/*n
a
s
d
1
n
b
v
r
2
n
c
r
t
3
c
d
22
c
l
a
22
l
b
22
l
c
22

*/