#include "sendset.h"

SendSet::SendSet()
{
	setupUi(this);

	connect(r_static, SIGNAL(clicked()), this, SLOT(setStatic()));
	connect(r_step, SIGNAL(clicked()), this, SLOT(setStep()));
	connect(r_sum, SIGNAL(clicked()), this, SLOT(setSum()));
	connect(pb_add, SIGNAL(clicked()), this, SLOT(add_clicked()));
	connect(pb_save, SIGNAL(clicked()), this, SLOT(save_clicked()));
	connect(pb_del, SIGNAL(clicked()), this, SLOT(del_clicked()));
	connect(le_name, SIGNAL(editingFinished()), this, SLOT(edit_name()));
	connect(sb_lenth, SIGNAL(valueChanged(int)), this, SLOT(edit_lenth()));
	connect(sb_interval, SIGNAL(valueChanged(int)), this, SLOT(edit_interval()));

	updateCurrentPackage();
	
}

void SendSet::setStatic()
{
	st_set->setCurrentWidget(static_page);
}

void SendSet::setStep()
{
	st_set->setCurrentWidget(step_page);
}

void SendSet::setSum()
{
	st_set->setCurrentWidget(sum_page);
}

void SendSet::add_clicked()
{
	emit addPackage();
}

void SendSet::save_clicked()
{
	emit savePackage(pack_now);
}

void SendSet::del_clicked()
{
	emit delPackage();
}

void SendSet::edit_name()
{
	pack_now.name = le_name->text();

}


void SendSet::edit_lenth()
{
	pack_now.num = sb_lenth->value();

}

void SendSet::edit_interval()
{
	pack_now.interval_ms = sb_interval->value();

}


void SendSet::updateCurrentPackage()
{
	le_name->setText(QString(pack_now.name));
	sb_lenth->setValue(pack_now.num);
	sb_interval->setValue(pack_now.interval_ms);

}

void SendSet::packageChanged(SendPackage &pack)
{
	pack_now = pack;
	updateCurrentPackage();
}

void SendSet::isPackage(bool f)
{
	qDebug()<<"is package"<<f;

	pb_save->setDisabled(!f);
	pb_del->setDisabled(!f);
}

