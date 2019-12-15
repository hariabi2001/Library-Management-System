#include "authorui.h"
#include "ui_authorui.h"

authorUI::authorUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::authorUI)
{
    ui->setupUi(this);
}

authorUI::~authorUI()
{
    delete ui;
}
