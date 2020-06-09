#ifndef BOOKUI_H
#define BOOKUI_H

#include "QTreeWidgetItem"
#include <QMainWindow>
#include "author.h"
#include "book.h"
#include "bookinformation.h"

namespace Ui {
class bookUI;
}

class bookUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit bookUI(QWidget *parent = nullptr);
    ~bookUI();

private slots:
    void on_booksTree_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::bookUI *ui;
    BookInformation *bookinformation;
    std::vector<Book*> books;
    std::vector<Author*> authors;

    void addRootGenre(QString name);
    void addChildBook(Book* book);
    void addData();
};

#endif // BOOKUI_H
