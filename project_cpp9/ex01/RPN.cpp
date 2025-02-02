#include "RPN.hpp"
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& other) : operands(other.operands) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        operands = other.operands;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::performOperation(int a, int b, const std::string& op) const {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) throw std::runtime_error("Error: Division by zero");
        return a / b;
    }
    throw std::runtime_error("Error: Unknown operator");
}

int RPN::calculate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isOperator(token)) {
            if (operands.size() < 2) {
                throw std::runtime_error("Error: Insufficient operands");
            }
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            operands.push(performOperation(a, b, token));
        } else {
            char* end;
            int num = std::strtol(token.c_str(), &end, 10);
            if (*end != '\0' || num < 0 || num > 9) {
                throw std::runtime_error("Error: Invalid token: " );
            }
            operands.push(num);
        }
    }

    if (operands.size() != 1) {
        throw std::runtime_error("Error: Invalid expression");
    }

    return operands.top();
}