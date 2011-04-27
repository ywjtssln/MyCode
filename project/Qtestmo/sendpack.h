#ifndef _SEND_PACK_H
#define _SEND_PACK_H

#include <QString>
#include "event.h"

using namespace tesmo_name;

class SendPackage {
public:
	QString name;
	unsigned int id;
	unsigned int num;
	unsigned int interval_ms;
	L_CBYTE_INFO l_info;

	SendPackage();
	SendPackage(unsigned int);
	SendPackage(const QString &);

};

#endif
