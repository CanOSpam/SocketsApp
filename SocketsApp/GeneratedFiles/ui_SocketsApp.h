/********************************************************************************
** Form generated from reading UI file 'SocketsApp.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCKETSAPP_H
#define UI_SOCKETSAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SocketsAppClass
{
public:
    QAction *actionHost_to_IP;
    QAction *actionIP_to_Host;
    QAction *actionService_to_Port;
    QAction *actionPort_to_Service;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *input1;
    QLineEdit *input2;
    QHBoxLayout *horizontalLayout;
    QPushButton *ok_button;
    QPushButton *cancel_button;
    QTextEdit *outputField;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SocketsAppClass)
    {
        if (SocketsAppClass->objectName().isEmpty())
            SocketsAppClass->setObjectName(QStringLiteral("SocketsAppClass"));
        SocketsAppClass->resize(427, 400);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SocketsAppClass->sizePolicy().hasHeightForWidth());
        SocketsAppClass->setSizePolicy(sizePolicy);
        actionHost_to_IP = new QAction(SocketsAppClass);
        actionHost_to_IP->setObjectName(QStringLiteral("actionHost_to_IP"));
        actionIP_to_Host = new QAction(SocketsAppClass);
        actionIP_to_Host->setObjectName(QStringLiteral("actionIP_to_Host"));
        actionService_to_Port = new QAction(SocketsAppClass);
        actionService_to_Port->setObjectName(QStringLiteral("actionService_to_Port"));
        actionPort_to_Service = new QAction(SocketsAppClass);
        actionPort_to_Service->setObjectName(QStringLiteral("actionPort_to_Service"));
        centralWidget = new QWidget(SocketsAppClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        input1 = new QLineEdit(centralWidget);
        input1->setObjectName(QStringLiteral("input1"));
        input1->setReadOnly(true);

        verticalLayout->addWidget(input1);

        input2 = new QLineEdit(centralWidget);
        input2->setObjectName(QStringLiteral("input2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(input2->sizePolicy().hasHeightForWidth());
        input2->setSizePolicy(sizePolicy1);
        input2->setMinimumSize(QSize(301, 0));
        input2->setReadOnly(true);

        verticalLayout->addWidget(input2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        ok_button = new QPushButton(centralWidget);
        ok_button->setObjectName(QStringLiteral("ok_button"));
        ok_button->setEnabled(false);

        horizontalLayout->addWidget(ok_button);

        cancel_button = new QPushButton(centralWidget);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));
        cancel_button->setEnabled(false);

        horizontalLayout->addWidget(cancel_button);


        verticalLayout->addLayout(horizontalLayout);

        outputField = new QTextEdit(centralWidget);
        outputField->setObjectName(QStringLiteral("outputField"));
        outputField->setReadOnly(true);

        verticalLayout->addWidget(outputField);

        SocketsAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SocketsAppClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 427, 21));
        SocketsAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SocketsAppClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SocketsAppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SocketsAppClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SocketsAppClass->setStatusBar(statusBar);

        mainToolBar->addAction(actionHost_to_IP);
        mainToolBar->addAction(actionIP_to_Host);
        mainToolBar->addAction(actionService_to_Port);
        mainToolBar->addAction(actionPort_to_Service);

        retranslateUi(SocketsAppClass);

        QMetaObject::connectSlotsByName(SocketsAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *SocketsAppClass)
    {
        SocketsAppClass->setWindowTitle(QApplication::translate("SocketsAppClass", "SocketsApp", 0));
        actionHost_to_IP->setText(QApplication::translate("SocketsAppClass", "Host to IP", 0));
#ifndef QT_NO_TOOLTIP
        actionHost_to_IP->setToolTip(QApplication::translate("SocketsAppClass", "Translate a host name to an IP address", 0));
#endif // QT_NO_TOOLTIP
        actionIP_to_Host->setText(QApplication::translate("SocketsAppClass", "IP to Host", 0));
#ifndef QT_NO_TOOLTIP
        actionIP_to_Host->setToolTip(QApplication::translate("SocketsAppClass", "Translate an IP to a host name", 0));
#endif // QT_NO_TOOLTIP
        actionService_to_Port->setText(QApplication::translate("SocketsAppClass", "Service to Port", 0));
#ifndef QT_NO_TOOLTIP
        actionService_to_Port->setToolTip(QApplication::translate("SocketsAppClass", "Translate a service/protocal to a port number", 0));
#endif // QT_NO_TOOLTIP
        actionPort_to_Service->setText(QApplication::translate("SocketsAppClass", "Port to Service", 0));
#ifndef QT_NO_TOOLTIP
        actionPort_to_Service->setToolTip(QApplication::translate("SocketsAppClass", "Translate a port or protocol to a service", 0));
#endif // QT_NO_TOOLTIP
        ok_button->setText(QApplication::translate("SocketsAppClass", "OK", 0));
        cancel_button->setText(QApplication::translate("SocketsAppClass", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class SocketsAppClass: public Ui_SocketsAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCKETSAPP_H
