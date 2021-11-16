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
	int index2 = volunteers->search(v.Name);


	if (index == -1|| index2 == -1) {
		cout << "ERROR"<<endl;
	}
	else
	{	
		c = clients->arr[index].data;
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
		clients->arr[index].data = c;
		for (list<string>::iterator iter = c.Helped_volunteer.begin(); iter != c.Helped_volunteer.end(); iter++) {
			clients->arr[index].data.Helped_volunteer.push_back(*iter);
		}
		//c = clients->arr[index].data ;



		//		clients->add(index,c);

		v = volunteers->arr[index2].data ;
		list<string>::iterator itera = v.Used_client.begin();
		for (itera; itera != v.Used_client.end(); itera++)
		{
			if (*itera == c.Name)
			{
				c_Phone = true;
			}
		}
		if (c_Phone == false)
		{
			v.Used_client.push_back(c.Name);
		}
		volunteers->arr[index2].data = v;
		for (list<string>::iterator iter = v.Used_client.begin(); iter != v.Used_client.end(); iter++) {
			volunteers->arr[index2].data.Used_client.push_back(*iter);
		}

		//volunteers->arr[index2].data = v;

	}

}

void HashTabels::listOfClients(volunteer v)
{
	int index = volunteers->search(v.Name);
	//if this volunteer is exists
	if (index != -1) {
	v = volunteers[index].arr->data;
	//list<string>::iterator iter = volunteers->arr[index].data.Used_client.begin();
	/*while (iter != volunteers->arr[index].data.Used_client.end())
	{
		v.Used_client.push_back(*iter);
	}*/
		
		cout << "The clients that were helped by volunteer " << v.Name << ": ";
		list<string>::iterator itera = volunteers->arr[index].data.Used_client.begin();
		for (itera; itera !=v.Used_client.end(); itera++) {
			cout << *itera << " ";
		}
	}
}

void HashTabels::listOfVolunteers(client c)
{
	int index = clients->search(c.phone);
	//if this client is exists
		if (index != -1) {
		c = clients[index].arr->data;
		cout << "The volunteers that helped to client " << c.phone << ": ";
		list<string>::iterator iter = c.Helped_volunteer.begin();
		for (iter; iter != c.Helped_volunteer.end(); iter++) {
			cout << *iter << " ";
		}
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