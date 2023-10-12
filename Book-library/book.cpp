#include "book.h"
#include <unordered_map>
#include <authorbookdata.h>

Book::Book(const std::string& name, time_t publicationDate, const std::string& genre, int pageNumber, authorBookData* authors)
    : name(name), publicationDate(publicationDate), genre(genre), pageNumber(pageNumber), authors(authors)
{
}

std::unordered_map<std::string, double, CustomHash, CustomEqual> Book::getPagesByAuthor() 
{
    std::unordered_map<std::string, double, CustomHash, CustomEqual> authorParts = authors->getPartByAuthor();
    std::unordered_map<std::string, double, CustomHash, CustomEqual> pagesByAuthor;
    double pagesAuthor;
    for (auto it = authorParts.begin(); it != authorParts.end(); it++){
        pagesAuthor = it->second * pageNumber;
        pagesByAuthor.insert({it->first, pagesAuthor});
    }
    return pagesByAuthor;
}

bool Book::isAuthor(Author* author)
{
    return authors->isAuthor(author);
}

std::vector<std::string> Book::getAuthors()
{
    std::vector<std::string> data = authors->getAuthors();
    return data;
}

std::string Book::getName() const
{
    return name;
}

void Book::setName(std::string_view value) 
{
    name = std::string(value);
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

void Book::setGenre(std::string_view value) 
{
    genre.assign(value.data(), value.size());
}


int Book::getPageNumber() const
{
    return pageNumber;
}

void Book::setPageNumber(int value)
{
    pageNumber = value;
}
manyAuthorBook_withSections::manyAuthorBook_withSections(const std::vector<Section>& sections, std::string name, time_t publicationDate, std::string genre, int pageNumber, authorBookData* authors)
    : Book(name, publicationDate, genre, pageNumber, authors), sections(sections)
{
}
