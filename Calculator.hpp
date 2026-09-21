#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "Stack.hpp"

class Calculator {
public:
    Calculator(const std::string& infix = "");

    
    std::string toPostfix(); // Throws std::logic_error
    double      calculate() const;

private:
    std::string infix;

};

#endif
