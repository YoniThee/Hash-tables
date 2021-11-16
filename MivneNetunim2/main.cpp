/*
Author: # Yehonatan Thee 209016393 && Shay Dopelt 208737981
description: the program is get details about volunteers and clients in the organization, and puts each of the data in
the right place by implementing hashing function
*/
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
		//all loop is crate new show of the client or volunteer
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
		case 'p':;
		case 'e':cout << "bye "; break;
		//case 'p': 
		default: cout << "Error ";  break;
		}
	} while (ch != 'e');


	return 0;
}
/*
EXMPLE:
Hash Tables

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
n
Enter volunteer name phone address
avraham 123 haifa

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
n
Enter volunteer name phone address
isaac 234 afula

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
n
Enter volunteer name phone address
yaacov 345 natania

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
c
please enter name and phone and address of client
reuven 1234 haifa

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
c
please enter name and phone and address of client
shimon 2345 jerusalem

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
c
please enter name and phone and address of client
levi 3456 afula

*/