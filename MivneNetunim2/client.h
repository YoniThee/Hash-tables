#pragma once
#include<string>
#include"HashTable.h"
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

	class HashClient : public HashTbls<client, int>
	{
	public:
		HashClient() : HashTbls() {};
		HashClient(int size) : HashTbls(size) {};
		int h1(int key)override;
		int h2(int key) override;
	};
};