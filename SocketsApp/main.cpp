#include "SocketsApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SocketsApp w;
	w.show();
	return a.exec();
}
