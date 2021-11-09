#pragma once
#include"item.h"
template <class T, class K>
class HashTbls {



public:
	enum state { empty, full, deleted };
	bool isPrime(int num) {
		for (int i = 2; i < num; i++) {
			if (num % i == 0)
				return false;
		}
		return true;
	}
	//template <class T, class K>
	HashTbls(int size = 100) {//counstructor build new hash table at prime number size - bigger of the input size		
		while (!isPrime(size))//if the number isn't prime check the next
		{
			size++;
		}
		arr = Item<T, K> hashTable[size];
	}
	~HashTbls()
	{
		delete arr;
	}
	int size;
	Item* arr;



	int hash(T k, int num);
	void addVolunteer(volunteer v)
	{
		this->add(v.name, v);
	};
	void addClient(Client c)
	{
		this->add(c.phone, c);
	};
	virtual void delVolunteer(volunteer v)
	{
		this->del(v.name, v);
	};
	void print();
	int search(K k);

	void add(K I, T k);
	void del(K I, T k);


	virtual Item<T, K>* h1(Item k) {};
	virtual Item<T, K>* h2(Item k) {};
};





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
	int i, index;
	index = hash(k, i);
	while (arr[index].flag == full)
	{
		index = hash(k, ++i);
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

 