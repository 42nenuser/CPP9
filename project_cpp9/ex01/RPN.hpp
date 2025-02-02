#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>

class RPN {
private:
    std::stack<int> operands;

    bool isOperator(const std::string& token) const;
    int performOperation(int a, int b, const std::string& op) const;

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int calculate(const std::string& expression);
};

#endif // RPN_HPP