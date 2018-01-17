#include "SocketsApp.h"

SocketsApp::SocketsApp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connectButtons();
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
	qDebug() << "Host from IP";
}

void SocketsApp::getIPFromHost()
{
	//Make buttons clickable and lineedits not readonly
	buttonsAndEditsUsable(true);
	qDebug() << "Host from IP";
}

void SocketsApp::getPortFromService()
{
	//Make buttons clickable and lineedits not readonly
	buttonsAndEditsUsable(true);
	qDebug() << "Host from IP";
}

void SocketsApp::getServiceFromPort()
{
	//Make buttons clickable and lineedits not readonly
	buttonsAndEditsUsable(true);
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

	//display lookups in textedit

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