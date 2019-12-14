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

Author oneAuthorBook::getAuthor() const
{
    return author;
}

void oneAuthorBook::setAuthor(const Author &value)
{
    author = value;
}

std::vector<Author> manyAuthorBook::getAuthors() const
{
    return authors;
}

void manyAuthorBook::setAuthors(const std::vector<Author> &value)
{
    authors = value;
}

oneAuthorBook::oneAuthorBook(Author author, std::string name, time_t publicationDate, std::string genre, int pageNumber)
    : Book(name, publicationDate, genre, pageNumber), author(author)
{
}

manyAuthorBook::manyAuthorBook(std::vector<Author> authors, std::string name, time_t publicationDate, std::string genre, int pageNumber)
    : Book(name, publicationDate, genre, pageNumber), authors(authors)
{
}

manyAuthorBook_percentDone::manyAuthorBook_percentDone(std::unordered_map<Author, int> bookPercentDone, std::vector<Author> authors, std::string name, time_t publicationDate, std::string genre, int pageNumber)
: manyAuthorBook(authors, name, publicationDate, genre, pageNumber), bookPercentDone(bookPercentDone)
{
}

manyAuthorBook_firstCoefficient::manyAuthorBook_firstCoefficient(int coefficient, std::vector<Author> authors, std::string name, time_t publicationDate, std::string genre, int pageNumber)
    : manyAuthorBook(authors, name, publicationDate, genre, pageNumber), coefficient(coefficient)
{
}

manyAuthorBook_withSections::manyAuthorBook_withSections(std::vector<Section> sections, std::vector<Author> authors, std::string name, time_t publicationDate, std::string genre, int pageNumber)
    : manyAuthorBook(authors, name, publicationDate, genre, pageNumber), sections(sections)
{
}
