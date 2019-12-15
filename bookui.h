#ifndef BOOKUI_H
#define BOOKUI_H

#include "QTreeWidgetItem"
#include <QMainWindow>
#include "author.h"
#include "book.h"

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
    std::vector<Book*> books;
    std::vector<Author*> authors;

    void addRootGenre(QString name);
    void addChildBook(QTreeWidgetItem *parent, QString name, QString path);
};

#endif // BOOKUI_H
