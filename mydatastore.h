#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "datastore.h"
#include "util.h"
#include "product_parser.h"


class MyDataStore: public DataStore{
  public:
  MyDataStore();
  ~MyDataStore();
  void addProduct(Product* p);
  void addUser(User* u); //add user map and user cart
  std::vector<Product*> search(std::vector<std::string>& terms, int type);
  void dump(std::ostream& ofile);
  void addToCart(std::string username, Product *p);
  void BuyCart(std::string username);
  void ViewCart(std::string username);
  private:
  std::vector<Product*> collection; //contains everything
  std::map<std::string, User*> customer;
  std::map<std::string, std::vector<Product*>> cart;
  std::map<std::string, std::set<Product*>> key;

   
};

#endif


