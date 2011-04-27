#include <QtGui>
#include <iostream>
#include "tesmo.h"

CTesmo::CTesmo()
{
	dock = new QDockWidget(tr("Send Watch"),this);
	tool_bar = new QToolBar(this);

	send = new QAction(tr("send"), this);
	listen = new QAction(tr("listen"), this);
	setting = new QAction(tr("setting"), this);
	help = new QAction(tr("help"), this);

	send_list= new QListWidget();
	listen_list= new QListWidget();
	central_win = new CentralWin();

	send_list->setMinimumWidth(300);
	listen_list->setMinimumWidth(300);

	setStyleSheet("QToolBar { background: yellow }");

	tool_bar->addAction(send);
	tool_bar->addAction(listen);
	tool_bar->addAction(setting);
	tool_bar->addAction(help);

	dock->setAllowedAreas(Qt::AllDockWidgetAreas);
	
	tool_bar->setAllowedAreas(Qt::LeftToolBarArea);
	tool_bar->setMovable(false);
	tool_bar->setFixedWidth(80);

	addToolBar(Qt::LeftToolBarArea, tool_bar);
	
	dock->setWidget(send_list);
	dock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);

	addDockWidget(Qt::RightDockWidgetArea, dock);

	connect(send, SIGNAL(triggered()), central_win, SLOT(setSendPage()));
	connect(send, SIGNAL(triggered()), this, SLOT(topSendDock()));
	connect(listen, SIGNAL(triggered()), central_win, SLOT(setListenPage()));
	connect(listen, SIGNAL(triggered()), this, SLOT(topListenDock()));
	connect(setting, SIGNAL(triggered()), central_win, SLOT(setSettingPage()));
	connect(help, SIGNAL(triggered()), central_win, SLOT(setHelpPage()));

	setGeometry(100, 100, 800, 500);


	setCentralWidget(central_win);

	setWindowTitle(tr("Tesmo!!")); 
	
}

void CTesmo::topSendDock()
{
	dock->setWidget(send_list);
	dock->setWindowTitle("Send Watch");
}


void CTesmo::topListenDock()
{
	dock->setWidget(listen_list);
	dock->setWindowTitle("Listen Watch");
}

