#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <book.h>
#include <author.h>

class algorithms
{
public:
    algorithms();
    int findBookNumber(std::vector<Book*> books, Author* author, time_t startDate, time_t endDate);
    double findPageNumber(std::vector<Book*> books, Author* author, time_t startDate, time_t endDate);
};

#endif // ALGORITHMS_H
