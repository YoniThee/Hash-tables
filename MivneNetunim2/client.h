#pragma once
#include<string>
#include"HashTable.h"
#include"item.h"
#include<list>
#include"volunteer.h"

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
	void operator=(const client& c);

	class HashClient : public HashTbls<client, int>
	{
	public:
		HashClient() : HashTbls() {};
		HashClient(int size) : HashTbls(size) {};
		int h1(int key) override;
		int h2(int key) override;
	};
};