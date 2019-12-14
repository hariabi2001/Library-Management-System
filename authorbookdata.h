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
public:
    std::unordered_map<Author, int> getPartByAuthor() override;
    Author getAuthor() const;
    void setAuthor(const Author &value);
};

class manyAuthors : public authorBookData
{
protected:
    std::vector<Author> authors;
public:
    std::unordered_map<Author, int> getPartByAuthor() override;
    std::vector<Author> getAuthors() const;
    void setAuthors(const std::vector<Author> &value);
};

class manyAuthor_firstCoefficient : manyAuthors
{
private:
    int coefficient;
public:
    std::unordered_map<Author, int> getPartByAuthor() override;
    int getCoefficient() const;
    void setCoefficient(int value);
};


#endif // AUTHORBOOKDATA_H
