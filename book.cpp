#include "book.h"

Book::Book(std::string name, time_t publicationDate, std::string genre, int pageNumber, std::shared_ptr<authorBookData> authors)
    : name(name), publicationDate(publicationDate), genre(genre), pageNumber(pageNumber), authors(authors)
{
}

std::vector<author_page> Book::getPagesByAuthor()
{
    authors->getPartByAuthor();
}

std::string Book::getName() const
{
    return name;
}

void Book::setName(const std::string &value)
{
    name = value;
}

time_t Book::getPublicationDate() const
{
    return publicationDate;
}

void Book::setPublicationDate(const time_t &value)
{
    publicationDate = value;
}

std::string Book::getGenre() const
{
    return genre;
}

void Book::setGenre(const std::string &value)
{
    genre = value;
}

int Book::getPageNumber() const
{
    return pageNumber;
}

void Book::setPageNumber(int value)
{
    pageNumber = value;
}
manyAuthorBook_withSections::manyAuthorBook_withSections(std::vector<Section> sections, std::string name, time_t publicationDate, std::string genre, int pageNumber, std::shared_ptr<authorBookData> authors)
    : Book(name, publicationDate, genre, pageNumber, authors), sections(sections)
{
}
