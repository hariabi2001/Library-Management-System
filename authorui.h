#ifndef AUTHORUI_H
#define AUTHORUI_H

#include <QMainWindow>

namespace Ui {
class authorUI;
}

class authorUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit authorUI(QWidget *parent = nullptr);
    ~authorUI();

private:
    Ui::authorUI *ui;
};

#endif // AUTHORUI_H
