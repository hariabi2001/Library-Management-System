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
#include <functional> // For custom hash function
using namespace std;
// Define custom hash function for Author class
namespace std {
    template <>
    struct hash<Author> {
        std::size_t operator()(const Author& author) const {
            return std::hash<std::string>{}(author.getName());
        }
    };
}

class Book {
private:
    std::string name;
    time_t publicationDate;
    std::string genre;
    int pageNumber;
    authorBookData* authors;

public:
    Book(std::string name, time_t publicationDate, std::string genre, int pageNumber, authorBookData* authors);
    std::unordered_map<string, double, hash<string>> getPagesByAuthor();
    bool isAuthor(Author* author);
    std::vector<std::string> getAuthors();

    std::string getName() const;
    void setName(const std::string& value);
    time_t getPublicationDate() const;
    void setPublicationDate(const time_t& value);
    std::string getGenre() const;
    void setGenre(const std::string& value);
    int getPageNumber() const;
    void setPageNumber(int value);
};

class manyAuthorBook_withSections : public Book {
private:
    std::vector<Section> sections;

public:
    manyAuthorBook_withSections(std::vector<Section> sections, std::string name, time_t publicationDate, std::string genre, int pageNumber, authorBookData* authors);
};

#endif // BOOK_H
