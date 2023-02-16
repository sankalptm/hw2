#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <algorithm>
#include <sstream>
#include "clothing.h"
#include "util.h"


Clothing::Clothing (std:: string size, std:: string brand, std:: string name_, double price_, int qty_, std::string category_):Product ( category_, name_,  price_,  qty_){
  size=size_;
  brand=brand_;
}

Clothing::~Clothing(){

}

std::set<std::string> Clothing:: keywords() const{
  std::set<std::string> title= parseStringToWords(name_);
  std::set<std::string> designers=parseStringToWords(brand_);
  std::set<std::string> combined=setUnion(title, designers);
  return combined;
  
}

std::string Clothing::displayString() const{
  std:: stringstream ss;
  ss << category_ << "\n" << name_ << "\n"<<brand_<<"\n"<<size_<<"\n" << price_ << "\n" << qty_ << std::endl;
  return ss.str();
}

void Clothing:: dump(std::ostream& os) const{
  os << category_ << "\n" << name_ << "\n"<<brand_<<"\n"<<size_<<"\n" << price_ << "\n" << qty_ << std::endl;
}