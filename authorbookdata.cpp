#include "authorbookdata.h"


std::string oneAuthor::getPseudonym() const
{
    return pseudonym;
}

void oneAuthor::setPseudonym(const std::string &value)
{
    pseudonym = value;
}

Author oneAuthor::getAuthor() const
{
    return author;
}

void oneAuthor::setAuthor(const Author &value)
{
    author = value;
}

manyAuthors::manyAuthors(std::unordered_map<Author, std::string> authors)
{
    this->authors = authors;
}

std::vector<Author> manyAuthors::getAuthors() const
{
    return authors;
}

void manyAuthors::setAuthors(const std::vector<Author> &value)
{
    authors = value;
}

manyAuthor_firstCoefficient::manyAuthor_firstCoefficient(int coefficient, std::unordered_map<Author, std::string> authors)
{
    this->coefficient = coefficient;
    this->authors = authors;
}

int manyAuthor_firstCoefficient::getCoefficient() const
{
    return coefficient;
}

void manyAuthor_firstCoefficient::setCoefficient(int value)
{
    coefficient = value;
}
