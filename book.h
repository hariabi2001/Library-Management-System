#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <ctime>
#include <author.h>

class Book
{
private:
    std::string name;
    time_t publicationDate;
    std::string genre;
    int pageNumber;

public:
    Book();
    std::string getName() const;
    void setName(const std::string &value);
    time_t getPublicationDate() const;
    void setPublicationDate(const time_t &value);
    std::string getGenre() const;
    void setGenre(const std::string &value);
    int getPageNumber() const;
    void setPageNumber(int value);
};

class oneAuthorBook : public Book
{
private:
    Author author;
public:
    Author getAuthor() const;
    void setAuthor(const Author &value);
};

#endif // BOOK_H
