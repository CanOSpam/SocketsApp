#include "SocketsApp.h"

SocketsApp::SocketsApp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connectButtons();
	selection = 0;

	setStyleSheet("QLineEdit[readOnly=\"true\"] {"
		"color: #808080;"
		"background-color: #666666;"
		"border: 1px solid #B0B0B0;"
		"border-radius: 2px;}");
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
	buttonsAndEditsUsable(true, 1);
	setActions(false);
	selection = 1;
	qDebug() << "Host from IP";
}

void SocketsApp::getIPFromHost()
{
	//Make buttons clickable and lineedits not readonly
	buttonsAndEditsUsable(true, 1);
	setActions(false);
	selection = 2;
	qDebug() << "Host from IP";
}

void SocketsApp::getPortFromService()
{
	//Make buttons clickable and lineedits not readonly
	buttonsAndEditsUsable(true, 2);
	setActions(false);
	ui.input1->setText("Service");
	ui.input2->setText("Protocol");
	selection = 3;
	qDebug() << "Host from IP";
}

void SocketsApp::getServiceFromPort()
{
	//Make buttons clickable and lineedits not readonly
	buttonsAndEditsUsable(true, 2);
	setActions(false);
	ui.input1->setText("Port");
	ui.input2->setText("Protocol");
	selection = 4;
	qDebug() << "Host from IP";
}

void SocketsApp::cancelClicked()
{
	buttonsAndEditsUsable(false, 0);
	setActions(true);
	ui.input1->setText("");
	ui.input2->setText("");
}

void SocketsApp::okClicked()
{
	buttonsAndEditsUsable(false, 0);

	QString arg1 = ui.input1->text();
	QString arg2 = ui.input2->text();
	QString result = "X";

	WORD wVersionRequested = MAKEWORD(2, 2);
	WSADATA wsaData;
	
	int s_port;
	struct servent *sv;


	// Open up a Winsock v2.2 session
	WSAStartup(wVersionRequested, &wsaData);
	
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
		sv = getservbyname(arg1.toStdString().c_str(), arg2.toStdString().c_str());
		if (sv == NULL)
		{
			result = "An error has occured with port from service";
		}
		else
		{
			result = "The port number for " + arg1 + " is ";
			result.append(QString::number(ntohs(sv->s_port)));
		}
		
		break;

	case 4:
		//Get service from port
		s_port = atoi(arg1.toStdString().c_str());

		sv = getservbyport(htons(s_port), arg2.toStdString().c_str());
		if (sv == NULL)
		{
			result = "An error has occured with service from port";
		}
		else
		{
			result = "The service for " + arg2 + " port " + QString::number(s_port) + " is " + sv->s_name;
		}
		
		break;

	default:
		result = "An error has occured";
		break;
	}
	selection = 0;
	WSACleanup();


	//display lookups in textedit
	QTextCursor textCursor = ui.outputField->textCursor();
	textCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
	ui.outputField->setTextCursor(textCursor);

	ui.outputField->append(result);

	setActions(true);
	ui.input1->setText("");
	ui.input2->setText("");
}
void SocketsApp::buttonsAndEditsUsable(bool yesNo, int num)
{
	if (num == 0)
	{
		ui.ok_button->setEnabled(false);
		ui.cancel_button->setEnabled(false);
		ui.input1->setReadOnly(true);
		ui.input2->setReadOnly(true);
	}
	else if (num == 1)
	{
		ui.ok_button->setEnabled(yesNo);
		ui.cancel_button->setEnabled(yesNo);
		ui.input1->setReadOnly(!yesNo);
	}
	else if (num == 2)
	{
		ui.ok_button->setEnabled(yesNo);
		ui.cancel_button->setEnabled(yesNo);
		ui.input1->setReadOnly(!yesNo);
		ui.input2->setReadOnly(!yesNo);
	}

	ui.input1->style()->unpolish(ui.input1);
	ui.input1->style()->polish(ui.input1);
	ui.input2->style()->unpolish(ui.input2);
	ui.input2->style()->polish(ui.input2);
	
}

void SocketsApp::setActions(bool flag)
{
	ui.actionHost_to_IP->setEnabled(flag);
	ui.actionIP_to_Host->setEnabled(flag);
	ui.actionService_to_Port->setEnabled(flag);
	ui.actionPort_to_Service->setEnabled(flag);
}