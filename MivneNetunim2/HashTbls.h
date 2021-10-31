#pragma once
#include"item.h"
template <class T, class K>
class HashTbls {
public:
	bool isPrime(int num) {
		for (int i = 2; i < num; i++) {
			if (num % i == 0)
				return false;
		}
		return true;
	}
	HashTbls(int size) {//counstructor build new hash table at prime number size - bigger of the input size		
		while (!isPrime(size))//if the number isn't prime check the next
		{
			size++;
		}
		Item<T,k> hashTable[size];
	}
	~HashTbls()
	{

	}
	virtual Item<T, K>* h1(Item k) = 0;
	virtual Item<T, K>* h2(Item k) = 0;


};