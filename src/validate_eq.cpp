#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void remove_sub(std::string &base, std::string to_remove) {
    int sub_size = static_cast<int>(to_remove.size());
    while(base.find(to_remove) != string::npos) {
        base.erase(base.find(to_remove), sub_size);
    }
}

void remove_char(std::string &base, char to_remove) {
    while(base.find(to_remove) != string::npos) {
        base.erase(base.find(to_remove), 1);
    }
}


int valid_symbols(std::string in, std::vector<char> vars) {
    
    // we erase all legal phrases and chars, and if nothing is left, then all symbols are valid
    std::string in_check = in; // copy input equation
    
    vector<string> valid_funcs = {"arcsin", "arccos", "arctan", "sqrt", "sinh", "cosh", "tanh", "sin", "cos", "tan", "csc", "sec", "cot", "log", "ln"}; // this order matters
    
    // erase all math symbols
    std::vector<char> math_syms = {'1','2','3','4','5','6','7','8','9','0','+','-','*','/','^','(',')'};
    
    for(int i = 0; i < math_syms.size(); ++i) {
        remove_char(in_check, math_syms.at(i));
    }
    
    // erase all valid funcs (from biggest to smallest names)
    for(int i = 0; i < valid_funcs.size(); ++i) {
        remove_sub(in_check, valid_funcs.at(i));
    }
    
    // erase all variables
    for(int i = 0; i < vars.size(); ++i) {
        remove_char(in_check, vars.at(i));
    }
    
    
    if(in_check.empty())    return 0;
    
    cout << "Invalid Equation\n";
    return -1;

}



int valid_syntax(std::string &in) {
    // checks if parentheses are in legal arrangement
    return -1;
}

int validate_eq(std::string &in, std::vector<char> vars) {
    if(valid_symbols(in, vars) == 0 && valid_syntax(in) == 0) return 0;
    return -1;
}
