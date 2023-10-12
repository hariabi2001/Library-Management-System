#include "section.h"

Section::Section(int pageNumber, std::shared_ptr<authorBookData> authors)
    : pageNumber(pageNumber), authors(authors) // Initialization list
{
    // The rest of your constructor code (if any)
}
