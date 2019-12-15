#include "bookui.h"
#include "ui_bookui.h"

bookUI::bookUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bookUI)
{
    ui->setupUi(this);
}

bookUI::~bookUI()
{
    delete ui;
}
