#ifndef _SEND_PAGE_H_
#define _SEND_PAGE_H_
#include <QtGui>
#include "sendset.h"

class SendPage : public QSplitter{
	Q_OBJECT
private:
	QListWidget *send_list;
	SendSet *send_set;

public:
	SendPage();

};


#endif
