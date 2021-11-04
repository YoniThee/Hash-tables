#include "HashTbls.h"
#include"volunteer.h"
#include"client.h"
#include <string>
class AllTabels : public HashTbls<class T,class K>
{
	HashTbls<volunteer,string>arrVolunteer();
	HashTbls<volunteer, string>arrClient();
};