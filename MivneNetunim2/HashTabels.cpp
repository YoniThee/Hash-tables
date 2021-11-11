#include"HashTabels.h"



void HashTabels::addClient(client c)
{
	clients->add(c.phone, c);
}
void HashTabels::addVolunteerToClient(volunteer v, client c)
{
}
void HashTabels::listOfVolunteers(client c)
{
	c.Helped_volunteer;
}
void HashTabels::listOfClients(volunteer v)
{
	v.Help_to_client;
}

void HashTabels::addVolunteer(volunteer v)
{
	volunteers->add(v.name, v);
}
void HashTabels::delVolunteer(volunteer v)
{
	volunteers->del(v.name, v);
}