// Two types of operators: unary, binary
// If unary then one branch
// otherwise it has two

#include <string>

class Node;

class Equation
{
  std::string equation;
  class Node;
  Equation();
};

class Node
{
 public:

  Node * left;
  Node * right;
  
  Node()
    {
      left = 0;
      right = 0 ;
    }
};


class Operator : Node
{
  void* (*function_pointer)(Node *, Node *);
  int identifier;
  bool unary;
  bool need_parentheses;
};
  

class Reals : Node
{
  double value;
  bool variable;

};

class Symbol : Node
{
  std::string symbol;
};






  
   
