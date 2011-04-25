#include "centralwin.h"

CentralWin::CentralWin()
{
	sendp = new SendPage();
	listenp = new ListenPage();
	settingp = new SettingPage();
	helpp = new HelpPage();
	
	addWidget(sendp);
	addWidget(listenp);
	addWidget(settingp);
	addWidget(helpp);

	setCurrentWidget(sendp);

}

void CentralWin::setSendPage()
{
	setCurrentWidget(sendp);
}

void CentralWin::setListenPage()
{
	setCurrentWidget(listenp); 
}

void CentralWin::setSettingPage()
{
	setCurrentWidget(settingp); 
}

void CentralWin::setHelpPage()
{
	setCurrentWidget(helpp); 
}
