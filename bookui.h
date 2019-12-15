#ifndef BOOKUI_H
#define BOOKUI_H

#include <QMainWindow>

namespace Ui {
class bookUI;
}

class bookUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit bookUI(QWidget *parent = nullptr);
    ~bookUI();

private:
    Ui::bookUI *ui;
};

#endif // BOOKUI_H
