#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "authorui.h"
#include "bookui.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void on_Authors_clicked();

    void on_Books_clicked();

private:
    Ui::MainWindow *ui;
    authorUI *authorui;
    bookUI *bookui;
};
#endif // MAINWINDOW_H
