#pragma once
#include<string>
#include"HashTbls.h"
#include"item.h"
#include"volunteer.h"
#include<list>


class client 
{
public:
	string Name;
	int phone;
	string address;
	list<string> Helped_volunteer;
	

	client();
	~client() {};	

	friend istream& operator >>(istream& a, client& v);
	friend ostream& operator <<(ostream& a, client& v);
	bool operator==(client r2);


};