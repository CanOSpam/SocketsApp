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
	connect(ui.actionIP_to_Host, &QAction::triggered, this, &SocketsApp::getHostFromIP);
	connect(ui.actionHost_to_IP, &QAction::triggered, this, &SocketsApp::getIPFromHost);
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
	ui.input1->setText("Dotted IP");
	selection = 1;
	qDebug() << "Host from IP";
}

void SocketsApp::getIPFromHost()
{
	//Make buttons clickable and lineedits not readonly
	buttonsAndEditsUsable(true, 1);
	setActions(false);
	ui.input1->setText("Host Name");
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
	int		a;
	struct	hostent *hp;
	struct	in_addr my_addr, *addr_p;
	char	**p;
	char	ip_address[256];


	// Open up a Winsock v2.2 session
	WSAStartup(wVersionRequested, &wsaData);
	
	//Check which action is active, then perform necessary lookups
	switch (selection)
	{
	case 1:
		//Get host from IP
		addr_p = (struct in_addr*)malloc(sizeof(struct in_addr));
		addr_p = &my_addr;

		if ((a = inet_addr(arg1.toStdString().c_str())) == 0)
		{
			result = ("IP Address must be of the form x.x.x.x\n");
			break;
		}

		// Copy IP address  into ip_address
		strcpy(ip_address, arg1.toStdString().c_str());
		addr_p->s_addr = inet_addr(ip_address);


		hp = gethostbyaddr((char *)addr_p, PF_INET, sizeof(my_addr));

		if (hp == NULL)
		{
			result = "host information for " + arg1 + " not found";
			result.append('\n');
			break;
		}
		result = "";
		for (p = hp->h_addr_list; *p != 0; p++)
		{
			struct in_addr in;
			char **q;

			memcpy(&in.s_addr, *p, sizeof(in.s_addr));
			result.append("IP Address: " + QString(inet_ntoa(in)) + "\nHost Name: "+ hp->h_name);
			result.append('\n');
			result.append("Aliases: \n");
			for (q = hp->h_aliases; *q != 0; q++)
			{
				result.append("\t" + QString(*q) + "\n");
			}
			result.append('\n');
		}


		break;

	case 2:
		//Get IP from Host
		addr_p = (struct in_addr*)malloc(sizeof(struct in_addr));
		addr_p = &my_addr;

		if ((hp = gethostbyname(arg1.toStdString().c_str())) == NULL) 	// Host name?
		{
			result = "";
			switch (h_errno)
			{
			case HOST_NOT_FOUND:
				result.append("No such host " + arg1 + "\n");
				break;
			case TRY_AGAIN:
				result.append("host " + arg1 + " try again later\n");
				break;
			case NO_RECOVERY:
				result.append("host " + arg1 + " DNS Error\n");
				break;
			case NO_ADDRESS:
				result.append("No IP Address for " + arg1 + "\n");
				break;
			default:
				result.append("Unknown Error:  " + QString::number(h_errno) + "\n");
				break;
			}
		}
		else
		{
			result = "";
			for (p = hp->h_addr_list; *p != 0; p++)
			{
				struct in_addr in;
				char **q;

				memcpy(&in.s_addr, *p, sizeof(in.s_addr));
				result.append("IP Address: "+ QString(inet_ntoa(in)) +"\t Host Name: " + QString(hp->h_name) + "\n");

				for (q = hp->h_aliases; *q != 0; q++)
				{
					result.append("\t   Aliases: " + QString(*q) + "\n");
				}
				result.append('\n');
			}
		}

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
		result.append('\n');
		
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
		result.append('\n');
		
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