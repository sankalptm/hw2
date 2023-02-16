#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{

  std::set<T> intersected; 
  typename std::set<T> ::iterator it; 
  for (it=s1.begin(); it!= s1.end(); ++it){
    if (s2.find(*it)!=s2.end()){
      intersected.insert(*it);
    }
  }
  return intersected;


}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{

  std:: set<T> unified;
  typename std:: set<T>::iterator it;
  for (it =s1.begin(); it !=s1.end(); ++it){
    unified.insert(*it);
  }
  typename std:: set<T>::iterator second;
  for (second= s2.begin(); second !=s2.end(); ++second){
    unified.insert(*second);
  }


  return unified; 
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
