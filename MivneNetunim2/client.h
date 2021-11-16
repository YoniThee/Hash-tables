#pragma once
#include<string>
#include"HashTable.h"
#include"item.h"
#include<list>
#include"volunteer.h"

class client
{
public:
	//-------property--------
	string Name;
	int phone;
	string address;
	list<string> Helped_volunteer;

	//-----------------constractor & destractor-------------------
	client();
	~client() {};


	//--------------operators-------------------
	friend istream& operator >>(istream& a, client& v);
	friend ostream& operator <<(ostream& a, client& v);
	bool operator==(client r2);
	void operator=(const client& c);


	//------------------hash table of client---------------------

	class HashClient : public HashTbls<client, int>
	{
	public:
		HashClient() : HashTbls() {};
		HashClient(int size) : HashTbls(size) {};
		int h1(int key) override;
		int h2(int key) override;
	};
};