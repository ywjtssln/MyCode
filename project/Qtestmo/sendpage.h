#ifndef _SEND_PAGE_H_
#define _SEND_PAGE_H_

#include <iostream>
#include <vector>
#include <QtGui>
#include "sendset.h"
#include "sendpack.h"

using namespace std;

class SendPage : public QSplitter{
	Q_OBJECT
private:
	QListWidget *send_list;
	SendSet *send_set;
	vector <SendPackage> sendpack_vec;

private slots:
	void currentPackageChanged(QListWidgetItem *);
	void addPackageRow();
	void delPackageRow();
	void savePackageInfo(SendPackage &);

public:
	SendPage();

};

#endif
