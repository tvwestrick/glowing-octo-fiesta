#include "types.h"
#include <iostream>
#include <vector>
//#include <pair> couldn't find


int tag_parentheses( std::vector<int> &lhs_parentheses, std::vector<int> &rhs_parentheses, std::string in)
{
  
  int lhs_iterator = 0;
  int rhs_iterator = 0;
  int length = static_cast<int>(in.length());
  for (int i = 0; i != length; ++i)
    {
      if (in[i] == '(')
	{
	  lhs_parentheses[lhs_iterator++] = i;
	}
      else if (in[i] == ')')
	{
	  rhs_parentheses[rhs_iterator++] = i;
	}
    }
  if (rhs_iterator != lhs_iterator)
    {
      std::cout << "Unmatched parentheses \n";
        return -1;
    }
  else
    return 0;
}

std::vector<std::pair<int, int>> match_pairs(std::vector<int> lhs_parentheses, std::vector<int> rhs_parentheses) {
    
    std::vector<std::pair<int, int>> pairs;
    
    std::pair<int, int> single_pair;
    
    int original_size = static_cast<int>(lhs_parentheses.size());
    
    while(pairs.size() != original_size) {
        single_pair.first = lhs_parentheses.back();
        int i = 0;
        for(; rhs_parentheses[i] <= single_pair.first; ++i)
        single_pair.second = i;
        pairs.push_back(single_pair);
        lhs_parentheses.pop_back();
        rhs_parentheses.erase(rhs_parentheses.begin() + i);
    }
    return pairs;
}

// ((())())()
     
Equation::Equation(std::string in)
{
  
}
