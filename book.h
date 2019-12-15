#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <unordered_map>
#include <vector>
#include <ctime>
#include <author.h>
#include <authorbookdata.h>
#include <section.h>
#include <memory>

class Book
{
private:
    std::string name;
    time_t publicationDate;
    std::string genre;
    int pageNumber;
    std::shared_ptr<authorBookData> authors;

public:
    Book(std::string name, time_t publicationDate, std::string genre, int pageNumber, std::shared_ptr<authorBookData> authors);
    std::unordered_map<std::string, double> getPagesByAuthor();
    bool isAuthor(Author* author);

    std::string getName() const;
    void setName(const std::string &value);
    time_t getPublicationDate() const;
    void setPublicationDate(const time_t &value);
    std::string getGenre() const;
    void setGenre(const std::string &value);
    int getPageNumber() const;
    void setPageNumber(int value);
};

class manyAuthorBook_withSections : public Book
{
private:
    std::vector<Section> sections;
public:
    manyAuthorBook_withSections(std::vector<Section> sections, std::string name, time_t publicationDate, std::string genre, int pageNumber, std::shared_ptr<authorBookData> authors);
};

#endif // BOOK_H
