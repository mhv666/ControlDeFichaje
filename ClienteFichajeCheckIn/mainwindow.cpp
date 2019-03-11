#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "app.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    m_app = new App;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_app;
}

void MainWindow::on_pushButton_clicked()
{
    QString jsonCheckInOut{};

QString ean13 = ui->ean13->text();
jsonCheckInOut = m_app->m_jsonBuilder->crearJsonChekcInOut(ean13);
m_app->m_webSocket->sendMessage(jsonCheckInOut);

}
