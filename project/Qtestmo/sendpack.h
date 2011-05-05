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

	vector <BYTE> data_m;
	vector <int> method_m;
	vector <CStaticMethod> static_m;
	vector <CStepMethod> step_m;
	vector <CSumMethod> sum_m;
	L_CBYTE_INFO l_info;

	SendPackage();
	SendPackage(unsigned int);
	void refreshByteInfo();

	void operator = (SendPackage &);

};

#endif
