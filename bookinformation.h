#ifndef BOOKINFORMATION_H
#define BOOKINFORMATION_H

#include <QDialog>
#include "book.h"

namespace Ui {
class BookInformation;
}

class BookInformation : public QDialog
{
    Q_OBJECT

public:
    explicit BookInformation(Book* book, QWidget *parent = nullptr);
    ~BookInformation();

private:
    Ui::BookInformation *ui;

};

#endif // BOOKINFORMATION_H
