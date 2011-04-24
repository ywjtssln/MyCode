#ifndef _CENTRAL_WIN_H
#define _CENTRAL_WIN_H

#include <QtGui>
#include "toolbarwin.h"
#include "toolbutton.h"


class CentralWin : public QStackedWidget {
	Q_OBJECT
private:

#if 0
	SendPage *sendp;
	ListenPage *listenp;
	SettingPage *settingp;
	HelpPage *helpp;
#endif 
public:
	CentralWin();

};



#endif
