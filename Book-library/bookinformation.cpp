#include "bookinformation.h"
#include "ui_bookinformation.h"
#include "authorbookdata.h"

BookInformation::BookInformation(Book* book, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookInformation)
{
    ui->setupUi(this);
    std::string text = "Book name:\n";
    text.append(book->getName());
    text.append("\n Publication date:\n");
    time_t time = book->getPublicationDate();
    struct tm *tmp = gmtime_r(&time);
    text.append(std::to_string(tmp->tm_year));
    text.append("\nPage number:\n");
    text.append(std::to_string(book->getPageNumber()));
    text.append("\nAuthors:\n");
    std::vector<std::string> authors = book->getAuthors();
    for (std::string author : authors){
        text.append(author);
        text.append("\n");
    }
    ui->bookData->setText(QString::fromStdString(text));
}


BookInformation::~BookInformation()
{
    delete ui;
}
