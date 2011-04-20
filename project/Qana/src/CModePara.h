#ifndef _CMODE_PARA_H_
#define _CMODE_PARA_H_

namespace ven_name {

typedef vector <UBYTE>::iterator ITER_UBYTE;

class CIPPV {
public:
	UINT vt;
	UINT freq;
	/* 吸气平台 */
	float p_plat;
	float ins;
	float exp;
	int press_h;
	int peep;
	int sigh;
};

class CModeIPPV : public CIPPV {
private:

public:
	CModeIPPV() {};
	CModeIPPV(CIPPV &c) : CIPPV(c);




	



};



}



#endif
