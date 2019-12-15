#include "algorithms.h"

algorithms::algorithms()
{  
}

int algorithms::findBookNumber(std::vector<Book *> books, Author* author, time_t startDate, time_t endDate)
{
    int bookNumber = 0;
    double secondsBetween1, secondsBetween2;

    for (Book* book : books){
        secondsBetween1 = difftime(endDate, book->getPublicationDate());
        secondsBetween2 = difftime(book->getPublicationDate(), startDate);
        if (book->isAuthor(author) && secondsBetween1>0 && secondsBetween2 > 0) bookNumber++;
    }
    return bookNumber;
}

double algorithms::findPageNumber(std::vector<Book *> books, Author *author, time_t startDate, time_t endDate)
{
    double pageNumber = 0;
    double secondsBetween1, secondsBetween2;
    for (Book* book : books){
        secondsBetween1 = difftime(endDate, book->getPublicationDate());
        secondsBetween2 = difftime(book->getPublicationDate(), startDate);
        if (secondsBetween1>0 && secondsBetween2 > 0){
           std::unordered_map<std::string, double> result = book->getPagesByAuthor();
           if (result.find(author->getRealName()) != result.end()) {
               pageNumber = pageNumber + result[author->getRealName()];
           }
        }
    }
    return pageNumber;
}

