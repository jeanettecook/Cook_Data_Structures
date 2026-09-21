#include "Calculator.hpp"
#include <string>
#include <cctype>



Calculator::Calculator(const std::string& infix_expression) {
    //store my infix expression
    infix = infix_expression;

}
bool Calculator::isOperand(char op){
    if (isdigit(op)){
        return true;
    }
    else{
        return false;
    }
}

bool Calculator::isOperator(char op){
    if(op == '+' || op == '-'|| op == '*'|| op == '/' || op == '^'){
        return true;
    }
    else{
        return false;
    }
}

    
std::string Calculator::toPostfix() {
    Stack<char> stack_char; 
    // make a function that ignores spaces
    std::string postfix;
    for (int i =0; i < infix.size(); i++){
        char current_char = infix[i];
        if (current_char == ' '){
            continue;
        }
        if (isOperator(current_char)){
            stack_char.push(current_char);
        }
        else if(isOperand(current_char)){
            postfix.push_back(current_char);
        }
    }
    while (!stack_char.empty()){
       char current_char = stack_char.pop();
       postfix.push_back(current_char);
    }

    return postfix;

}



double        Calculator::calculate() const {
    return 0;
}