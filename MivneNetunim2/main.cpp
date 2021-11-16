#include <iostream>
#include <string>
#include<list>
#include "volunteer.h"
#include "client.h"
#include"HashTabels.h"
#include"HashTable.h"
using namespace std;




int main()
{

	char ch;
	
	list<volunteer*> lst;
	
	//HashTbls<class T,class K> ht(100);
	//HashTbls ht();
	HashTabels ht;


	cout << "Hash Tables\n";
	do
	{
		volunteer v;
		client c;
		cout << "\nChoose one of the following" << endl;
		cout << "n: New volunteer" << endl;
		cout << "d: Del a volunteer " << endl;
		cout << "c: New client" << endl;
		cout << "l: Add a connection volunteer-client " << endl;
		cout << "*: Print volunteers that helped a client " << endl;
		cout << "i: Print clients that were helped by a voluneer " << endl;
		cout << "p: Print hash tables" << endl;
		cout << "e: Exit" << endl;
		cin >> ch;
		switch (ch)
		{
		case 'n':cin >> v; ht.addVolunteer(v);  break;
		case 'd':cout << "enter volunteer name "; cin >> v.Name; ht.delVolunteer(v);  break;
		case 'c': cin >> c; ht.addClient(c); break;
		case 'l': cout << "enter volunteer name and client phone ";  cin >> v.Name >> c.phone; ht.addVolunteerToClient(v, c); break;
		case '*': cout << "enter client phone ";  cin >> c.phone; ht.listOfVolunteers(c); break;
		case 'i': cout << "enter volunteer name ";  cin >> v.Name; ht.listOfClients(v); break;
		case 'p':ht.Print(); break;
		case 'e':cout << "bye "; break;
		default: cout << "Error ";  break;
		}
	} while (ch != 'e');


	return 0;
}

/*
n
a
1
q
n
b
2
e
n
c
3
r
c
d
5
t
c
e
7
j

*/