#include "algorithms.h"
#include <sstream>
#include <iomanip>
#include <ctime>
#include <sstream>

algorithms::algorithms() = default;

int algorithms::findBookNumber(const std::vector<Book*>& books, Author* author, time_t startDate, time_t endDate)
{
    int bookNumber = 0;
    double secondsBetween1, secondsBetween2;
    for (Book* book : books) {
        secondsBetween1 = difftime(endDate, book->getPublicationDate());
        secondsBetween2 = difftime(book->getPublicationDate(), startDate);
        if (book->isAuthor(author)) bookNumber++;
        // qt dates don't work :(
        // (secondsBetween1 >= 0) && (secondsBetween2 >= 0)) bookNumber++;
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

std::time_t algorithms::getTime(const std::string& timeString) {
    std::tm whenStart = {};
    std::istringstream timeStream(timeString);
    timeStream >> std::get_time(&whenStart, "%Y/%m/%d %H:%M:%S");
    if (timeStream.fail()) {
        // Handle invalid input
        return -1; // Or any other appropriate error handling
    }
    
    // Convert std::tm to std::chrono::system_clock::time_point
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::from_time_t(std::mktime(&whenStart));
    
    // Convert std::chrono::system_clock::time_point to std::time_t
    return std::chrono::system_clock::to_time_t(tp);
}

