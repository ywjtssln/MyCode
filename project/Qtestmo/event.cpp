#include <iostream>
#include <vector>
#include <list>
#include "event.h"

using namespace std;
using namespace tesmo_name;


CEMethod::CEMethod()
{
	id = METHOD_STATIC;
}


CEMethod::CEMethod(METHOD_ID mid)
{
	id = mid;
}

CEStaticMethod::CEStaticMethod() : CEMethod(METHOD_STATIC)
{
	static_dat = 0;
}

CEStaticMethod::CEStaticMethod(BYTE dat) : CEMethod(METHOD_STATIC)
{
	static_dat = dat;
}

CEStaticMethod::CEStaticMethod(const CStaticMethod &m) : CEMethod(METHOD_STATIC)
{
	static_dat = m.static_byte;
}

CEStaticMethod::CEStaticMethod(const CStaticMethod *m) : CEMethod(METHOD_STATIC)
{
	static_dat = m->static_byte;
}

void CEStaticMethod::next(V_BYTE &b, V_BYTE::size_type pos)
{
	b[pos] = static_dat;
}
	
void CEStaticMethod::reset(V_BYTE &b, V_BYTE::size_type pos)
{
	b[pos] = static_dat;
}

CEStepMethod::CEStepMethod(BYTE start, BYTE stop, int st, OVERFLOW_FLAG f) : CEMethod(METHOD_STEP)
{
	step_start = start;
	step_stop = stop;
	sign = (st >= 0) ? 1 : 0;
	step = st & 0xff;
	flag = f;
}

CEStepMethod::CEStepMethod(const CStepMethod &m) : CEMethod(METHOD_STEP)
{
	step_start = m.step_start;
	step_stop = m.step_stop;
	sign = (m.step >= 0) ? 1 : 0;
	step = m.step & 0xff;
	flag = m.flag;
}

CEStepMethod::CEStepMethod(const CStepMethod *m) : CEMethod(METHOD_STEP)
{
	step_start = m->step_start;
	step_stop = m->step_stop;
	sign = (m->step >= 0) ? 1 : 0;
	step = m->step & 0xff;
	flag = m->flag;
}


void CEStepMethod::next(V_BYTE &b, V_BYTE::size_type pos)
{
	/* TODO: think about overflow. */

	int tmp = sign ? (b[pos] + step) : (b[pos] - step);

	switch(flag){
		case OVERFLOW_LOOP :
			tmp = (tmp > step_stop) ? step_start : tmp;
			tmp = (tmp < step_start) ? step_stop : tmp;
			break;
		case OVERFLOW_STOP:
			tmp = (tmp > step_stop) ? step_stop : tmp;
			tmp = (tmp < step_start) ? step_start : tmp;
			break;
	}

	b[pos] = tmp;

}

void CEStepMethod::reset(V_BYTE &b, V_BYTE::size_type pos)
{
	b[pos] = step_start;
}


CESumMethod::CESumMethod(int start, int stop) : CEMethod(METHOD_SUM)
{
	sum_start = start;
	sum_stop = stop;
}

CESumMethod::CESumMethod(const CSumMethod &m) : CEMethod(METHOD_SUM)
{
	sum_start = m.sum_start;
	sum_stop = m.sum_stop;
}

CESumMethod::CESumMethod(const CSumMethod *m) : CEMethod(METHOD_SUM)
{
	sum_start = m->sum_start;
	sum_stop = m->sum_stop;
}

void CESumMethod::next(V_BYTE &b, V_BYTE::size_type pos)
{
	BYTE tmp = 0;
	int i = sum_start;

	for(; i <= sum_stop; i++)
		tmp += b[i];

	b[pos] = tmp;
}

void CESumMethod::reset(V_BYTE &b, V_BYTE::size_type pos)
{
	b[pos] = 0;
}

CEPackage::CEPackage(L_CBYTE_INFO &info)
{

	for(L_CBYTE_INFO::iterator iter = info.begin() ;iter != info.end() ; ++iter)
		addInfo(iter);

}

CEPackage::~CEPackage()
{

	for(L_CEMETHOD::iterator iter = l_method.begin(); iter != l_method.end(); ++iter)
		delete *iter;

	l_method.clear();
	v_byte.clear();

}

void CEPackage::addInfo(L_CBYTE_INFO::const_iterator iter)
{
	CEMethod *cem;

	v_byte.push_back(iter->byte);

	switch(iter->id){
		case METHOD_STATIC:
			cem = new CEStaticMethod( (CStaticMethod *) (iter->info) );
			break;
		case METHOD_STEP:
			cem = new CEStepMethod( (CStepMethod *) (iter->info) );
			break;
		case METHOD_SUM:
			cem = new CESumMethod( (CSumMethod *) (iter->info) );
			cem->next(v_byte, v_byte.size() - 1);
			break;
	}

	cout<<"get byte "<<(void *)v_byte.back()<<endl;
	
	l_method.push_back(cem);


}


void CEPackage::get(V_BYTE &v)
{
	v = v_byte;
}

void CEPackage::next()
{
	V_BYTE::size_type pos = 0;

	for(L_CEMETHOD::iterator iter = l_method.begin(); iter != l_method.end(); ++iter)
		(*iter)->next(v_byte, pos++);
}

void CEPackage::reset(V_BYTE &v)
{
	V_BYTE::size_type pos = 0;

	for(L_CEMETHOD::iterator iter = l_method.begin(); iter != l_method.end(); ++iter)
		(*iter)->reset(v_byte, pos++);

	v = v_byte;
}

