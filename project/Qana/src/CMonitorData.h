#ifndef CMONITOR_DATA_H_
#define CMONITOR_DATA_H_

#include <bitset>
#include <deque>
#include "CBaseData.h"
#include "BaseType.h"

namespace ven_name {

typedef bitset<10> BIT10;

enum STATUS_BIT { 
	VT_STATUS_BIT = 0, O2_STATUS_BIT,
	FREQ_STATUS_BIT, IE_STATUS_BIT,
	PEEP_STATUS_BIT, PIP_STATUS_BIT,
	PPLAT_STATUS_BIT, CST_STATUS_BIT,
	RAW_STATUS_BIT, VE_STATUS_BIT,
};

class CMonitorData : public CBaseData {
private:
	UINT vt;
	UINT o2;
	UINT freq;
	float ins;
	float exp;
	int peep;
	deque <int> peep_tmp;
	int pip;
	int pip_tmp;
	int pplat;
	int cst;
	float raw;
	float ve;
	BIT10 bit_status;

	void update_peep();
	void update_pip();
	void update_pplat();

public:
	CMonitorData():CBaseData() {};
	void setVT(UINT);
	void setO2(UINT);
	void setFreq(UINT);
	void setIns(float);
	void setExp(float);

	/* other members don't need explicitly setting. */
	void update_cst();
	void update_raw();
	void update_ve();

	UINT getVT();
	UINT getO2();
	UINT getFreq();
	float getIns();
	float getExp();
	int getPeep();
	int getPip();
	int getPplat();
	int getCst();
	int getRaw();
	int getVe();

	bool test();
	bool test(STATUS_BIT);
	void clear();
	void clear(STATUS_BIT);
	void pushWaveData(const CWaveData &cdata);

};

}

#endif

