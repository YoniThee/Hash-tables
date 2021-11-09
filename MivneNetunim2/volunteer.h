#pragma once
#include<string>
#include"HashTable.h"
#include"item.h"

using namespace std;
class volunteer
{
public:
	string name;
	string address;
	string city;
	
	int phone;
	void print();
	volunteer();
	~volunteer() {}
	
	friend istream& operator >>(istream& a, volunteer& v);
	friend ostream& operator <<(ostream& a, volunteer& v);
	volunteer& operator=(const volunteer &v);
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