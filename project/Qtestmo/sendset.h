#ifndef _SEND_SET_H_
#define _SEND_SET_H_

#include <QtGui>
#include "ui_sendset.h"
#include "sendpack.h"

class MyLineEdit :public QLineEdit {
	Q_OBJECT
private:
	int id;
public:
	MyLineEdit(int i, QWidget *w) : QLineEdit(w){ id = i; }

protected: 
signals:
	void focusChanged(int);

protected:
	void focusInEvent(QFocusEvent *);

};

class SendSet : public QWidget , private Ui::SendSet {
	Q_OBJECT
private:
	SendPackage pack_now;
	MyLineEdit *lined[20];
	void updateCurrentPackage();

public:
	explicit SendSet();
	void packageChanged(SendPackage &);
	void isPackage(bool);

public slots:
	void setStatic();
	void setStep();
	void setSum();
	void byteInfoChanged(int);
	void add_clicked();
	void save_clicked();
	void del_clicked();
	void edit_name();
	void edit_lenth();
	void edit_interval();
	void edit_static();
	void edit_step_start();
	void edit_step_step();
	void edit_step_end();
	void edit_sum_start();
	void edit_sum_end();

signals:
	void addPackage();
	void savePackage(SendPackage &);
	void delPackage();

};


#endif
