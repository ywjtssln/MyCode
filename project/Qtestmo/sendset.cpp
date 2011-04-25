#include "sendset.h"

SendSet::SendSet()
{
	QLabel *lname = new QLabel(tr("Name"));
	QLabel *llenth = new QLabel(tr("Lenth"));
	QLabel *linterval = new QLabel(tr("Interval"));
	hl = new QGridLayout;
	le_name = new QLineEdit;
	sb_lenth = new QSpinBox();
	sb_interval = new QSpinBox;
	//bg_radio = new QButtonGroup;
	gb_radio = new QGroupBox(tr("method"));
	rb_static = new QRadioButton("static");
	rb_step = new QRadioButton("step");
	rb_sum = new QRadioButton("sum");
	QVBoxLayout *vl = new QVBoxLayout;

	rb_static->setChecked(true);

	vl->addWidget(rb_static);
	vl->addWidget(rb_step);
	vl->addWidget(rb_sum);

	vl->addStretch(1);
	gb_radio->setLayout(vl);

	sb_lenth->setRange(0, 100);
	sb_interval->setRange(0, 2000);
	sb_interval->setSingleStep(10);

	hl->addWidget(lname, 0, 0, 1, 1);
	hl->addWidget(le_name, 0, 1, 1, 8);
	hl->addWidget(llenth, 1, 0, 1, 1);
	hl->addWidget(sb_lenth, 1, 1);
	hl->addWidget(linterval, 1, 2, 1, 1);
	hl->addWidget(sb_interval, 1, 3);
	hl->addWidget(gb_radio, 2, 0);

	setLayout(hl);

}
