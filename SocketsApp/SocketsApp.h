#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SocketsApp.h"

class SocketsApp : public QMainWindow
{
	Q_OBJECT

public:
	SocketsApp(QWidget *parent = Q_NULLPTR);

private:
	Ui::SocketsAppClass ui;
};
