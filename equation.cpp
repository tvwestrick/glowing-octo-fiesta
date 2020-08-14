#include "types.h"
#include <iostream>
#include <vector>
#include <pair>


int tag_parentheses( std::vector<int> &lhs_parentheses, std::vector<int> &rhs_parentheses, std::string in)
{
  
  int lhs_iterator = 0;
  int rhs_iterator = 0;
  int length = in.length();
  for (int i = 0; i != length; ++i)
    {
      if (in[i] == '(')
	{
	  lhs[lhs_iterator++] = i;
	}
      else if (in[i] == ')')
	{
	  rhs[rhs_iterator++] = i;
	}
    }
  if (rhs_iterator != lhs_iterator)
    {
      std::cout << "Unmatched parentheses \n";
      return -1
    }
  else
    return 0;
}

std::vector<std::pair<int>> match_pairs(std::vector<int> lhs_parentheses, std::vector<int> rhs_parentheses) {
    
    std::vector<std::pair<int>> pairs;
    
    std::pair<int>> single_pair;
    
    int orignal_length = lhs_parentheses.length();
    
    while(pairs.length() != orignal_length) {
        single_pair.first = *lhs_parentheses.back();
        int i = 0;
        for(; rhs_parentheses[i] <= single_pair.first; ++i)
        single_pair.second = i;
        pairs.push_back(single_pair);
        lhs_parentheses.pop_back();
        rhs_parentheses.erase(rhs_parentheses.begin() + i);
    }
}

// ((())())()
     
Equation::Equation(std::string in)
{
  
