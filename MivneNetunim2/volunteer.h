#pragma once
#include<string>
#include<list>
#include"HashTable.h"
#include"client.h"
#include"item.h"

using namespace std;
class volunteer
{
public:
	//-------property--------
	string Name;
	string address;
	int phone;
	void print();
	list<string> Used_client;

	//-----------------constractor & destractor-------------------
	volunteer();
	~volunteer() {}

	//-----------------operators---------------------
	friend istream& operator >>(istream& a, volunteer& v);
	friend ostream& operator <<(ostream& a, volunteer& v);
	void operator=(const volunteer& v);
	bool operator==(volunteer v);
	int findNumForH2(int size);

	//------------------hash table of volunteer---------------------
	class HashVolunteer : public HashTbls<volunteer, string> {
	public:
		int h1(string key) override;
		int h2(string key) override;
		HashVolunteer() : HashTbls() {};
		HashVolunteer(int size) : HashTbls(size) {

		};
	};
};