#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;


void remove_sub(std::string &base, std::string to_remove) {
    assert(!base.empty() && !to_remove.empty());
    int sub_size = static_cast<int>(to_remove.size());
    while(base.find(to_remove) != string::npos) {
        base.erase(base.find(to_remove), sub_size);
    }
}

void remove_char(std::string &base, char to_remove) {
    assert(!base.empty());
    while(base.find(to_remove) != string::npos) {
        base.erase(base.find(to_remove), 1);
    }
}


int valid_symbols(std::string in, std::vector<char> vars) {
    
    assert(!in.empty());
    
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
    assert(!in.empty());
    // checks if parentheses are in legal arrangement
    
    // counts parentheses from left to right, num_right cannot exceed num_left
    int num_left = 0;
    int num_right = 0;
    for(auto i = 0; i < in.size(); ++i) {
        if(in.at(i) == '(') num_left++;
        if(in.at(i) == ')') num_right++;
        if(num_right > num_left) {
            std::cout << "Invalid Equation\n";
            return -1;
        }
    }
    
    // counts parentheses from right to left, num_left cannot exceed num_right
    num_left = 0;
    num_right = 0;
    for(auto i = in.size()-1; i >= 0; ++i) {
        if(in.at(i) == '(') num_left++;
        if(in.at(i) == ')') num_right++;
        if(num_left > num_right) {
            std::cout << "Invalid Equation\n";
            return -1;
        }
    }
    
    return 0;
}

int validate_eq(std::string &in, std::vector<char> vars) {
    assert(!in.empty());
    if(valid_symbols(in, vars) == 0 && valid_syntax(in) == 0) return 0;
    return -1;
}
