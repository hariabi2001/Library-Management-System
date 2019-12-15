#ifndef AUTHORUI_H
#define AUTHORUI_H

#include <QMainWindow>
#include "author.h"
#include "book.h"
#include "algorithms.h"

namespace Ui {
class authorUI;
}

class authorUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit authorUI(QWidget *parent = nullptr);
    ~authorUI();

private slots:
    void on_pageSort_clicked();

    void on_bookSort_clicked();

private:
    algorithms algorithm;
    Ui::authorUI *ui;
    void addToList(Author *author);
    void addStringToList(std::string value);
    std::vector<Book*> books;
    std::vector<Author*> authors;
};

#endif // AUTHORUI_H
