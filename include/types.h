// Two types of operators: unary, binary
// If unary then one branch
// otherwise it has two

#include <string>
#include <vector>

class Node
{
public:
    Node * left;
    Node * right;
    int identifier;
    bool is_operator;
    std::string plaintext;
    
    Node() {
      left = 0;
      right = 0 ;
    }
};

class Equation
{
public:
    std::string equation;
    char dep_var;
    std::vector<char> indep_vars;
    // ex:  z = x^2 + y^2
    // equation = "z = x^2 + y^2"
    // dep_var = 'z', indep_vars = <'x', 'y'>
    Equation(std::string eq_in);
    Node root;
};

//class Operator : Node
//{
//    void* (*function_pointer)(Node *, Node *);
//    int identifier;
//    bool unary;
//    bool need_parentheses;
//
//    Operator(int id_in, bool un_in, double need_in) : identifier(id_in), unary(un_in), need_parentheses(need_in) {}
//};
  

//class Reals : Node
//{
//  double value;
//  bool variable;
//};
//
//class Symbol : Node
//{
//  std::string symbol;
//};






  
   
