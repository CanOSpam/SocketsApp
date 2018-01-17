#include "SocketsApp.h"

SocketsApp::SocketsApp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connectButtons();
	selection = 0;
	
}


inline void SocketsApp::connectButtons()
{
	connect(ui.actionHost_to_IP, &QAction::triggered, this, &SocketsApp::getHostFromIP);
	connect(ui.actionIP_to_Host, &QAction::triggered, this, &SocketsApp::getIPFromHost);
	connect(ui.actionService_to_Port, &QAction::triggered, this, &SocketsApp::getPortFromService);
	connect(ui.actionPort_to_Service, &QAction::triggered, this, &SocketsApp::getServiceFromPort);
	connect(ui.ok_button, &QPushButton::clicked, this, &SocketsApp::okClicked);
	connect(ui.cancel_button, &QPushButton::clicked, this, &SocketsApp::cancelClicked);
}

void SocketsApp::getHostFromIP()
{
	//Make buttons clickable and lineedits not readonly
	buttonsAndEditsUsable(true);
	selection = 1;
	qDebug() << "Host from IP";
}

void SocketsApp::getIPFromHost()
{
	//Make buttons clickable and lineedits not readonly
	buttonsAndEditsUsable(true);
	selection = 2;
	qDebug() << "Host from IP";
}

void SocketsApp::getPortFromService()
{
	//Make buttons clickable and lineedits not readonly
	buttonsAndEditsUsable(true);
	selection = 3;
	qDebug() << "Host from IP";
}

void SocketsApp::getServiceFromPort()
{
	//Make buttons clickable and lineedits not readonly
	buttonsAndEditsUsable(true);
	selection = 4;
	qDebug() << "Host from IP";
}

void SocketsApp::cancelClicked()
{
	buttonsAndEditsUsable(false);
	ui.input1->setText("");
	ui.input2->setText("");
}

void SocketsApp::okClicked()
{
	buttonsAndEditsUsable(false);
	//Check which action is active, then perform necessary lookups
	switch (selection)
	{
	case 1:
		//Get host from IP
		break;

	case 2:
		//Get IP from Host
		break;

	case 3:
		//Get port from service
		break;

	case 4:
		//Get service from port
		break;

	default:
		break;
	}

	//display lookups in textedit
	ui.outputField->append("Lookup Performed");

	ui.input1->setText("");
	ui.input2->setText("");
}
void SocketsApp::buttonsAndEditsUsable(bool yesNo)
{
	ui.ok_button->setEnabled(yesNo);
	ui.cancel_button->setEnabled(yesNo);
	ui.input1->setReadOnly(!yesNo);
	ui.input2->setReadOnly(!yesNo);
}