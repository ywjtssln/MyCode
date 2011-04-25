#include "sendpage.h"

SendPage::SendPage() : QSplitter(Qt::Vertical, 0)
{
	send_list = new QListWidget();
	send_set = new SendSet();

	send_list->addItem("package 1");
	send_list->addItem("package 2");
	send_list->addItem("package 3");

	addWidget(send_list);
	addWidget(send_set);

}
