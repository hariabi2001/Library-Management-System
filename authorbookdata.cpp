#include "authorbookdata.h"

authorBookData::authorBookData()
{

}


Author oneAuthor::getAuthor() const
{
    return author;
}

void oneAuthor::setAuthor(const Author &value)
{
    author = value;
}

std::vector<Author> manyAuthors::getAuthors() const
{
    return authors;
}

void manyAuthors::setAuthors(const std::vector<Author> &value)
{
    authors = value;
}

int manyAuthor_firstCoefficient::getCoefficient() const
{
    return coefficient;
}

void manyAuthor_firstCoefficient::setCoefficient(int value)
{
    coefficient = value;
}
