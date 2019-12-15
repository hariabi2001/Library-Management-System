#include "author.h"
#include <string>

std::string Author::getFavouriteGenre() const
{
    return favouriteGenre;
}

void Author::setFavouriteGenre(const std::string &value)
{
    favouriteGenre = value;
}

Author::Author(std::string realName, std::string favouriteGenre)
{
    this->realName = realName;
    this->favouriteGenre = favouriteGenre;
}

int Author::findBookNumber(std::vector<Book*> books)
{
    int bookNumber = 0;
    for (Book* book : books){
        if (book->isAuthor(this)) bookNumber++;
    }
    return bookNumber;
}

std::string Author::getRealName() const
{
    return realName;
}

void Author::setRealName(const std::string &value)
{
    realName = value;
}
