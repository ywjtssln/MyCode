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
	QListWidget *dock_list1;
	QListWidget *dock_list2;
	QToolBar *tool_bar;
	QToolBar *tool_bar_down;
	CentralWin *central_win;

public:
	CTesmo();
};


#endif
