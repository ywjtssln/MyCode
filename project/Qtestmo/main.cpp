/******************************************************************************
** This file may become a super.....bug....
**
** 2011.4.23 V1.0 by zy
**
******************************************************************************/

#include <QtGui>
#include <tesmo.h>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Q_INIT_RESOURCE(test_r);
	CTesmo tesmo;

	tesmo.show();

	return app.exec();
}

