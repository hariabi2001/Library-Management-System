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
    auto authorui = std::make_unique<authorUI>(this);
    authorui->show();
}

void MainWindow::on_Books_clicked()
{
    auto bookui = std::make_unique<bookUI>(this);
    bookui->show();
}
