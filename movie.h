#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
#include <set>
#include "product.h"

class Movie: public Product{
  public:
    Movie(std::string genre, std::string rating, std::string name_, double price_, int qty_, std::string category_);
    ~Movie();
    virtual std::set<std::string> keywords() const;
    virtual std::string displayString() const;
    virtual void dump(std::ostream& os) const;
  private:
    std::string genre_;
    std::string rating_; 
};

#endif