#ifndef _EVENT_H_
#define _EVENT_H_

#include <list>
#include <vector>

using namespace std;


namespace tesmo_name {

class CByteInfo;
class CEMethod;

typedef unsigned char BYTE;
typedef void * METHOD_INFO;
typedef list <CByteInfo> L_CBYTE_INFO;
typedef list <CEMethod *> L_CEMETHOD;
typedef vector <BYTE> V_BYTE;

enum METHOD_ID { METHOD_STATIC = 0, METHOD_STEP, METHOD_SUM };

enum OVERFLOW_FLAG { OVERFLOW_LOOP, OVERFLOW_STOP };

enum RETURN_VALUE { RETURN_PARA_ERROR = -2, RETURN_ERROR, RETURN_OK, 
	RETURN_OVERFLOW };



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
	int step;
	OVERFLOW_FLAG flag;
};

/* use to define sum method info */
class CSumMethod {
public:
	int sum_start;
	int sum_stop;

};

/* use to init relatived info */
class CByteInfo {
public:
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
