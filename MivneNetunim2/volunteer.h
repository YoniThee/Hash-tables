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
	string Name;
	string address;
	string city;
	int phone;
	void print();
	list<int> Used_client;


	volunteer();
	~volunteer() {}

	friend istream& operator >>(istream& a, volunteer& v);
	friend ostream& operator <<(ostream& a, volunteer& v);
	void operator=(const volunteer& v);
	bool operator==(volunteer v);
	int findNumForH2(int size);

	class HashVolunteer : public HashTbls<volunteer, string> {
	public:
		int h1(string key) override;
		int h2(string key) override;
		HashVolunteer() : HashTbls() {};
		HashVolunteer(int size) : HashTbls(size) {

		};
	};
};