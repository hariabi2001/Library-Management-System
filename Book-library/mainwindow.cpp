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
    
}


void MainWindow::on_Authors_clicked()
{
    auto authorUIPtr = std::make_unique<authorUI>(this);
    authorUIPtr->show();
}

void MainWindow::on_Books_clicked()
{
    auto bookUIPtr = std::make_unique<bookUI>(this);
    bookUIPtr->show();
}
