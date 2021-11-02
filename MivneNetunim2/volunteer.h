#pragma once
#include<string>
#include"HashTbls.h"
#include"item.h"
using namespace std;
class volunteer {
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
	
	class HashVolunteer : public HashTbls<volunteer,string> {
		Item<volunteer, string>* h1(volunteer key);
		HashTbls<volunteer, string> addVolunteer(volunteer v);
	};
};