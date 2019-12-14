#ifndef AUTHORBOOKDATA_H
#define AUTHORBOOKDATA_H
#include <author.h>
#include <unordered_map>
#include <vector>


class authorBookData
{
public:
    virtual std::unordered_map<Author, int> getPartByAuthor() = 0;
    virtual ~authorBookData() = 0;
};

class oneAuthor : public authorBookData
{
private:
    Author author;
    std::string pseudonym;
public:
    oneAuthor(Author author);
    std::unordered_map<Author, int> getPartByAuthor() override;
    Author getAuthor() const;
    void setAuthor(const Author &value);
    std::string getPseudonym() const;
    void setPseudonym(const std::string &value);
};

class manyAuthors : public authorBookData
{
protected:
    //authors and their pseudonyms
    std::unordered_map<Author, std::string> authors;
public:
    manyAuthors(std::unordered_map<Author, std::string> authors);
    std::unordered_map<Author, int> getPartByAuthor() override;
    std::vector<Author> getAuthors() const;
    void setAuthors(const std::vector<Author> &value);
};

class manyAuthor_firstCoefficient : manyAuthors
{
private:
    int coefficient;
public:
    manyAuthor_firstCoefficient(int coefficient, std::unordered_map<Author, std::string> authors);
    std::unordered_map<Author, int> getPartByAuthor() override;
    int getCoefficient() const;
    void setCoefficient(int value);
};


#endif // AUTHORBOOKDATA_H
