#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
 REQUIRES: base and to_remove be non-empty strings
 MODIFIRES: erases any occurences of to_remove from base
*/
void remove_sub(std::string &base, std::string to_remove);

/*
 REQUIRES: base is a non-empty string, to_remove is a valid char
 MODIFIRES: erases any occurences of to_remove from base
*/
void remove_char(std::string &base, char to_remove);

/*
 REQUIRES: in is a non-empty string
 EFFECTS: returns 0 if all symbols and functions are valid, -1 if not
*/
int valid_symbols(std::string in, std::vector<char> vars);

/*
 REQUIRES: in is a non-empty string
 EFFECTS: returns 0 if parentheses are in legal arrangement, -1 if not
*/
int valid_syntax(std::string &in);


/*
 REQUIRES: in is a non-empty string
 EFFECTS: returns 0 if equation is valid, -1 if not
*/
int validate_eq(std::string &in, std::vector<char> vars);
