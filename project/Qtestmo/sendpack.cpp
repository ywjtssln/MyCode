#include <QString>
#include <QVariant>
#include "sendpack.h"


SendPackage::SendPackage()
{
	name = "Package ";
	id = 0;
	num = 0;
	interval_ms = 0;

	data_m.resize(20);
	method_m.resize(20);
	static_m.resize(20);
	step_m.resize(20);
	sum_m.resize(20);
}

SendPackage::SendPackage(unsigned int d)
{
	name = "Package ";
	name = name + QVariant(d).toString();
	id = d;
	num = 0;
	interval_ms = 0;

	data_m.resize(20);
	method_m.resize(20);
	static_m.resize(20);
	step_m.resize(20);
	sum_m.resize(20);
}

void SendPackage::operator = (SendPackage &pack)
{

	name = pack.name;
	id = pack.id;
	num = pack.num;
	interval_ms = pack.interval_ms;

	data_m = pack.data_m;
	method_m = pack.method_m;
	static_m = pack.static_m;
	step_m = pack.step_m;
	sum_m = pack.sum_m;
	l_info = pack.l_info;

}

void SendPackage::refreshByteInfo()
{
	CByteInfo info = {0, METHOD_STATIC, NULL};

	l_info.clear();

	for(unsigned int i = 0; i != num; ++i)
	{
		info.byte = data_m[i];
		info.id = static_cast<METHOD_ID>(method_m[i]);
		switch(info.id){
			case METHOD_STATIC:
				info.info = (void *) &(static_m[i]);
				break;
			case METHOD_STEP:
				info.info = (void *) &(step_m[i]);
				break;
			case METHOD_SUM:
				info.info = (void *) &(sum_m[i]);
				break;
		}
		l_info.push_back(info);

	}

}
