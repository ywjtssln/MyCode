#include <algorithm>
#include <iostream>
#include "CMonitorData.h"

using namespace ven_name;


void CMonitorData::setVT(UINT tmp_vt)
{
	if(tmp_vt != vt){
		vt = tmp_vt;
		bit_status.set(VT_STATUS_BIT);
	}
}

void CMonitorData::setO2(UINT tmp_o2)
{
	if(tmp_o2 != o2){
		o2 = tmp_o2;
		bit_status.set(O2_STATUS_BIT);
	}
}

void CMonitorData::setFreq(UINT tmp_freq)
{
	if(tmp_freq != freq){
		freq = tmp_freq;
		bit_status.set(FREQ_STATUS_BIT);
	}
}

void CMonitorData::setIns(float tmp_ins)
{
	if(tmp_ins != ins){
		ins = tmp_ins;
		bit_status.set(IE_STATUS_BIT);
	}
}

void CMonitorData::setExp(float tmp_exp)
{
	if(tmp_exp != exp){
		exp = tmp_exp;
		bit_status.set(IE_STATUS_BIT);
	}
}


UINT CMonitorData::getVT()
{
	return vt;
}

UINT CMonitorData::getO2()
{
	return o2;
}

UINT CMonitorData::getFreq()
{
	return freq;
}

float CMonitorData::getIns()
{
	return ins;
}

float CMonitorData::getExp()
{
	return exp;
}

int CMonitorData::getPeep()
{
	return peep;
}

int CMonitorData::getPip()
{
	return pip;
}

int CMonitorData::getPplat()
{
	return pplat;
}

int CMonitorData::getCst()
{
	return cst;
}

int CMonitorData::getRaw()
{
	return raw;
}

int CMonitorData::getVe()
{
	return ve;
}

bool CMonitorData::test()
{
	return bit_status.any();
}

bool CMonitorData::test(STATUS_BIT bit_tmp)
{
	return bit_status.test(bit_tmp);
}

void CMonitorData::clear()
{
	bit_status.reset();
}

void CMonitorData::clear(STATUS_BIT bit_tmp)
{
	bit_status.reset(bit_tmp);
}

void CMonitorData::update_peep()
{
	int p = 0;
	deque <int>::iterator iter; 

	for(iter = peep_tmp.begin(); iter != peep_tmp.end(); ++iter)
		p += *iter;

	p = p / peep_tmp.size();
	if(p != peep){
		bit_status.set(PEEP_STATUS_BIT);
		peep = p;
	}
}

void CMonitorData::update_pip()
{
	if(pip != pip_tmp){
		bit_status.set(PIP_STATUS_BIT);
		pip = pip_tmp;
	}
	pip_tmp = 0;
}

void CMonitorData::update_pplat()
{
	CWaveData t = getLastElement();
	if(pplat != t.press){
		bit_status.set(PPLAT_STATUS_BIT);
		pplat = t.press;
	}
}

void CMonitorData::update_cst()
{
	int t = vt / (pip - peep);

	if(cst != t){
		bit_status.set(CST_STATUS_BIT);
		cst = t;
	}

}

void CMonitorData::update_raw()
{
	float t = pip * freq * (ins + exp) / (vt * ins * 60);

	if(raw != t){
		bit_status.set(RAW_STATUS_BIT);
		raw = t;
	}

}

void CMonitorData::update_ve()
{
	float t = vt * freq * 0.001;

	if(ve != t){
		bit_status.set(VE_STATUS_BIT);
		ve = t;
	}

}

/* Reload. Add new CWaveData to queue, and update the related bit.*/
void CMonitorData::pushWaveData(const CWaveData &cdata)
{
	CBaseData::pushWaveData(cdata);
	
	pip_tmp = pip_tmp < cdata.press ? cdata.press : pip_tmp;

	peep_tmp.push_back(cdata.press);
	while(peep_tmp.size() > 4)
		peep_tmp.pop_front();
	
	if(getStatus() == TO_EXP)
		update_pplat();
	
	if(getStatus() == TO_INS){
		update_peep();
		update_pip();
	}

}
