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
	//template <class T, class K>
	HashTbls(int size) {//counstructor build new hash table at prime number size - bigger of the input size		
		while (!isPrime(size))//if the number isn't prime check the next
		{
			size++;
		}
		Item<T,K> hashTable[size];
	}
	~HashTbls()
	{

	}
	int size;
	Item* arr;

	//void addVolunteerToClient(T v, K c);
	

	int hash(T k, int num);
	virtual void addVolunteer(Item k) = 0;
	virtual void addClient(Item k) = 0;
	virtual void delVolunteer(Item v) = 0;
	void print(T t);



	virtual Item<T, K>* h1(Item k) = 0;
	virtual Item<T, K>* h2(Item k) = 0;
};

//template<class T, class K>
//inline void HashTbls<T, K>::addVolunteerToClient(T v, K c)



template<class T, class K>
inline int HashTbls<T, K>::hash(T k, int num)
{
	int temp = 0;
	for (int i = 0; i < num; i++)//looking for the index
	{
		temp += h2();
	}
	
	return temp;//return the index
}

template<class T, class K>
inline void HashTbls<T, K>::addVolunteer(T k)
{
	int temp = h1(k.name);
	ht[temp] = k;
}

template<class T, class K>
inline void HashTbls<T, K>::del(T v)
{
	int temp = h1(k.name);
	ht[temp] = 0;
}

template<class T, class K>
inline void HashTbls<T, K>::print(T t)
{
	for (int i = 0; i < t.size; i++)
	{
		cout << t[i] << endl;
	}
}

 