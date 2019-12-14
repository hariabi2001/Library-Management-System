#include "book.h"

Book::Book(std::string name, time_t publicationDate, std::string genre, int pageNumber)
{
    this->name = name;
    this->publicationDate = publicationDate;
    this->genre = genre;
    this->pageNumber = pageNumber;
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

oneAuthorBook::oneAuthorBook(Author author, std::string name, time_t publicationDate, std::string genre, int pageNumber)
    : Book(name, publicationDate, genre, pageNumber), author(author)
{
}

Author oneAuthorBook::getAuthor() const
{
    return author;
}

void oneAuthorBook::setAuthor(const Author &value)
{
    author = value;
}


manyAuthorBook::manyAuthorBook(std::vector<Author> authors, std::string name, time_t publicationDate, std::string genre, int pageNumber)
: Book(name, publicationDate, genre, pageNumber), authors(authors)
{
}

std::vector<Author> manyAuthorBook::getAuthors() const
{
    return authors;
}

void manyAuthorBook::setAuthors(const std::vector<Author> &value)
{
    authors = value;
}
