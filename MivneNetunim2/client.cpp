#include "client.h"
#include <iostream>

client::client()
{
	Name = "";
	phone_number = 0;
	address = "";


	
}



istream& operator>>(istream& a, client& v)
{
	cout << "Enter Name, Phone number and address\n";
	a >> v.Name;
	a >> v.phone_number;
	a >> v.address;
}

ostream& operator<<(ostream& a, client& v)
{
	a <<"Name = "<< v.Name << endl <<"Phone = "<< v.phone_number << endl <<"adress = "<< v.address << endl;
}



