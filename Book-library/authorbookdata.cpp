#include "authorbookdata.h"
#include <unordered_map>

oneAuthor::oneAuthor(Author *author, std::string pseudonym)
    :author(author), pseudonym(pseudonym)
{
}

std::unordered_map<std::string, double, CustomHash, std::equal_to<>> oneAuthor::getPartByAuthor() 
{
    std::unordered_map<std::string, double, CustomHash, std::equal_to<>> result;
    result.insert({ author->getRealName(), 1.0 }); // Use 1.0 to ensure a double value
    return result;
}

std::vector<std::string> oneAuthor::getAuthors()
{
    std::vector<std::string> result;
    result.push_back(author->getRealName());
    return result;
}

bool oneAuthor::isAuthor(Author* otherAuthor) 
{
    if (this->author == otherAuthor) {
        return true;
    }
    return false;
}

std::string oneAuthor::getPseudonym() const
{
    return pseudonym;
}

void oneAuthor::setPseudonym(const std::string &value)
{
    pseudonym = value;
}

manyAuthor_firstCoefficient::manyAuthor_firstCoefficient(int coefficient, std::vector<author_pseudonym> authors)
    :manyAuthors(authors), coefficient(coefficient)
{
}

std::unordered_map<std::string, double> manyAuthor_firstCoefficient::getPartByAuthor()
{
    std::unordered_map<std::string, double> result;
    int numberOfParts = authors.size() + coefficient - 1;
    double partMadeByAuthors = 1 / numberOfParts;
    double partMadeByFirstAuthor = coefficient * partMadeByAuthors;
    result.insert({ authors[0].author->getRealName(), partMadeByFirstAuthor });
    for (size_t i = 1; i < authors.size(); i++){
        result.insert({ authors[i].author->getRealName(), partMadeByAuthors });
    }
    return result;
}

std::vector<std::string> manyAuthor_firstCoefficient::getAuthors()
{
    std::vector<std::string> result;
    for (author_pseudonym author : authors){
        result.push_back(author.author->getRealName());
    }
    return result;
}

int manyAuthor_firstCoefficient::getCoefficient() const
{
    return coefficient;
}

void manyAuthor_firstCoefficient::setCoefficient(int value)
{
    coefficient = value;
}

manyAuthors::manyAuthors(std::vector<author_pseudonym> authors)
{
    this->authors = authors;
}

bool manyAuthors::isAuthor(Author *author)
{
    for(author_pseudonym it : authors)
        if (it.author == author) return true;
    return false;
}

std::unordered_map<std::string, double> manyAuthors::getPartByAuthor()
{
    std::unordered_map<std::string, double> result;
    double partMadeByAuthor;
    int numberOfAuthors = authors.size();
    partMadeByAuthor = 1.0 / numberOfAuthors; // Make sure to use a floating-point division here.
    for (author_pseudonym author : authors) {
        result.try_emplace(author.author->getRealName(), partMadeByAuthor);
    }
    return result;
}

std::vector<std::string> manyAuthors::getAuthors()
{
    std::vector<std::string> result;
    for (author_pseudonym author : authors){
        result.push_back(author.author->getRealName());
    }
    return result;
}
