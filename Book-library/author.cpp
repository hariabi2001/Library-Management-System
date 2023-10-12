#include "author.h"
#include <string>

std::string Author::getFavouriteGenre() const
{
    return favouriteGenre;
}

void Author::setFavouriteGenre(std::string_view value)
{
    favouriteGenre = value;
}

Author::Author(const std::string& realName, const std::string& favouriteGenre)
{
    this->realName = realName;
    this->favouriteGenre = favouriteGenre;
}

std::string Author::getRealName() const
{
    return realName;
}

void Author::setRealName(const std::string &value)
{
    realName = value;
}

