#ifndef AUTHOR_H
#define AUTHOR_H
#include <string>
#include <vector>
#include <book.h>


class Author
{
private:
    std::string realName;
    std::string favouriteGenre;
public:
    Author(std::string realName, std::string favouriteGenre);
    int findBookNumber(std::vector<Book*> books);
    std::string getRealName() const;
    void setRealName(const std::string &value);
    std::string getFavouriteGenre() const;
    void setFavouriteGenre(const std::string &value);
};

#endif // AUTHOR_H
