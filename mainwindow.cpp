#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authorui.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Authors_clicked()
{
    authorui = new authorUI(this);
    authorui->show();
}

void MainWindow::on_Books_clicked()
{
    bookui = new bookUI(this);
    bookui->show();
}
