/* This file is the header of event.cpp */
/* 2011.4.22 V1.0 by zy */

/* In order to use libtesmo.so, we have to include "event.h", and using name */
/* space tesmo_name. Please pay attention to the class CByteInfo and the mem */
/* bers in it, that's enough for you to create a new class CEPackage.  */

#if 0
this is an example: 

#include "event.h"

using namespace tesmo_name;

int main(int argc, char **argv){

	V_BYTE byte;
	L_CBYTE_INFO info;
	CStaticMethod sta = { 0x55 };
	CStaticMethod stb = { 0xaa };
	CStepMethod stp = { 0x10, 0xaa, 3, OVERFLOW_LOOP };
	CSumMethod sum = { 0, 2 };
	CByteInfo c0= { 0x12, METHOD_STATIC, (void *)&sta};
	CByteInfo c1= { 0x10, METHOD_STEP, (void *)&stb};
	CByteInfo c2= { 0x10, METHOD_STEP, (void *)&stp};
	CByteInfo c3= { 0x78, METHOD_SUM, (void *)&sum};

	info.push_back(c0);
	info.push_back(c1);
	info.push_back(c2);
	info.push_back(c3);

	CEPackage cp(info);
	cp.get(byte);

	......use byte ......

#endif

#ifndef _EVENT_H_
#define _EVENT_H_

#include <list>
#include <vector>

using namespace std;


namespace tesmo_name {

class CByteInfo;
class CEMethod;

/* 8bit as a byte */
typedef unsigned char BYTE;
/* force to other class for information */
typedef void * METHOD_INFO;
/* be used to init CEPackage */
typedef list <CByteInfo> L_CBYTE_INFO;
/* be used within CEPackage, can be skipped */
typedef list <CEMethod *> L_CEMETHOD;
/* vector of byte */
typedef vector <BYTE> V_BYTE;

/* if here has some more method, first change here. */
enum METHOD_ID { METHOD_STATIC = 0, METHOD_STEP, METHOD_SUM };

/* be used for METHOD_STEP. */
enum OVERFLOW_FLAG { OVERFLOW_LOOP = 0, OVERFLOW_STOP };


/* use to define static method info */
class CStaticMethod {
public:
	BYTE static_byte;
};

/* use to define step method info */
class CStepMethod {
public:
	BYTE step_start;
	BYTE step_stop;
	/* step > 0  means to add step */
	/* step < 0  means to subtract step */
	int step;
	OVERFLOW_FLAG flag;
};

/* use to define sum method info */
class CSumMethod {
public:
	/* byte begin with pos 0 */
	int sum_start;
	/* stop pos is used for sum too. */
	int sum_stop;

};

/* use to init relatived info */
class CByteInfo {
public:
	/* Initiation of each byte. use fuction "next()" change values. */
	BYTE byte;
	METHOD_ID id;
	METHOD_INFO info; 
};


class CEMethod {
public:
	METHOD_ID id;

	CEMethod();
	CEMethod(METHOD_ID mid);
	virtual void next(V_BYTE &, V_BYTE::size_type){};
	virtual void reset(V_BYTE &, V_BYTE::size_type){};
};


class CEStaticMethod : public CEMethod {
private:
	BYTE static_dat;
public:
	CEStaticMethod();
	CEStaticMethod(BYTE dat);
	CEStaticMethod(const CStaticMethod &);
	CEStaticMethod(const CStaticMethod *);

	virtual void next(V_BYTE &, V_BYTE::size_type);
	virtual void reset(V_BYTE &, V_BYTE::size_type);

};

class CEStepMethod : public CEMethod {
private:
	bool sign;
	BYTE step_start;
	BYTE step_stop;
	BYTE step;
	OVERFLOW_FLAG flag;
public:
	CEStepMethod();
	CEStepMethod(BYTE , BYTE , int, OVERFLOW_FLAG = OVERFLOW_STOP);
	CEStepMethod(const CStepMethod &);
	CEStepMethod(const CStepMethod *);
	/* we suppose the first value within step_start and step_stop. */
	virtual void next(V_BYTE &, V_BYTE::size_type);
	virtual void reset(V_BYTE &, V_BYTE::size_type);

};

class CESumMethod : public CEMethod {
private:
	unsigned int sum_start;
	unsigned int sum_stop;
public:
	CESumMethod();
	CESumMethod(int ,int);
	CESumMethod(const CSumMethod &);
	CESumMethod(const CSumMethod *);
	virtual void next(V_BYTE &, V_BYTE::size_type);
	virtual void reset(V_BYTE &, V_BYTE::size_type);

};



class CEPackage {
private:
	V_BYTE v_byte;
	L_CEMETHOD l_method;

public:

	CEPackage() {};
	CEPackage(L_CBYTE_INFO &);
	~CEPackage();

	void addInfo(L_CBYTE_INFO::const_iterator);
	void get(V_BYTE &);
	void next();
	void reset(V_BYTE &);

};

}

#endif
