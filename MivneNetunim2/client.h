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
	int phone_number;
	string address;
	list<string> Helped_volunteer;
	

	client();
	~client() {};
	void Add_Helped_volunteer(volunteer v , client c);
	

	friend istream& operator >>(istream& a, client& v);
	friend ostream& operator <<(ostream& a, client& v);



};