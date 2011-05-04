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


	le_static->setInputMask("\\0\\xHH");
	le_step_step->setInputMask("\\0\\xHH");
	le_step_start->setInputMask("\\0\\xHH");
	le_step_end->setInputMask("\\0\\xHH");
	le_sum_start->setInputMask("\\0\\xHH");
	le_sum_end->setInputMask("\\0\\xHH");

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
	connect(cb_over, SIGNAL(currentIndexChanged(int)), this, SLOT(edit_over(int)));
	connect(r_inc, SIGNAL(clicked()), this, SLOT(edit_inc()));
	connect(r_dec, SIGNAL(clicked()), this, SLOT(edit_dec()));

	updateCurrentPackage();
	
}

void SendSet::setByte(vector <BYTE> &vec)
{
	pack_now.data_m = vec;
}

void SendSet::setStatic()
{
	st_set->setCurrentWidget(static_page);
	pack_now.method_m[line_now] = METHOD_STATIC;
}

void SendSet::setStep()
{
	st_set->setCurrentWidget(step_page);
	pack_now.method_m[line_now] = METHOD_STEP;
}

void SendSet::setSum()
{
	st_set->setCurrentWidget(sum_page);
	pack_now.method_m[line_now] = METHOD_SUM;
}

void SendSet::byteInfoChanged(int i)
{
	QString *str = new QString("Method ");
	line_now = i;

	qDebug()<<"byte changed "<<i;

	str->push_back(QVariant(i).toString());

	le_static->setText(QString::number(pack_now.static_m[i].static_byte, 16));

	if(pack_now.step_m[i].step >= 0){
		le_step_step->setText(QString::number(pack_now.step_m[i].step, 16));
		r_inc->setChecked(true);
	} else {
		le_step_step->setText(QString::number(abs(pack_now.step_m[i].step), 16));
		r_dec->setChecked(true);
	}

	le_step_start->setText(QString::number(pack_now.step_m[i].step_start, 16));
	le_step_end->setText(QString::number(pack_now.step_m[i].step_stop, 16));
	cb_over->setCurrentIndex(pack_now.step_m[i].flag);

	le_sum_start->setText(QString::number(pack_now.sum_m[i].sum_start, 16));
	le_sum_end->setText(QString::number(pack_now.sum_m[i].sum_stop, 16));

	groupBox->setTitle(*str);
	switch (pack_now.method_m[i]){
		case METHOD_STATIC:
			r_static->setChecked(true);
			setStatic();
			break;
		case METHOD_STEP:
			r_step->setChecked(true);
			setStep();
			break;
		case METHOD_SUM:
			r_sum->setChecked(true);
			setSum();
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
			lined[i]->setText(QString::number(pack_now.data_m[i], 16));
		}
		else{
			lined[i]->setInputMask(NULL);
			lined[i]->setPlaceholderText(QVariant(i).toString());
			lined[i]->setDisabled(true);
		}
	}

	byteInfoChanged(0);

}

void SendSet::edit_interval()
{
	pack_now.interval_ms = sb_interval->value();

}

void SendSet::edit_static()
{
	bool f;
	unsigned short v = QString(le_static->text()).toUShort(&f, 16);

	if(focusWidget() == le_static){
		pack_now.static_m[line_now].static_byte = v;
		pack_now.data_m[line_now] = v;
		le_static->selectAll();
		lined[line_now]->setText(QString::number(pack_now.static_m[line_now].static_byte, 16));
	}

}

void SendSet::edit_step_start()
{
	bool f;
	unsigned short v = QString(le_step_start->text()).toUShort(&f, 16);

	if(focusWidget() == le_step_start){
		pack_now.step_m[line_now].step_start= v;
		pack_now.data_m[line_now] = v;
		le_step_start->selectAll();
		lined[line_now]->setText(QString::number(pack_now.step_m[line_now].step_start, 16));
	}

}


void SendSet::edit_step_step()
{
	bool f;
	unsigned short v = QString(le_step_step->text()).toUShort(&f, 16);

	if(focusWidget() == le_step_step){
		if(r_inc->isChecked())
			pack_now.step_m[line_now].step= v;
		else
			pack_now.step_m[line_now].step= -v;

		le_step_step->selectAll();
	}

}

void SendSet::edit_step_end()
{
	bool f;
	unsigned short v = QString(le_step_end->text()).toUShort(&f, 16);

	if(focusWidget() == le_step_end){
		pack_now.step_m[line_now].step_stop = v;
		le_step_end->selectAll();
	}

}

void SendSet::edit_over(int f)
{
	pack_now.step_m[line_now].flag = static_cast<OVERFLOW_FLAG>(f);

}

void SendSet::edit_inc()
{
	pack_now.step_m[line_now].step = abs(pack_now.step_m[line_now].step);
}

void SendSet::edit_dec()
{
	pack_now.step_m[line_now].step = - abs(pack_now.step_m[line_now].step);
}

void SendSet::edit_sum_start()
{
	bool f;
	unsigned short v = QString(le_sum_start->text()).toUShort(&f, 16);

	if(focusWidget() == le_sum_start){
		pack_now.sum_m[line_now].sum_start = v;
		le_sum_start->selectAll();
	}

}

void SendSet::edit_sum_end()
{
	bool f;
	unsigned short v = QString(le_sum_end->text()).toUShort(&f, 16);

	if(focusWidget() == le_sum_end){
		pack_now.sum_m[line_now].sum_start = v;
		le_sum_end->selectAll();
	}

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


