#ifndef _TESMO_H_
#define _TESMO_H_

#include <QtGui>
#include "centralwin.h"

class Mytoolbutton :public QToolButton {
public:
	Mytoolbutton();
};

class CTesmo : public QMainWindow {
	Q_OBJECT
private:
	QListWidget *send_list;
	QListWidget *listen_list;
	QDockWidget *dock;
	QToolBar *tool_bar;
	QToolBar *tool_bar_down;
	CentralWin *central_win;

	QAction *send;
	QAction *listen;
	QAction *setting;
	QAction *help;

private slots:
	void topListenDock(); 
	void topSendDock(); 


public:
	CTesmo();
};


#endif
