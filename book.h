#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <unordered_map>
#include <vector>
#include <ctime>
#include <author.h>

class Book
{
private:
    std::string name = "";
    time_t publicationDate;
    std::string genre = "";
    int pageNumber = 0;
public:
    Book(std::string name, time_t publicationDate, std::string genre, int pageNumber);
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
    oneAuthorBook(Author author, std::string name, time_t publicationDate, std::string genre, int pageNumber);
    Author getAuthor() const;
    void setAuthor(const Author &value);
};

class manyAuthorBook : public Book
{
private:
    std::vector<Author> authors;
public:
    manyAuthorBook(std::vector<Author> authors, std::string name, time_t publicationDate, std::string genre, int pageNumber);
    std::vector<Author> getAuthors() const;
    void setAuthors(const std::vector<Author> &value);
};

class manyAuthorBook_bookParts : public manyAuthorBook
{
private:
    std::unordered_map<Author, int> bookPercentDone;
public:
    manyAuthorBook_bookParts(std::unordered_map<Author, int> bookPercentDone, std::string name, time_t publicationDate, std::string genre, int pageNumber);
};

#endif // BOOK_H
