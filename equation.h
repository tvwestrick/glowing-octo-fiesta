#include <iostream>

using namespace std;

/*
 REQUIRES: lhs_parentheses and rhs_parentheses to be empty int vectors
 MODIFIRES: lhs_parentheses and rhs_parentheses are filled with indices
    of parenteheses from string
 EFFECTS: returns 0 if sucessful, -1 if there are mismatched parentheses
*/

int tag_parentheses( std::vector<int> &lhs_parentheses, std::vector<int> &rhs_parentheses, std::string in);


/*
 REQUIRES: lhs_parentheses and rhs_parentheses to be filled with matchable parentheses
 EFFECTS: returns vector of pairs of ints corresponding to each parenthesis pair
*/
std::vector<std::pair<int, int>> match_pairs(std::vector<int> lhs_parentheses, std::vector<int> rhs_parentheses);

