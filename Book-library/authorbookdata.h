#ifndef AUTHORBOOKDATA_H
#define AUTHORBOOKDATA_H
#include <author.h>
#include <unordered_map>
#include <vector>

struct author_pseudonym{
    Author *author;
    std::string pseudonym;
    author_pseudonym(Author *author, std::string pseudonym)
        :author(author), pseudonym(pseudonym){}
};

class authorBookData
{
public:
    virtual std::unordered_map<std::string, double> getPartByAuthor() = 0;
    virtual bool isAuthor(Author* author) = 0;
    virtual std::vector<std::string> getAuthors() = 0;
    virtual ~authorBookData(){}
};

class oneAuthor : public authorBookData
{
private:
    //can be one author, but many pseudonyms for different books, so better to save a pointer to the author
    Author *author;
    std::string pseudonym;
public:
    oneAuthor(Author *author, std::string pseudonym);
    std::unordered_map<std::string, double> getPartByAuthor() override;
    std::vector<std::string> getAuthors() override;
    bool isAuthor(Author* author) override;
    Author getAuthor() const;
    void setAuthor(const Author &value);
    std::string getPseudonym() const;
    void setPseudonym(const std::string &value);
};

class manyAuthors : public authorBookData
{
protected:
    //authors and their pseudonyms
    std::vector<author_pseudonym> authors;
public:
    manyAuthors(std::vector<author_pseudonym> authors);
    bool isAuthor(Author* author) override;
    std::unordered_map<std::string, double> getPartByAuthor() override;
    std::vector<std::string> getAuthors() override;
};

class manyAuthor_firstCoefficient : public manyAuthors
{
private:
    int coefficient;
public:
    manyAuthor_firstCoefficient(int coefficient, std::vector<author_pseudonym> authors);
    std::unordered_map<std::string, double> getPartByAuthor() override;
    std::vector<std::string> getAuthors() override;
    //isAuthor, getAuthors from manyAuthors class should be used
    int getCoefficient() const;
    void setCoefficient(int value);
};


#endif // AUTHORBOOKDATA_H
