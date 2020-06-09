#ifndef SECTION_H
#define SECTION_H
#include <authorbookdata.h>
#include <memory>


class Section
{
    int pageNumber;
    std::shared_ptr<authorBookData> authors;
public:
    Section(int pageNumber, std::shared_ptr<authorBookData> authors);
};

#endif // SECTION_H
