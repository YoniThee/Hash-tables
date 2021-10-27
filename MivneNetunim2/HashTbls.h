#pragma once
#include"item.h"
template <class T, class K>
class HashTbls {
	HashTbls();
	~HashTbls()
	{

	}
	virtual Item<T, K>* h1(Item k) = 0;
	virtual Item<T, K>* h2(Item k) = 0;

};