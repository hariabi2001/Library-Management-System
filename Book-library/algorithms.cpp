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
        if (book->isAuthor(author))
            bookNumber++;
    }
    return bookNumber;
}

double algorithms::findPageNumber(std::vector<Book*> books, Author* author, time_t startDate, time_t endDate)
{
    double pageNumber = 0;
    double secondsBetween1, secondsBetween2;

    for (Book* book : books) {
        secondsBetween1 = difftime(endDate, book->getPublicationDate());
        secondsBetween2 = difftime(book->getPublicationDate(), startDate);

        // Check if the book falls within the specified date range
        // if (secondsBetween1 > 0 && secondsBetween2 > 0) {
        std::unordered_map<std::string, double> result = book->getPagesByAuthor();

        // Check if the author's name exists in the book's author list
        auto authorPageCount = result.find(author->getRealName());
        if (authorPageCount != result.end()) {
            pageNumber += authorPageCount->second;
        }
        
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

    // Convert std::tm to std::chrono::system_clock::time_point directly
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::from_time_t(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    tp += std::chrono::hours(whenStart.tm_hour);
    tp += std::chrono::minutes(whenStart.tm_min);
    tp += std::chrono::seconds(whenStart.tm_sec);
    tp += std::chrono::hours(whenStart.tm_mday - 1); // Subtract 1 to adjust for day
    tp += std::chrono::hours(whenStart.tm_mon * 30); // Very rough approximation for months
    tp += std::chrono::hours((whenStart.tm_year - 70) * 365 * 24); // Adjust for years since 1970

    // You might want to add more precise month and year adjustments
    // based on your specific requirements.

    // Convert std::chrono::system_clock::time_point to std::time_t
    std::time_t time = std::chrono::system_clock::to_time_t(tp);

    return time;
}


