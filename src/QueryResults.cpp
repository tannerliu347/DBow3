/**
 * File: QueryResults.cpp
 * Date: March, November 2011
 * Author: Dorian Galvez-Lopez
 * Description: structure to store results of database queries
 * License: see the LICENSE.txt file
 *
 */

#include <iostream>
#include <fstream>
#include "QueryResults.h"

using namespace std;

namespace DBoW3
{

// ---------------------------------------------------------------------------

ostream & operator<<(ostream& os, const Result& ret )
{
  os << "<EntryId: " << ret.Id << ", Score: " << ret.Score << ">";
  return os;
}

// ---------------------------------------------------------------------------

ostream & operator<<(ostream& os, const QueryResults& ret )
{
  if(ret.size() == 1)
    os << "1 result:" << endl;
  else
    os << ret.size() << " results:" << endl;
    
  QueryResults::const_iterator rit;
  for(rit = ret.begin(); rit != ret.end(); ++rit)
  {
    if (ret.getDbSize() - rit->Id <= 5)
      continue;
    os << *rit;
    if(rit + 1 != ret.end()) os << endl;
  }
  return os;
}

// ---------------------------------------------------------------------------

int QueryResults::getDbSize() const {
  return dbSize_;
}

void QueryResults::setDbSize(int dbSize) {
  dbSize_ = dbSize;
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

void QueryResults::saveM(const std::string &filename) const
{
  fstream f(filename.c_str(), ios::out);
  
  QueryResults::const_iterator qit;
  for(qit = begin(); qit != end(); ++qit)
  {
    f << qit->Id << " " << qit->Score << endl;
  }
  
  f.close();
}

// ---------------------------------------------------------------------------

} // namespace DBoW3

