#include <iostream>
#include "CBaseData.h"

using namespace ven_name;

/* Add new CWaveData to queue.*/
void CBaseData::pushWaveData(const CWaveData &cdata)
{
	
	status = (status == UNKOWN) ? INS
		: static_cast<INS_STATUS> (last_element.ins << 1 + cdata.ins);
	
	wave_queue.push(cdata);
	last_element = cdata;

}

/* Pop One CWaveData to cdata, return the number of left elements in queue. */
int CBaseData::popWaveData(CWaveData &cdata)
{
	if(!wave_queue.empty()){
		cdata = wave_queue.front();
		wave_queue.pop();
	}
	return wave_queue.size();
}

void CBaseData::clearWaveData()
{
	queue<CWaveData> t;
	wave_queue = t;
	last_element.ins = INS;
	status = UNKOWN;
}

CWaveData CBaseData::getLastElement()
{
	return last_element;
}

INS_STATUS CBaseData::getStatus()
{
	return status;
}
