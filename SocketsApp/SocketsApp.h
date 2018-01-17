#pragma once

#include <QtWidgets/QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <string>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

//Remove for final
#include <QDebug>

#include "ui_SocketsApp.h"

class SocketsApp : public QMainWindow
{
	Q_OBJECT

public:
	SocketsApp(QWidget *parent = Q_NULLPTR);

public slots:
	void okClicked();
	void cancelClicked();
	void getHostFromIP();
	void getIPFromHost();
	void getPortFromService();
	void getServiceFromPort();

private:
	Ui::SocketsAppClass ui;
	inline void connectButtons();
	void buttonsAndEditsUsable(bool yes, int num);
	void setActions(bool flag);
	int selection;
};