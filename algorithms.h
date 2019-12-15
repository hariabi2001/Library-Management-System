#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <book.h>
#include <author.h>

class algorithms
{
public:
    algorithms();
    int findBookNumber(std::vector<Book*> books, Author* author);
};

#endif // ALGORITHMS_H
