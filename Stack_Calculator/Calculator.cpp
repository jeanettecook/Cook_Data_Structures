#include "Calculator.hpp"
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <stdexcept>

// Helper functions live in this file only, so Calculator.hpp does not
// need to declare them.

static bool isOperandChar(char c){
    return isdigit(c);
}

static bool isOperatorChar(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

static bool isOpenBracket(char c){
    return c == '(' || c == '[' || c == '{';
}

static bool isCloseBracket(char c){
    return c == ')' || c == ']' || c == '}';
}

// true if the open and close bracket are the same kind
static bool bracketsMatch(char open, char close){
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// every close bracket must match the most recent unmatched open bracket,
// and no open brackets can be left over at the end
static bool bracketsBalanced(const std::string& expr){
    Stack<char> brackets;
    for (int i = 0; i < expr.size(); i++){
        char current_char = expr[i];
        if (isOpenBracket(current_char)){
            brackets.push(current_char);
        }
        else if (isCloseBracket(current_char)){
            if (brackets.empty()){
                return false;
            }
            char open = brackets.pop();
            if (!bracketsMatch(open, current_char)){
                return false;
            }
        }
    }
    return brackets.empty();
}

static int precedence(char op){
    if (op == '^'){
        return 3;
    }
    if (op == '*' || op == '/' || op == '%'){
        return 2;
    }
    if (op == '+' || op == '-'){
        return 1;
    }
    return 0; // brackets
}

// Converts infix to postfix, returned as separate tokens ("2974", "12", "+", ...)
// so multi-digit numbers stay apart. Throws std::logic_error on bad input.
static std::vector<std::string> toPostfixTokens(const std::string& infix){
    // check for bad characters first
    for (int i = 0; i < infix.size(); i++){
        char current_char = infix[i];
        if (!(current_char == ' ' || isOperandChar(current_char) || isOperatorChar(current_char)
              || isOpenBracket(current_char) || isCloseBracket(current_char))){
            throw std::logic_error("Error: invalid character in the expression");
        }
    }

    if (!bracketsBalanced(infix)){
        throw std::logic_error("Error: invalid parentheses");
    }

    Stack<char> stack_char;
    std::vector<std::string> tokens;
    int operand_count = 0; // how many values would be on the stack when evaluating

    for (int i = 0; i < infix.size(); i++){
        char current_char = infix[i];
        if (current_char == ' '){
            continue;
        }
        if (isOperandChar(current_char)){
            // read the whole number, not just one digit
            std::string number;
            while (i < infix.size() && isOperandChar(infix[i])){
                number.push_back(infix[i]);
                i++;
            }
            i--; // the for loop will move past the last digit
            tokens.push_back(number);
            operand_count++;
        }
        else if (isOpenBracket(current_char)){
            stack_char.push(current_char);
        }
        else if (isCloseBracket(current_char)){
            // pop until we reach the matching open bracket
            while (!isOpenBracket(stack_char.top())){
                tokens.push_back(std::string(1, stack_char.pop()));
                operand_count--;
            }
            stack_char.pop(); // throw away the open bracket
        }
        else if (isOperatorChar(current_char)){
            // each operator needs a value on its left
            if (operand_count < 1){
                throw std::logic_error("Error: invalid number of operands");
            }
            // ^ is right associative, the rest are left associative
            while (!stack_char.empty() && !isOpenBracket(stack_char.top()) &&
                   (precedence(stack_char.top()) > precedence(current_char) ||
                    (precedence(stack_char.top()) == precedence(current_char) && current_char != '^'))){
                tokens.push_back(std::string(1, stack_char.pop()));
                operand_count--;
            }
            stack_char.push(current_char);
        }
    }
    while (!stack_char.empty()){
        tokens.push_back(std::string(1, stack_char.pop()));
        operand_count--;
    }

    // a valid expression leaves exactly one value
    if (operand_count != 1){
        throw std::logic_error("Error: invalid number of operands");
    }

    return tokens;
}



Calculator::Calculator(const std::string& infix_expression) {
    //store my infix expression
    infix = infix_expression;

}

std::string Calculator::toPostfix() {
    std::vector<std::string> tokens = toPostfixTokens(infix);
    std::string postfix;
    for (int i = 0; i < tokens.size(); i++){
        postfix += tokens[i];
    }
    return postfix;
}

double        Calculator::calculate() const {
    std::vector<std::string> tokens = toPostfixTokens(infix);
    Stack<double> values;
    for (int i = 0; i < tokens.size(); i++){
        const std::string& token = tokens[i];
        if (isdigit(token[0])){
            values.push(std::stod(token));
            continue;
        }
        double right = values.pop();
        double left = values.pop();

        switch (token[0]){
            case '+': values.push(left + right); break;
            case '-': values.push(left - right); break;
            case '*': values.push(left * right); break;
            case '/':
                if (right == 0){
                    throw std::logic_error("Error: division by zero");
                }
                values.push(left / right);
                break;
            case '%':
                if (right == 0){
                    throw std::logic_error("Error: division by zero");
                }
                values.push(std::fmod(left, right));
                break;
            case '^': values.push(std::pow(left, right)); break;
        }
    }
    return values.pop();
}
