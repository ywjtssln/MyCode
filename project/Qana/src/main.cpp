#include <iostream>
#include "CMonitorData.h"

using namespace ven_name; 
using namespace std; 

int main(int argc, char **argv){
	CMonitorData data;
	CWaveData wavedat[5] = {
		{0, 30, 40},
		{0, 32, 50},
		{0, 90, 30},
		{1, 35, 50},
		{0, 30, 80},
	};
	CWaveData wavetmp;
	int t = 0;

	

	cout<<"hope to see this...."<<endl;
	while(t < 5){
		wavetmp = wavedat[t];
		cout<<"push ins = "<<wavetmp.ins<<" press = "<<wavetmp.press<<" flow = "<<wavetmp.flow<<endl;
		data.pushWaveData(wavedat[t]);
		t++;
	}

	while(t > 0){
		t = data.popWaveData(wavetmp);
		cout<<"pop ins = "<<wavetmp.ins<<" press = "<<wavetmp.press<<" flow = "<<wavetmp.flow<<endl;
	}

	return 0;
}
