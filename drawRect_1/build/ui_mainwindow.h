/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qwgraphicsview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWGraphicsView *GView;
    QPushButton *btnAddRect;
    QPushButton *btnRemove;
    QPushButton *btnGetCoord;
    QPushButton *btnReset;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1035, 782);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GView = new QWGraphicsView(centralWidget);
        GView->setObjectName(QString::fromUtf8("GView"));
        GView->setGeometry(QRect(0, 0, 701, 701));
        GView->setFrameShape(QFrame::NoFrame);
        GView->setFrameShadow(QFrame::Plain);
        GView->setLineWidth(0);
        btnAddRect = new QPushButton(centralWidget);
        btnAddRect->setObjectName(QString::fromUtf8("btnAddRect"));
        btnAddRect->setGeometry(QRect(720, 20, 93, 28));
        btnRemove = new QPushButton(centralWidget);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));
        btnRemove->setGeometry(QRect(850, 20, 93, 28));
        btnGetCoord = new QPushButton(centralWidget);
        btnGetCoord->setObjectName(QString::fromUtf8("btnGetCoord"));
        btnGetCoord->setGeometry(QRect(720, 80, 93, 28));
        btnReset = new QPushButton(centralWidget);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));
        btnReset->setGeometry(QRect(850, 80, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1035, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnAddRect->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\241\206", nullptr));
        btnRemove->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\346\241\206", nullptr));
        btnGetCoord->setText(QCoreApplication::translate("MainWindow", "\346\210\252\345\217\226\345\233\276\345\203\217", nullptr));
        btnReset->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
