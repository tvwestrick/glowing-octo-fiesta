#include "types.h"
#include <iostream>
#include <vector>
#include <cassert>


//#include <pair> // couldn't find

void elim_spaces(std::string &in) {
    std::string nospaces;
    for(int i = 0; i < in.size(); ++i) {
        if(in.at(i) != ' ' && in.at(i) != ' ')
            nospaces += in.at(i);
    }
    in = nospaces;
}

int tag_parentheses( std::vector<int> &lhs_parentheses, std::vector<int> &rhs_parentheses, std::string in)
{
    assert(lhs_parentheses.empty() && rhs_parentheses.empty());
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
    
    assert(lhs_parentheses.size() == rhs_parentheses.size());
    // not a sufficient condition to see if pairs are matchable
    // maybe make another function to test this
    
    std::vector<std::pair<int, int>> pairs;
    std::pair<int, int> single_pair;
    int original_size = static_cast<int>(lhs_parentheses.size());
    
    
    // DOES NOT ACCOUNT FOR POSSIBLE INVALID SYNTAX
    
    
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
     
Equation::Equation(std::string eq_in) {
    equation = eq_in;
    
}
