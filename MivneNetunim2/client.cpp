#include "client.h"
#include <iostream>

client::client()
{
	Name = "";
	phone = 0;
	address = "";


	
}

bool client::operator==(client c2)
{
	if ((this->Name == c2.Name) && (this->phone == c2.phone) && (this->address == c2.address))
	{
		return true;
	}
	return false;
}

istream& operator>>(istream& a, client& v)
{
	cout << "Enter Name, Phone number and address\n";
	a >> v.Name;
	a >> v.phone;
	a >> v.address;
}

ostream& operator<<(ostream& a, client& v)
{
	a <<"Name = "<< v.Name << endl <<"Phone = "<< v.phone << endl <<"adress = "<< v.address << endl;
}



