#include "sendpage.h"


SendPage::SendPage() : QSplitter(Qt::Vertical, 0)
{
	send_list = new QListWidget();
	send_set = new SendSet();
	
	connect(send_list, SIGNAL(currentRowChanged(int)), this, SLOT(currentPackageChanged(int)));
	connect(send_set, SIGNAL(addPackage()), this, SLOT(addPackageRow()));
	connect(send_set, SIGNAL(savePackage(SendPackage &)), this, SLOT(savePackageInfo(SendPackage &)));

	addWidget(send_list);
	addWidget(send_set);


	addPackageRow();
	currentPackageChanged(0);


}

void SendPage::currentPackageChanged(int i)
{
	if(i >= 0)
		send_set->packageChanged(sendpack_vec.at(i));

}


void SendPage::addPackageRow()
{
	sendpack_vec.push_back(SendPackage(sendpack_vec.size()));

	QListWidgetItem *item = new QListWidgetItem(( sendpack_vec.back() ).name);
	send_list->addItem(item);
	item->setSelected(true);
	send_list->setCurrentRow(send_list->row(item));
	send_set->packageChanged(sendpack_vec.back());


	std::cout<<"vec size = "<<sendpack_vec.size()<<std::endl;
	std::cout<<"current row = "<<send_list->currentRow()<<std::endl;
}


void SendPage::savePackageInfo(SendPackage &pack)
{
	sendpack_vec.at(send_list->currentRow()) = pack;
}
