#include <QString>
#include <QVariant>
#include "sendpack.h"


SendPackage::SendPackage()
{
	name = "Package ";
	id = 0;
	num = 0;
	interval_ms = 0;
}

SendPackage::SendPackage(unsigned int d)
{
	name = "Package ";
	name = name + QVariant(d).toString();
	id = d;
	num = 0;
	interval_ms = 0;
}

SendPackage::SendPackage(const QString &n)
{
	name = n;
}
