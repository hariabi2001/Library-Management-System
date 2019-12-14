#ifndef AUTHOR_H
#define AUTHOR_H
#include <string>


class Author
{
private:
    std::string realName;
    std::string pseudonymName;
    std::string favouriteGenre;
public:
    Author(std::string realName, std::string pseudonymName, std::string favouriteGenre);
    std::string getRealName() const;
    void setRealName(const std::string &value);
    std::string getPseudonymName() const;
    void setPseudonymName(const std::string &value);
    std::string getFavouriteGenre() const;
    void setFavouriteGenre(const std::string &value);
};

#endif // AUTHOR_H
