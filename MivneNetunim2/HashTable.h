#pragma once
//enum state { empty, full, deleted };
#include"item.h"
#include<string>
#include<iostream>
using namespace std;

template <typename T, typename K>
class HashTbls
{


public:
	//------property-----------
	state flag;
	int size ;
	Item<T, K>* arr = NULL;
	bool isPrime(int num);

	//------constructor & destructor-----------
	HashTbls<T, K>();
	HashTbls<T, K>(int m); //counstructor build new hash table at prime number size - bigger of the input size		
	~HashTbls()
	{
		delete[] arr;
	}

	//----------hashing function-----------
	int hash(K k, int num) {
		int temp = 0;
		for (int i = 0; i < num; i++)//looking for the index
		{
			temp += h1(k);
		}

		return temp;//return the index
	}
	void print();
	int search(K k);
	void add(K I, T k);
	void del(K I, T k);

	//----------virtual functions--------------
	virtual int h1(K k) = 0;
	virtual int h2(K k) = 0;

	friend class HashTabels;

};

template<typename T, typename K>
bool HashTbls<T, K>::isPrime(int num)
{
	//check if num is prime number
	for (int i = 2; i < num; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

template<typename T, typename K>
HashTbls<T, K>::HashTbls() : size(0), arr(NULL) {}


template <typename T, typename K>
HashTbls<T, K>::HashTbls(int mySize)
{
	while (!isPrime(mySize))//if the number isn't prime check the next
	{
		mySize++;
	}
	size = mySize;
	arr = new Item<T, K>[mySize];
}

template<typename T, typename K>
inline void HashTbls<T, K>::print()
{
	for (int i = 0; i < this->size; i++)
	{
		if(this->arr[i].flag == full)
		cout << this->arr[i].key << ": " << this->arr[i].data << endl;

	}
}




template<class T, class K>
inline int HashTbls<T, K>::search(K k)
{
	for (int i = 0; i < this->size; i++)
	{
		if (arr[i].key == k)
		{
			return i;
		}

	}
	return -1;
}

template<class T, class K>
inline void HashTbls<T, K>::add(K k, T t)
{
	//check for free place to add the new item 
	int i = 0, index = h1(k);
	while (this->arr[index].flag == (state)full)
	{
		//Calculation hashing formula
		i++;
		int temp = (h1(k) + i * h2(k)) % size;
		temp -= 97;//if the key is convert from string
		index = hash(k, temp);
	}

	this->arr[index].data = t;
	this->arr[index].key = k;
	this->arr[index].flag = full;
	
}




template<class T, class K>
inline void HashTbls<T, K>::del(K k, T t)
{
	for (int i = 0; i < this->size; i++)
	{
		//chack for the right key, and make sure that we not deleted him yet
		if (arr[i].key == k && arr[i].flag != deleted )
		{
			//delete fun is need to update the index at the table to deleted status 
			arr[i].flag = deleted;
			i = this->size;

		}
		else if (i == this->size-1)
		{
			cout << "ERROR\n";
		}
	}

}
/*
n
a
s
d
1
n
b
n
m
2
n
c
v
b
3
n
d
r
t
8
n
c
x
c
22
l
a
22
l
b
22
l
c
22
l
d
22
*/