#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <set>
#include "product.h"

class Book: public Product{
  public:
    Book(std::string ISBN, std::string author, std::string name_, double price_, int qty_, std::string category_);
    ~Book();
    virtual std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;
    virtual bool isMatch(std::vector<std::string>& searchTerms) const;
  private:
    std::string ISBN_;
    std::string author_; 
};

#endif