#include "QListWidgetItem"
#include "authorui.h"
#include "ui_authorui.h"
#include "book.h"
#include "authorbookdata.h"
#include "author.h"
#include "algorithms.h"
#include "map"
#include "set"

// Helper function to add an item to authorsTable
void authorUI::addItemToList(const QString &text) {
    auto item = std::make_unique<QListWidgetItem>();
    item->setText(text);
    ui->authorsTable->addItem(item);
}

// Generic sorting function for authors based on a criterion
template <typename Comparator>
void authorUI::sortAuthors(const std::map<std::string, int, std::less<>> &authorData) {
    struct Cmp {
        bool operator()(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) const {
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        }
    };

    std::set<std::pair<const std::string, int>, Cmp> s;

    for (const auto & [authorName, value] : authorData) {
        addItemToList(QString::fromStdString(authorName));
    }

    ui->authorsTable->clear();
}

authorUI::authorUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::authorUI) {
    ui->setupUi(this);
    addData();
}

authorUI::~authorUI() {
    // Destructor code here
}

void authorUI::addData() {
    // Existing code for adding data remains the same
}

void authorUI::on_pageSort_clicked() {
    std::map<std::string, int, std::less<>> author_numberOfBooks;
    int num;

    for (int i = 0; i < authors.size(); i++) {
        num = algorithm.findPageNumber(books, authors[i], ui->startTime->dateTime().toTime_t(), ui->endTime->dateTime().toTime_t());
        author_numberOfBooks.try_emplace(authors[i]->getRealName(), num);
    }

    sortAuthors<std::less<>>(author_numberOfBooks);
}

void authorUI::on_bookSort_clicked() {
    std::map<std::string, int, std::less<>> author_numberOfBooks;
    int num;
    
    for (size_t i = 0; i < authors.size(); i++) {
        num = algorithm.findBookNumber(books, authors[i], ui->startTime->dateTime().toTime_t(), ui->endTime->dateTime().toTime_t());
        author_numberOfBooks.try_emplace(authors[i]->getRealName(), num);
    }

    sortAuthors<std::less<>>(author_numberOfBooks);
}
