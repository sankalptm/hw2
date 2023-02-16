#ifndef CLOTHING_H
#define CLOTHING_H

#include <string>
#include <iostream>
#include <set>
#include "product.h"

class Clothing: public Product{
  public:
    Clothing(std::string size, std::string brand, std::string name_, double price_, int qty_, std::string category_);
    ~Clothing();
    virtual std::set<std::string> keywords() const;
    virtual std::string displayString() const;
    virtual void dump(std::ostream& os) const;
  private:
    std::string size_;
    std::string brand_; 
};

#endif