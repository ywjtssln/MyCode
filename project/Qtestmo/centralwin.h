#ifndef _CENTRAL_WIN_H
#define _CENTRAL_WIN_H

#include <QtGui>
#include "toolbarwin.h"
#include "toolbutton.h"
#include "sendpage.h"
#include "listenpage.h"
#include "settingpage.h"
#include "helppage.h"


class CentralWin : public QStackedWidget {
	Q_OBJECT
private:
	SendPage *sendp;
	ListenPage *listenp;
	SettingPage *settingp;
	HelpPage *helpp;

private slots:
	void setSendPage();  
	void setListenPage();
	void setSettingPage();  
	void setHelpPage(); 

public:
	CentralWin();

};



#endif
