#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <algorithm>
#include <sstream>
#include "movie.h"
#include "util.h"


Movie::Movie (std:: string genre, std:: string rating, std:: string name_, double price_, int qty_, std::string category_):Product ( category_, name_,  price_,  qty_){
  genre=genre_;
  rating=rating_;
}

Movie::~Movie(){

}

std::set<std::string> Movie:: keywords() const{
  std::set<std::string> title= parseStringToWords(name_);
  //std::set<std::string> designers=parseStringToWords(designer_);
  //std::set<std::string> combined=setUnion(title, designers);
  return title;
  
}

std::string Movie::displayString() const{
  std:: stringstream ss;
  ss << category_ << "\n" << name_ << "\n"<<genre_<<"\n"<<rating_<<"\n" << price_ << "\n" << qty_ << std::endl;
  return ss.str();
}

void Movie:: dump(std::ostream& os) const{
  os << category_ << "\n" << name_ << "\n"<<genre_<<"\n"<<rating_<<"\n" << price_ << "\n" << qty_ << std::endl;
}