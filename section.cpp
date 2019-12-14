#include "section.h"


Section::Section(int pageNumber, std::shared_ptr<authorBookData> authors)
{
    this->pageNumber = pageNumber;
    this->authors = authors;
}
