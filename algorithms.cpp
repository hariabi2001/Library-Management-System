#include "algorithms.h"

algorithms::algorithms()
{  
}

int algorithms::findBookNumber(std::vector<Book *> books, Author* author)
{
    int bookNumber = 0;
    for (Book* book : books){
        if (book->isAuthor(author)) bookNumber++;
    }
    return bookNumber;
}
