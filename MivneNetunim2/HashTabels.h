#pragma once
#include<iostream>
#include"Client.h"
#include"Volunteer.h"
#include"HashTable.h"
#include"Item.h"


using namespace std;

class HashTabels{
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

	void addVolunteer(volunteer v) {

	}
	void delVolunteer(volunteer v);
	void addClient(client c);
	void addVolunteerToClient(volunteer v, client c);
	void listOfVolunteers(client c);
	void listOfClients(volunteer v);
};


