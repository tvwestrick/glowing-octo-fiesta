#include <iostream>
#include <vector>
#include <string>

#include "equation.h" // ?? is this right ??

using namespace std;

void spaces_test();



int main() {
    return 0;
}


void spaces_test() {
    std::vector<std::string> inputs1 = {"abc", " a b c ", "  a      b  c", " a       bc  "};
    
    for(int i = 0; i < inputs1.size(); ++i) {
        elim_spaces(inputs1.at(i));
        if(inputs1.at(i) == "abc")
            std::cout << "Elim Spaces Test " << i << " PASSED\n";
        else {
            std::cout << "Elim Spaces Test " << i << " FAILED\n";
        }
    }
    
    std::vector<std::string> inputs2 = {"", "   ", "    "};
    
    for(int i = 0; i < inputs2.size(); ++i) {
        elim_spaces(inputs2.at(i));
        if(inputs2.at(i) == "")
            std::cout << "Elim Spaces Test " << i+inputs1.size() << " PASSED\n";
        else {
            std::cout << "Elim Spaces Test " << i+inputs1.size() << " FAILED\n";
        }
    }
}
