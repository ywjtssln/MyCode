#include "sendpage.h"


SendPage::SendPage() : QSplitter(Qt::Vertical, 0)
{
	send_list = new QListWidget();
	send_set = new SendSet();
	
	connect(send_list, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(currentPackageChanged(QListWidgetItem *)));
	connect(send_list, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(currentPackageChanged(QListWidgetItem *)));
	connect(send_list, SIGNAL(currentRowChanged(int)), this, SLOT(currentPackageChanged(int)));
	connect(send_set, SIGNAL(addPackage()), this, SLOT(addPackageRow()));
	connect(send_set, SIGNAL(savePackage(SendPackage &)), this, SLOT(savePackageInfo(SendPackage &)));
	connect(send_set, SIGNAL(delPackage()), this, SLOT(delPackageRow()));

	addWidget(send_list);
	addWidget(send_set);


	addPackageRow();

}

void SendPage::currentPackageChanged(int row)
{
	qDebug()<<"CURRENT ROW ROW"<<row;

	if(row >= 0 && (unsigned int)row < sendpack_vec.size()){
		send_set->packageChanged(sendpack_vec.at(row));
	}

}


void SendPage::currentPackageChanged(QListWidgetItem *item)
{
	int row = send_list->row(item);

	qDebug()<<"CHG row "<<row; 
	if(row >= 0 && (unsigned int)row < sendpack_vec.size()){
		send_set->packageChanged(sendpack_vec.at(row));
	}


	qDebug()<<"CHG current row "<<send_list->currentRow(); 
}


void SendPage::addPackageRow()
{
	sendpack_vec.push_back(SendPackage(sendpack_vec.size()));

	if(send_list->count() == 0)
		send_set->isPackage(true);

	QListWidgetItem *item = new QListWidgetItem(( sendpack_vec.back() ).name);
	item->setSelected(true);
	send_list->addItem(item);
	send_list->setCurrentRow(send_list->row(item));
	send_set->packageChanged(sendpack_vec.back());

	qDebug()<<"ADD current count"<<send_list->count(); 
	qDebug()<<"ADD current row "<<send_list->currentRow(); 

}


void SendPage::savePackageInfo(SendPackage &pack)
{
	int row = send_list->row((send_list->selectedItems()).last());

	sendpack_vec.at(row) = pack;
	send_list->item(row)->setText(pack.name);

	qDebug()<<"SAVE current row "<<send_list->currentRow(); 
}

void SendPage::delPackageRow()
{
	int row = send_list->row((send_list->selectedItems()).last());
	vector <SendPackage>::iterator iter = sendpack_vec.begin();


	if(send_list->count()){
		sendpack_vec.erase(iter + row);
		send_list->removeItemWidget(send_list->takeItem(row));
		currentPackageChanged(send_list->item(send_list->currentRow()));
	}

	if(send_list->count() == 0)
		send_set->isPackage(false);


	qDebug()<<"DEL current row "<<send_list->currentRow(); 
}
