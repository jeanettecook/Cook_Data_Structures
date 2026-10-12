#include "Calculator.hpp"
#include <string>
#include <cctype>
#include <cmath>
#include <stdexcept>



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
    if(op == '+' || op == '-'|| op == '*'|| op == '/' || op == '%' || op == '^'){
        return true;
    }
    else{
        return false;
    }
}

bool Calculator::isOpenBracket(char c){
    return c == '(' || c == '[' || c == '{';
}

bool Calculator::isCloseBracket(char c){
    return c == ')' || c == ']' || c == '}';
}

// true if the open and close bracket are the same kind
bool Calculator::bracketsMatch(char open, char close){
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// every close bracket must match the most recent unmatched open bracket,
// and no open brackets can be left over at the end
bool Calculator::bracketsBalanced(){
    Stack<char> brackets;
    for (int i = 0; i < infix.size(); i++){
        char current_char = infix[i];
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

int Calculator::precedence(char op){
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

    
std::string Calculator::toPostfix() {
    // check for bad characters first
    for (int i = 0; i < infix.size(); i++){
        char current_char = infix[i];
        if (!(current_char == ' ' || isOperand(current_char) || isOperator(current_char)
              || isOpenBracket(current_char) || isCloseBracket(current_char))){
            throw std::logic_error("Error: invalid character in the expression");
        }
    }

    if (!bracketsBalanced()){
        throw std::logic_error("Error: invalid parentheses");
    }

    Stack<char> stack_char; 
    std::string postfix;
    postfix_tokens.clear();
    int operand_count = 0; // how many values would be on the stack when evaluating

    for (int i = 0; i < infix.size(); i++){
        char current_char = infix[i];
        if (current_char == ' '){
            continue;
        }
        if (isOperand(current_char)){
            // read the whole number, not just one digit
            std::string number;
            while (i < infix.size() && isOperand(infix[i])){
                number.push_back(infix[i]);
                i++;
            }
            i--; // the for loop will move past the last digit
            postfix += number;
            postfix_tokens.push_back(number);
            operand_count++;
        }
        else if (isOpenBracket(current_char)){
            stack_char.push(current_char);
        }
        else if (isCloseBracket(current_char)){
            // pop until we reach the matching open bracket
            while (!isOpenBracket(stack_char.top())){
                char op = stack_char.pop();
                postfix.push_back(op);
                postfix_tokens.push_back(std::string(1, op));
                operand_count--;
            }
            stack_char.pop(); // throw away the open bracket
        }
        else if (isOperator(current_char)){
            // ^ is right associative, the rest are left associative
            while (!stack_char.empty() && !isOpenBracket(stack_char.top()) &&
                   (precedence(stack_char.top()) > precedence(current_char) ||
                    (precedence(stack_char.top()) == precedence(current_char) && current_char != '^'))){
                char op = stack_char.pop();
                postfix.push_back(op);
                postfix_tokens.push_back(std::string(1, op));
                operand_count--;
            }
            stack_char.push(current_char);
        }
        // each operator needs two operands to use
        if (operand_count < 1 && isOperator(current_char)){
            throw std::logic_error("Error: invalid number of operands");
        }
    }
    while (!stack_char.empty()){
       char current_char = stack_char.pop();
       postfix.push_back(current_char);
       postfix_tokens.push_back(std::string(1, current_char));
       operand_count--;
    }

    // a valid expression leaves exactly one value
    if (operand_count != 1){
        throw std::logic_error("Error: invalid number of operands");
    }

    return postfix;

}



double        Calculator::calculate() const {
    Stack<double> values;
    for (int i = 0; i < postfix_tokens.size(); i++){
        const std::string& token = postfix_tokens[i];
        if (isdigit(token[0])){
            values.push(std::stod(token));
            continue;
        }
        if (values.empty()){
            throw std::logic_error("Error: invalid number of operands");
        }
        double right = values.pop();
        if (values.empty()){
            throw std::logic_error("Error: invalid number of operands");
        }
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
    if (values.empty()){
        throw std::logic_error("Error: invalid number of operands");
    }
    return values.pop();
}
