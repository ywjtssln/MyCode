#include <QtGui>
#include <iostream>
#include "tesmo.h"

CTesmo::CTesmo()
{
	setStyleSheet("QToolBar { background: green}");

	QDockWidget *dc1 = new QDockWidget(tr("sender"),this);
	QDockWidget *dc2= new QDockWidget(tr("receiver"),this);
	tool_bar_down = new QToolBar(this);
	tool_bar = new QToolBar(this);


	dock_list1= new QListWidget(dc1);
	dock_list2= new QListWidget(dc2);
	central_win = new CentralWin();


	dc1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea |
			Qt::BottomDockWidgetArea);
	
	dc2->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea |
			Qt::BottomDockWidgetArea);

	tool_bar->setAllowedAreas(Qt::LeftToolBarArea);
	tool_bar->setMovable(false);
	tool_bar->setFixedWidth(80);


	tool_bar_down->setAllowedAreas(Qt::BottomToolBarArea);
	tool_bar_down->setMovable(false);
	tool_bar_down->setFixedHeight(30);
//	tool_bar_down->setStyleSheet("QToolBar { background: green}");

	addToolBar(Qt::BottomToolBarArea, tool_bar_down);
	addToolBar(Qt::LeftToolBarArea, tool_bar);

	
	dc1->setWidget(dock_list1);
	dc2->setWidget(dock_list2);

	addDockWidget(Qt::RightDockWidgetArea, dc1);
	addDockWidget(Qt::RightDockWidgetArea, dc2);

	dock_list1->setStyleSheet("QWidget { background: red }");
	dock_list2->setStyleSheet("QWidget { background: yellow }");



	setGeometry(100, 100, 400, 300);


	setCentralWidget(central_win);

	setWindowTitle(tr("Tesmo!!")); 
	resize(800, 500);
	
};

