#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "Stack.hpp"
#include <string>
#include <vector>

class Calculator {
public:
    Calculator(const std::string& infix = "");

    
    std::string toPostfix(); // Throws std::logic_error
    double      calculate() const;

private:
    std::string infix;
    // postfix split into tokens ("2974", "12", "+", ...) so calculate()
    // can tell where one multi-digit number ends and the next begins
    std::vector<std::string> postfix_tokens;

    bool isOperand(char);
    bool isOperator(char);
    bool isOpenBracket(char);
    bool isCloseBracket(char);
    bool bracketsMatch(char open, char close);
    bool bracketsBalanced();
    int  precedence(char);

};

#endif
