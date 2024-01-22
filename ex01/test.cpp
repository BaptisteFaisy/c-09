#include <iostream>
#include <stack>
#include <sstream>

int evaluateRPN(const std::string& expression) {
    std::stack<int> operandStack;

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
            // Si le token est un nombre, le convertir en entier et empiler
            operandStack.push(std::stoi(token));
        } else {
            // Si le token est un opérateur, dépiler deux opérandes, effectuer l'opération et empiler le résultat
            int operand2 = operandStack.top();
            operandStack.pop();

            int operand1 = operandStack.top();
            operandStack.pop();

            if (token == "+") {
                operandStack.push(operand1 + operand2);
            } else if (token == "-") {
                operandStack.push(operand1 - operand2);
            } else if (token == "*") {
                operandStack.push(operand1 * operand2);
            } else if (token == "/") {
                operandStack.push(operand1 / operand2);
            } else {
                std::cerr << "Opérateur non reconnu : " << token << std::endl;
                return 0;  // Opérateur non pris en charge
            }
        }
    }

    // Le résultat final est au sommet de la pile
    return operandStack.top();
}

int main() {
    std::string rpnExpression = "  1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 / ";
    int result = evaluateRPN(rpnExpression);

    std::cout << "Résultat de l'expression RPN : " << result << std::endl;

    return 0;
}