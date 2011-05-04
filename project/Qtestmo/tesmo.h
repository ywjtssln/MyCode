#ifndef _TESMO_H_
#define _TESMO_H_

#include <QtGui>
#include "centralwin.h"

class MyToolbutton : public QToolButton {
public:
	MyToolbutton();
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

	QPushButton *play_pause;
	QPushButton *stop;
	QAction *send;
	QAction *listen;
	QAction *setting;
	QAction *help;

private slots:
	void topListenDock(); 
	void topSendDock(); 
	void nextPackage();
	void resetPackage();

public:
	CTesmo();
};


#endif
