#ifndef _CBASE_DATA_H_
#define _CBASE_DATA_H_

#include <queue>
#include "BaseType.h"

using namespace std;

namespace ven_name {

enum INS_STATUS { INS = 0, TO_EXP, TO_INS, EXP, UNKOWN };

class CWaveData {
public:
	/* if in INS status ins = 0 */
	int ins;
	int press;
	int flow;
};

class CBaseData {
private:
	CWaveData last_element;
	queue<CWaveData> wave_queue;
	INS_STATUS status;

public:
	CBaseData(){ status = UNKOWN; };
	void pushWaveData(const CWaveData &);
	int popWaveData(CWaveData &);
	void clearWaveData();
	CWaveData getLastElement();
	INS_STATUS getStatus();
	
};


}


#endif
