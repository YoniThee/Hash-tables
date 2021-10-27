#pragma once
#include<string>
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
	volunteer& operator=(const volunteer &v);
	bool operator==(volunteer v);
};