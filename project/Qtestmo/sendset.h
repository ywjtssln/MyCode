#ifndef _SEND_SET_H_
#define _SEND_SET_H_

#include <QtGui>
#include "ui_sendset.h"
#include "sendpack.h"


class SendSet : public QWidget , private Ui::SendSet {
	Q_OBJECT
private:
	SendPackage pack_now;
	void updateCurrentPackage();

public:
	explicit SendSet();
	void packageChanged(SendPackage &);

public slots:
	void setStatic();
	void setStep();
	void setSum();
	void add_clicked();
	void save_clicked();
	void edit_name();
	void edit_lenth();
	void edit_interval();

signals:
	void addPackage();
	void savePackage(SendPackage &);
};


#endif
