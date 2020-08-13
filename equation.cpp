#include "types.h"
#include <iostream>
#include <vector>


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

// ((())())()
     
Equation::Equation(std::string in)
{
  
