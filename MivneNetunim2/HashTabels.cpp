#include"HashTabels.h"
HashTabels::addVolunteer(volunteer v)
{
	volunteers->add(v.name, v);
};
HashTabels::addClient(client c)
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
;
HashTabels::delVolunteer(volunteer v)
{
	voluteers->del(v.name, v);
};