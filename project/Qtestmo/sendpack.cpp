#include <string>
#include "sendpack.h"


SendPackage::SendPackage(unsigned int id)
{
	name = "Package ";
	name += id;
}

SendPackage::SendPackage(const string &n)
{
	name = n;
}
