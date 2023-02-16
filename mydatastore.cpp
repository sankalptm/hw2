#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include "product.h"
#include "user.h"
#include "util.h"
#include "mydatastore.h"
#include "product_parser.h"
using namespace std;

MyDataStore::MyDataStore(){

}
MyDataStore::~MyDataStore(){
  map<std::string, User*>::iterator user_delete;
  //vector<Product*>>::iterator product_delete;
  //map<std::string, std::set<Product*>::iterator key_delete;
  for (user_delete=customer.begin(); user_delete!= customer.end(); user_delete++){
    delete user_delete->second;
  }
  for (size_t i=0; i < collection.size();i++){
    delete collection[i];
  }
  /*for (key_delete=key.begin(); key_delete!=key.end(); key_delete++){
    for (Product*i : key_delete->second){
      delete i;
    }
  }*/
}
void MyDataStore:: addProduct(Product* p){
  collection.push_back(p);
  set<std::string> terms=p->keywords();
  //finds all the words in the product name and stores in a set
  //vector<std::string> terms_as_vector(terms.begin(), terms.end());
  //should i pass in the getName for this
  //size_t num_terms= terms.size();
  //product can have multiple key words
  set<Product*> word_pairs;
  set<string>::iterator it;
 /* for (size_t i=0; i < terms.size(); i++){
    it= terms.find(i);
    if (key.find(*it)==key.end()){
      key.insert(make_pair(*it,word_pairs.insert(p)));
    }
    else{
      key[*it].insert(p);
    }*/

    for (it=terms.begin(); it!= terms.end(); it++){
      string temp;
      temp=convToLower(*it);
      map<string, set<Product*>>::iterator key_it= key.find(temp);
     
      if (key_it!=key.end()){
        //cout<<"Added "<<*it<<endl;
        
        key[temp].insert(p);
      }
      else {
        //cout<<"Added "<<*it<<endl;
        set<Product*> new_set;
        new_set.insert(p);
        key[temp] = new_set;
      }

    }
    // IF key map does not contain the key word
    // then, create a new set, add the product and store in the map
    // ELSE -> get the existing set from the map, add the product and store 
    // back in the map
   //key.insert(make_pair(terms_as_vector[i], word_pairs.insert(p)));
    //make one index for each term and push back the product for each
  
}
void MyDataStore:: addUser(User* u){
  customer.insert(make_pair(u->getName(), u));
  //cart.insert(make_pair(u.getName(), collection));


}
std::vector<Product*> MyDataStore:: search(std::vector<std::string>& terms, int type){
  std::vector<Product*> answerList;
  //std::vector<Product*>::iterator it = collection.begin(); 
  //keep track of which products have which keywords 
  // you need to build a vector of products 
  //continue to setUnion or setIntersect until 
  set<Product*> combined;
  if (type==1){
    
    for (size_t i=0; i < terms.size(); i++){
      if (key.find(terms[i])!=key.end()){
        //map<string, set<Product*>>::iterator it =key.find(terms[i]);
        //access the specific value of the map 
        combined =setUnion(combined, key[terms[i]]);
      }
    }
    
  }
  else if (type==0) {
    //set <Product*> combined;
    if (key.find(terms[0])!=key.end()){
      combined=(key[terms[0]]);
    }
    
    for (size_t i=1; i < terms.size(); i++){
      //cout<<"Found"<<terms[i]<<endl;
      if (key.find(terms[i])!=key.end()){
        //cout<<"Found"<<terms[i]<<endl;
        //map<string, set<Product*>>::iterator it =key.find(terms[i]);
        //access the specific value of the map 
        combined =setIntersection(combined, key[terms[i]]);
      }
    }
  }
  else {
    vector<Product*> empty;
    cout <<"Invalid request"<<endl;
    return empty;
  }
  //answerList(combined.begin(), combined.end());
  /*for (size_t j=0; j<combined.size(); j++){
    answerList.push_back(combined.find(j));
  }*/
  set<Product*>::iterator it;
  for (it=combined.begin(); it!=combined.end(); it++){
    answerList.push_back(*it);
  }
  return answerList;


  

}
void MyDataStore:: addToCart(string username, Product* p){
  //two cases if user exists or user doesnt exists
  //use an iterator to find user
  //look at slide 20 lecture 5 for information on an iterator
  if (cart.find(username)!= cart.end()){
    cart[username].push_back(p);// push product into vector
  }
  else {
    vector <Product*> updated;
    updated.push_back(p);
    cart.insert(make_pair(username, updated));
  }
 

}

void MyDataStore:: dump(std::ostream& ofile){
  //iterate through collection and call collection[i]->dump(os)
  //ofile <<"<products>"<<"\n"<< category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << endl;
  ofile<<"<products>"<<"\n";
  for (size_t i=0; i< collection.size(); i++){
    collection[i]->dump(ofile);
  }
  ofile<<"</products>"<<"\n"<<"<users>"<<"\n";
  for (map<string, User*>::iterator it =customer.begin(); it!=customer.end();it++){
    if (it->second!=NULL){
      (*it).second->dump(ofile);
    }
  }
  ofile<<"</users>"<<"\n";
}
void MyDataStore::BuyCart(string username){
  map<string, vector<Product*>>::iterator it = cart.find(username);

  if (cart.find(username) == cart.end()){
    cout << "Invalid username" << endl;
    return;
  }


  vector<Product*> remaining;
  if (it != cart.end()){
    vector<Product*>::iterator secondary= it->second.begin();
    map<string, User*>::iterator customer_exists=customer.find(username);
    if (customer_exists!= customer.end()){
      for (secondary; secondary!=it->second.end();secondary++ ){
      
        if ((*secondary)->getQty()>0 && customer[username]->getBalance()>(*secondary)->getPrice()){
          (*secondary)->subtractQty(1);
          customer[username]->deductAmount((*secondary)->getPrice());
        }
        else {
          remaining.push_back(*secondary);
        }
      }
      if (remaining.size()>0){
        cart[username]=remaining;
      }
      else {
        cart.erase(username);
      }
    }
  }
  else {
    cout<<"Invalid username"<<endl;
    return;
  }

}
void MyDataStore::ViewCart(string username){
  if (cart.find(username)!= cart.end()){
    for (size_t i=0; i<cart[username].size(); i++){
      cout <<cart[username][i]<<endl;
    }
  }
}