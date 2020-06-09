#include "algorithms.h"
#include <sstream>
#include <iomanip>
#include <ctime>
#include <sstream>

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
        if (book->isAuthor(author)) bookNumber++;
        //qt dates don't work :(
        //(secondsBetween1>=0) && (secondsBetween2>=0)) bookNumber++;
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
        //if (secondsBetween1>0 && secondsBetween2 > 0){
           std::unordered_map<std::string, double> result = book->getPagesByAuthor();
           if (result.find(author->getRealName()) != result.end()) {
               pageNumber = pageNumber + result[author->getRealName()];
           }
        //}
    }
    return pageNumber;
}

time_t algorithms::getTime(std::string time)
{
    time_t tStart;
    int yy, month, dd, hh, mm, ss;
    struct tm whenStart;
    const char *zStart = time.c_str();

    sscanf(zStart, "%d/%d/%d %d:%d:%d", &yy, &month, &dd, &hh, &mm, &ss);
    whenStart.tm_year = yy;
    whenStart.tm_mon = month - 1;
    whenStart.tm_mday = dd;
    whenStart.tm_hour = hh;
    whenStart.tm_min = mm;
    whenStart.tm_sec = ss;
    whenStart.tm_isdst = -1;

    tStart = mktime(&whenStart);
    return tStart;
}

