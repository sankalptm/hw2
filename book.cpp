#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <algorithm>
#include <sstream>
#include "book.h"
#include "util.h"
using namespace std;

Book::Book (std:: string ISBN, std:: string author,std:: string name_, double price_, int qty_, std::string category_):Product ( category_, name_,  price_,  qty_){
  ISBN=ISBN_;
  author=author_;
}

Book::~Book(){

}

std::set<std::string> Book:: keywords() const {
  std::set<std::string> title= parseStringToWords(name_);
  std::set<std::string> authors=parseStringToWords(author_);
  std::set<std::string> combined=setUnion(title, authors);
  return combined;
  
}
bool Book:: isMatch(std::vector<std::string>& searchTerms) const{
  return false;
}

std::string Book::displayString() const{
  //category, name, price, quantity, ISBN, author
  std:: stringstream ss;
  ss << category_ << "\n" << name_ <<"\n"<< price_ << "\n" << qty_ <<"\n"<<ISBN_<<"\n"<<author_<< std::endl;
  return ss.str();
}

void Book:: dump(std::ostream& os) const{
  os << category_ << "\n" << name_ <<"\n"<< price_ << "\n" << qty_ <<"\n"<<ISBN_<<"\n"<<author_<< std::endl;
}