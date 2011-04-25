#ifndef _SEND_SET_H_
#define _SEND_SET_H_

#include <QtGui>

class SendSet : public QWidget {
	Q_OBJECT
private:
	QGridLayout *hl;
	QGroupBox *gb_radio;
	QButtonGroup *bg_radio;
	QLineEdit *le_name;
	QSpinBox *sb_lenth;
	QSpinBox *sb_interval;
	QRadioButton *rb_static;
	QRadioButton *rb_step;
	QRadioButton *rb_sum;

public:
	SendSet();

};


#endif
