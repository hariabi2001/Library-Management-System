#include "bookui.h"
#include "ui_bookui.h"
#include "algorithms.h"
#include "bookinformation.h"

bookUI::bookUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bookUI)
{
    ui->setupUi(this);
    ui->booksTree->setHeaderHidden(true);
    addData();
}

bookUI::~bookUI()
{
    // Destructor implementation (if needed).
}

void bookUI::addRootGenre(QString name)
{
    std::unique_ptr<QTreeWidgetItem> item = std::make_unique<QTreeWidgetItem>(ui->booksTree);
    item->setText(0, name);
    ui->booksTree->addTopLevelItem(item.release());
}

void bookUI::addChildBook(Book* book)
{
    for (int i = 0; i < ui->booksTree->topLevelItemCount(); ++i)
    {
        QTreeWidgetItem* item = ui->booksTree->topLevelItem(i);
        if (item->text(0) == QString::fromStdString(book->getGenre()))
        {
            auto newBook = std::make_unique<QTreeWidgetItem>();
            newBook->setText(0, QString::fromStdString(book->getName()));
            item->addChild(newBook.release());
            break;
        }
    }
}

void bookUI::addData()
{
    auto author1 = std::make_shared<Author>("Cris Smith", "Classic");
    auto author2 = std::make_shared<Author>("Albert Tuna", "History");
    auto author3 = std::make_shared<Author>("Nickolas Tame", "History");
    auto author4 = std::make_shared<Author>("Khristina Palson", "Thriller");
    auto author5 = std::make_shared<Author>("John Kenner", "Science Fiction");
    
    authors.push_back(author1);
    authors.push_back(author2);
    authors.push_back(author3);
    authors.push_back(author4);
    authors push_back(author5);
    
    auto data1 = std::make_shared<oneAuthor>(author4, "Kelly");
    std::vector<author_pseudonym> many1;
    many1.push_back(author_pseudonym(author1, "Derek"));
    many1.push_back(author_pseudonym(author2, "Felly"));
    many1.push_back(author_pseudonym(author3, "Dams"));
    many1.push_back(author_pseudonym(author5, "Parkinson");
    auto data2 = std::make_shared<manyAuthors>(many1);
    
    algorithms algorithm;
    
    auto first = std::make_shared<Book>("Garry", algorithm.getTime("2000/02/01 00:00:00"), "Classic", 123, data2);
    auto second = std::make_shared<Book>("July moon", algorithm.getTime("2005/02/07 00:00:00"), "History", 123, data1);
    
    books.push_back(first);
    books.push_back(second);
    
    addRootGenre("Classic");
    addRootGenre("History");
    addRootGenre("Thriller");
    addRootGenre("Science Fiction");
    
    for (const auto& book : books)
        addChildBook(book);
}

void bookUI::on_booksTree_itemClicked(const QTreeWidgetItem* item, [[maybe_unused]] int column)
{
    if (item->parent())
    {
        Book* searchedBook = books[0];
        for (Book* book : books)
        {
            if (QString::fromStdString(book->getName()) == item->text(0))
            {
                searchedBook = book;
                break;
            }
        }
        auto bookInfo = std::make_unique<BookInformation>(searchedBook);
        bookInfo->show();
    }
}


