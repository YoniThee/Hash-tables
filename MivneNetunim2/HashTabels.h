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
	//default constructor
	HashTabels()
	{
		clients = new client::HashClient(100);
		volunteers = new volunteer::HashVolunteer(100);
	}
	//cunstrcor by size
	HashTabels(int size) {
		clients = new client::HashClient(size);
		volunteers = new volunteer::HashVolunteer(size);
	};
	//---------realization of hash table function---------------
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
	bool v_Name = false, c_Phone = false, Exists1 = false, Exists2 = false;
	int index = clients->search(c.phone);
	int index2 = volunteers->search(v.Name);

	//we need to check that v and c is exists and that they still not deleted
	if (index == -1|| index2 == -1 || clients->arr[index].flag != full || volunteers->arr[index2].flag!=full) {
		cout << "ERROR"<<endl;
	}
	else
	{	
		c = clients->arr[index].data;
		list<string>::iterator iter = clients->arr[index].data.Helped_volunteer.begin();
		for (iter; iter != clients->arr[index].data.Helped_volunteer.end(); iter++)
		{
			//if the name is in v we dont want to put him for nore time
			if (*iter == v.Name)
			{
				Exists1 = true;
				v_Name = true;
			}
		}
		if (v_Name == false)
		{
			//connect the new volunteer to the list of helped-volunteer of this alient
			clients->arr[index].data.Helped_volunteer.push_back(v.Name);
		}

		v = volunteers->arr[index2].data ;
		list<string>::iterator itera = volunteers->arr[index2].data.Used_client.begin();
		for (itera; itera != volunteers->arr[index2].data.Used_client.end(); itera++)
		{
			//if the name is in c we dont want to put him for nore time
			if (*itera == c.Name)
			{
				Exists2 = true;
				c_Phone = true;
			}
		}
		if (c_Phone == false)
		{
			//connect the new client to the list of used client of this volunteer
			volunteers->arr[index2].data.Used_client.push_back(c.Name);
			
		}
		if (Exists1 == true && Exists2 == true)
		{
			cout << "ERROR" << endl;
		}		
	}

}

void HashTabels::listOfClients(volunteer v)
{
	cout << "The clients that were helped by volunteer " << v.Name << ": ";
	int index = volunteers->search(v.Name);
	//if this volunteer is exists
	if (index != -1) {
	v = volunteers->arr[index].data;
	
		list<string>::iterator iter = volunteers->arr[index].data.Used_client.begin();
		for (iter; iter !=volunteers->arr[index].data.Used_client.end(); iter++) {
			cout << *iter << " ";
		}
	}
}

void HashTabels::listOfVolunteers(client c)
{	
	cout << "The volunteers that helped to client " << c.phone << ": ";
	int index = clients->search(c.phone);
	//if this client is exists
		if (index != -1) {
		c = clients->arr[index].data;
		list<string>::iterator iter = clients->arr[index].data.Helped_volunteer.begin();
		for (iter; iter != clients->arr[index].data.Helped_volunteer.end(); iter++) {
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