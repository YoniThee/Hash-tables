#pragma once
#include"item.h"
#include<string>
#include<iostream>
using namespace std;
template <typename T, typename K>
class HashTbls 
{


public:
	enum state {empty, full, deleted};
	bool isPrime(int num);
	HashTbls<T, K>();
	HashTbls<T, K>(int m); //counstructor build new hash table at prime number size - bigger of the input size		
	~HashTbls()
	{
		delete[] arr;
	}


		int size;
		Item<T, K>* arr = NULL;



		int hash(T k, int num) {
			int temp = 0;
			for (int i = 0; i < num; i++)//looking for the index
			{
				temp += h2();
			}

			return temp;//return the index
		}
		/*
		void addVolunteer(volunteer v)
		{
			this->add(v.name, v);
		};
		void addClient(client c)
		{
			this->add(c.phone, c);
		};
		virtual void delVolunteer(volunteer v)
		{
			this->del(v.name, v);
		};*/
		void print();
		int search(K k);

		void add(K I, T k);
		void del(K I, T k);


		virtual int h1(K k) =0;
		virtual int h2(K k) =0;

		friend class HashTabels;
	
};

//template<class T, class K>
//inline void HashTbls<T, K>::addVolunteerToClient(T v, K c)
template<typename T, typename K>
bool HashTbls<T,K>::isPrime(int num)
{
	for (int i = 2; i < num; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

template<typename T,typename K>
HashTbls<T, K>::HashTbls() : size(0), arr(NULL) {}


template <typename T, typename K>
HashTbls<T, K>::HashTbls(int mySize) {
	while (!isPrime(mySize))//if the number isn't prime check the next
	{
		mySize++;
	}	
	arr = new Item<T, K>[mySize];
}

//template<typename T, typename K>
//int HashTbls<T, K>::hash(T k, int num)




template<typename T, typename K>
inline void HashTbls<T, K>::print()
{
	for (int i = 0; i < this->arr.size; i++)
	{
		if (arr[i].Special_arr != empty)
		{
			cout << arr[i] << endl;
		}
	}
}

template<class T, class K>
inline int HashTbls<T, K>::search(K k)
{
	for (int i = 0; i < arr.size; i++)
	{
		if (arr[i].K == k)
		{
			return arr[i];
		}

	}
	return -1;
}

template<class T, class K>
inline void HashTbls<T, K>::add(K k, T t)
{
	int i =h1(k), index;
	index = hash(k, i);
	while (arr[index].flag == full)
	{
		i++;
		int temp = (h1(k) + i * h2(k)) % size;
		index = hash(k,temp);
	}
	arr[index] = t;
	arr[index].flag = full;


}

template<class T, class K>
inline void HashTbls<T, K>::del(K k, T t)
{
	for (int i = 0; i < arr.size; i++)
	{
		if (arr[i].K == k)
		{
			arr[i].flag = deleted;
			T temp = new T;
			arr[i] = temp;
		}
	}

}

 