#pragma once
#include<iostream>
#include"Client.h"
#include"Volunteer.h"
#include"HashTable.h"
#include"Item.h"


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
	void addVolunteerToClient(volunteer v, client c);
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
void HashTabels::addVolunteerToClient(volunteer v, client c)
{
	int index = clients->search(c.phone);
	if (index == -1) {
		cout << "ERROR";
	}
	else {
		clients[index].print();
		///*client temp = clients[index];
		//cout << temp;
		c.Helped_volunteer.push_back(v.Name);
		//clients[index] = c;

		//list<string>::iterator iter = clients->arr->data.Helped_volunteer.begin();
		//for (iter; iter != clients->arr->data.Helped_volunteer.end(); iter++)
		//{

		//}
		//clients[index]->*(data.Helped_volunteer.push_back(v.Name));
	}

}

void HashTabels::listOfClients(volunteer v)
{
	list<int>::iterator iter = v.Used_client.begin();
	for (iter; iter != v.Used_client.end(); iter++) {
		cout << *iter;
	}
}

void HashTabels::listOfVolunteers(client c)
{
	list<string>::iterator iter = c.Helped_volunteer.begin();
	for (iter; iter != c.Helped_volunteer.end(); iter++) {
		cout << *iter;
	}
}
/*n
a
s
d
1
c
z
2
c
l
a
2
*/