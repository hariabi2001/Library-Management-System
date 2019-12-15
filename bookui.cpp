#include "bookui.h"
#include "ui_bookui.h"
#include "algorithms.h"

bookUI::bookUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bookUI)
{
    ui->setupUi(this);
    Author *author1 = new Author("Cris Smith", "Classic");
    Author *author2 = new Author("Albert Tuna", "History");
    Author *author3 = new Author("Nickolas Tame", "History");
    Author *author4 = new Author("Khristina Palson", "Thriller");
    Author *author5 = new Author("John Kenner", "Science Fiction");
    authors.push_back(author1);
    authors.push_back(author2);
    authors.push_back(author3);
    authors.push_back(author4);
    authors.push_back(author5);
    authorBookData *data1 = new oneAuthor(author4, "Kelly");
    std::vector<author_pseudonym> many1;
    many1.push_back(author_pseudonym(author1, "Derek"));
    many1.push_back(author_pseudonym(author2, "Felly"));
    many1.push_back(author_pseudonym(author3, "Dams"));
    many1.push_back(author_pseudonym(author5, "Parkinson"));
    authorBookData *data2 = new manyAuthors(many1);
    algorithms algorithm;
    Book *first = new Book("Garry", algorithm.getTime("2000/02/01 00:00:00"), "Classic", 123, data2);
    Book *second = new Book("July moon", algorithm.getTime("2005/02/07 00:00:00"), "History", 123, data1);
    books.push_back(first);
    books.push_back(second);
    addRootGenre("Classic");
    addRootGenre("History");
    addRootGenre("Thriller");
    addRootGenre("Science fiction");
    addRootGenre("Classic");

}

bookUI::~bookUI()
{
    delete ui;
}

void bookUI::addRootGenre(QString name)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
    item->setText(0, name);
    ui->treeWidget->addTopLevelItem(item);
}

void bookUI::addChildBook(QTreeWidgetItem *parent, QString name, QString path)
{
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, name);
    item->setData(0, Qt::UserRole, path);
    parent->addChild(item);
}
