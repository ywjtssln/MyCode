#include "sendset.h"

void MyLineEdit::focusInEvent(QFocusEvent *event)
{
	if(event->gotFocus())
		emit focusChanged(id);
}
	

SendSet::SendSet()
{
	setupUi(this);

	for(int i = 0; i != 10; ++i){
		lined[i] = new MyLineEdit(i, this);
		lined[i]->setGeometry(7 + i * 40, 95, 40, 24);
		lined[i]->setDisabled(true);
		lined[i]->setPlaceholderText(QVariant(i).toString());
		connect(lined[i], SIGNAL(focusChanged(int)), this, SLOT(byteInfoChanged(int)));
	}
	for(int j = 10; j != 20; ++j){
		lined[j] = new MyLineEdit(j, this);
		lined[j]->setGeometry(7 + (j - 10) * 40, 125, 40, 24);
		lined[j]->setDisabled(true);
		lined[j]->setPlaceholderText(QVariant(j).toString());
		connect(lined[j], SIGNAL(focusChanged(int)), this, SLOT(byteInfoChanged(int)));
	}

	connect(r_static, SIGNAL(clicked()), this, SLOT(setStatic()));
	connect(r_step, SIGNAL(clicked()), this, SLOT(setStep()));
	connect(r_sum, SIGNAL(clicked()), this, SLOT(setSum()));
	connect(pb_add, SIGNAL(clicked()), this, SLOT(add_clicked()));
	connect(pb_save, SIGNAL(clicked()), this, SLOT(save_clicked()));
	connect(pb_del, SIGNAL(clicked()), this, SLOT(del_clicked()));
	connect(le_name, SIGNAL(editingFinished()), this, SLOT(edit_name()));
	connect(sb_lenth, SIGNAL(valueChanged(int)), this, SLOT(edit_lenth()));
	connect(sb_interval, SIGNAL(valueChanged(int)), this, SLOT(edit_interval()));
	connect(le_static, SIGNAL(editingFinished()), this, SLOT(edit_static()));
	connect(le_step_start, SIGNAL(editingFinished()), this, SLOT(edit_step_start()));
	connect(le_step_step, SIGNAL(editingFinished()), this, SLOT(edit_step_step()));
	connect(le_step_end, SIGNAL(editingFinished()), this, SLOT(edit_step_end()));
	connect(le_sum_start, SIGNAL(editingFinished()), this, SLOT(edit_sum_start()));
	connect(le_sum_end, SIGNAL(editingFinished()), this, SLOT(edit_sum_end()));

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

void SendSet::byteInfoChanged(int i)
{
	switch (pack_now.method_m[i]){
		case METHOD_STATIC:
			r_static->setChecked(true);
			le_static->setText(QVariant(pack_now.static_m[i].static_byte).toString());
			break;
		case METHOD_STEP:
			r_step->setChecked(true);
			le_step_step->setText(QVariant(pack_now.step_m[i].step).toString());
			le_step_start->setText(QVariant(pack_now.step_m[i].step_start).toString());
			le_step_end->setText(QVariant(pack_now.step_m[i].step_stop).toString());
			cb_over->setCurrentIndex(pack_now.step_m[i].flag);
			break;
		case METHOD_SUM:
			r_sum->setChecked(true);
			le_sum_start->setText(QVariant(pack_now.sum_m[i].sum_start).toString());
			le_sum_end->setText(QVariant(pack_now.sum_m[i].sum_stop).toString());
			break;
	}

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

	for(unsigned int i = 0; i!= 20; ++i){
		if(i < pack_now.num){
			lined[i]->setInputMask("\\0\\xHH");
			lined[i]->setDisabled(false);
		}
		else{
			lined[i]->setInputMask(NULL);
			lined[i]->setPlaceholderText(QVariant(i).toString());
			lined[i]->setDisabled(true);
		}
	}

}

void SendSet::edit_interval()
{
	pack_now.interval_ms = sb_interval->value();

}

void SendSet::edit_static(){

}

void SendSet::edit_step_start(){

}


void SendSet::edit_step_step(){

}

void SendSet::edit_step_end(){

}

void SendSet::edit_sum_start(){

}

void SendSet::edit_sum_end(){

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


