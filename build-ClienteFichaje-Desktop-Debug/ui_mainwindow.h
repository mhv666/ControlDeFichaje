/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btnCrear;
    QLabel *label;
    QLineEdit *nombre;
    QLineEdit *pass;
    QLabel *label_2;
    QRadioButton *rbSi;
    QRadioButton *rbNo;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *ean13;
    QPushButton *btnActivar;
    QFrame *line;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 332);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnCrear = new QPushButton(centralWidget);
        btnCrear->setObjectName(QStringLiteral("btnCrear"));
        btnCrear->setGeometry(QRect(20, 100, 351, 34));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 58, 18));
        nombre = new QLineEdit(centralWidget);
        nombre->setObjectName(QStringLiteral("nombre"));
        nombre->setGeometry(QRect(100, 10, 221, 32));
        pass = new QLineEdit(centralWidget);
        pass->setObjectName(QStringLiteral("pass"));
        pass->setGeometry(QRect(100, 50, 221, 32));
        pass->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 58, 18));
        rbSi = new QRadioButton(centralWidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(rbSi);
        rbSi->setObjectName(QStringLiteral("rbSi"));
        rbSi->setGeometry(QRect(20, 270, 41, 22));
        rbNo = new QRadioButton(centralWidget);
        buttonGroup->addButton(rbNo);
        rbNo->setObjectName(QStringLiteral("rbNo"));
        rbNo->setGeometry(QRect(80, 270, 51, 22));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 240, 58, 18));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 170, 181, 18));
        ean13 = new QLineEdit(centralWidget);
        ean13->setObjectName(QStringLiteral("ean13"));
        ean13->setGeometry(QRect(20, 200, 351, 32));
        btnActivar = new QPushButton(centralWidget);
        btnActivar->setObjectName(QStringLiteral("btnActivar"));
        btnActivar->setGeometry(QRect(150, 260, 221, 34));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 150, 371, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btnCrear->setText(QApplication::translate("MainWindow", "Crear", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Nombre", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        rbSi->setText(QApplication::translate("MainWindow", "Si", Q_NULLPTR));
        rbNo->setText(QApplication::translate("MainWindow", "&No", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Habilitar", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Codigo Trabajador asignado", Q_NULLPTR));
        btnActivar->setText(QApplication::translate("MainWindow", "Activar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
