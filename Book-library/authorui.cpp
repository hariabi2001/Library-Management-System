#include "QListWidgetItem"
#include "authorui.h"
#include "ui_authorui.h"
#include "book.h"
#include "authorbookdata.h"
#include "author.h"
#include "algorithms.h"
#include "map"
#include "set"

authorUI::authorUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::authorUI)
{
    ui->setupUi(this);
    addData();
}

authorUI::~authorUI()
{
    
}

void authorUI::addToList(Author *author)
{
    std::unique_ptr<QListWidgetItem> item = std::make_unique<QListWidgetItem>();
    item->setText(QString::fromStdString(author->getRealName()));
    ui->authorsTable->addItem(item);
}

void authorUI::addStringToList(std::string value)
{
    QListWidgetItem *item = new QListWidgetItem();
    item->setText(QString::fromStdString(value));
    ui->authorsTable->addItem(item);
}

void authorUI::addData()
{
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
    Book *first = new Book("Garry", algorithm.getTime("Sun Feb 13 00:26:36 2000"), "Classic", 123, data1);
    Book *second = new Book("July moon", algorithm.getTime("Mon Feb 7 00:21:00 2005"), "Classic", 123, data2);
    books.push_back(first);
    books.push_back(second);
    addToList(author1);
    addToList(author2);
    addToList(author3);
    addToList(author4);
    addToList(author5);
}

void authorUI::on_pageSort_clicked()
{
    struct Cmp
    {
        bool operator ()(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
           {
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
           }
    };
    std::map<std::string, int> author_numberOfBooks;
    int num;
    for (int i = 0; i < authors.size(); i++){
        num = algorithm.findPageNumber(books, authors[i], ui->startTime->dateTime().toTime_t(), ui->endTime->dateTime().toTime_t());
        author_numberOfBooks.insert({ authors[i]->getRealName(), num });
    }
    std::set<std::pair<const std::string, int>, Cmp> s;
    for (const auto& pair : author_numberOfBooks) {
        s.insert(pair);
    }
    ui->authorsTable->clear();
    for (std::pair<std::string, int> element : s){
        addStringToList(element.first);
    }
}

void authorUI::on_bookSort_clicked()
{
    struct Cmp
    {
        bool operator ()(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
           {
               if(a.second == b.second) return a.first < b.first;
               return a.second < b.second;
           }
    };
    std::map<std::string, int> author_numberOfBooks;
    int num;
    for (size_t i = 0; i < authors.size(); i++){
        num = algorithm.findBookNumber(books, authors[i], ui->startTime->dateTime().toTime_t(), ui->endTime->dateTime().toTime_t());
        author_numberOfBooks.insert({ authors[i]->getRealName(), num });
    }
    std::set<std::pair<const std::string, int>, Cmp> s;
    for (const auto& pair : author_numberOfBooks) {
        s.insert(pair);
    }
    ui->authorsTable->clear();
    for (std::pair<std::string, int> element : s){
        addStringToList(element.first);
    }
}
