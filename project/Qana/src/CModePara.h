#ifndef _CMODE_PARA_H_
#define _CMODE_PARA_H_

namespace ven_name {

typedef vector <UBYTE>::iterator ITER_UBYTE;
typedef bitset<7> BIT7;
enum GET_PARA { LAST = -1, SELF, NEXT };

class CIPPV {
public:
	UINT vt;
	UINT freq;
	/* 吸气平台 */
	float p_plat;
	int ie;
	int press_h;
	int peep;
	int sigh;
};

class CModeIPPV : public CIPPV {
private:
	UINT vt_step;
	UINT freq_step;
	float p_plat_step;
	int ie_step;
	int press_h_step;
	int peep_step;
	int sigh_step;
	BIT7 bit_status;
	vector <UBYTE> package[8];
	

public:
	CModeIPPV() {};
	CModeIPPV(CIPPV &c) : CIPPV(c);
	ITER_UBYTE pack();
	UINT getVt(GET_PARA &);
	UINT getFreq(GET_PARA &);
	float getPplat(GET_PARA &);
	vector <string>::iterator getIe(GET_PARA &);
	int getPressh(GET_PARA &);
	int getPeep(GET_PARA &);
	int getSigh(GET_PARA &);


};



}



#endif
