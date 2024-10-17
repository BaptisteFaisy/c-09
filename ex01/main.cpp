/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:01:49 by bfaisy            #+#    #+#             */
/*   Updated: 2024/10/17 11:33:32 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <stack>
#include <sstream>
void evaluateRPN(std::string expression);


int main(int ac, char **av)
{
	if (ac > 2)
	{
		std::cout << "Error : too many argument\n";
		return (1);
	}
	evaluateRPN(av[1]);
}
void evaluateRPN(std::string str) {
    std::stack<int> operandStack;
    int ig = 0;

    while (str[ig] != '\0') {
        if (str[ig] == ' ') {
            ig++;
            continue;
        }

        if (isdigit(str[ig])) {
            operandStack.push(str[ig] - '0');
        }
        else if (str[ig] == '+' || str[ig] == '-' || str[ig] == '*' || str[ig] == '/') {
            if (operandStack.size() < 2) {
                std::cout << "Erreur : expression mal formée, pas assez d'opérandes\n";
                return;
            }

            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            if (str[ig] == '+') {
                operandStack.push(operand1 + operand2);
            } else if (str[ig] == '-') {
                operandStack.push(operand1 - operand2);
            } else if (str[ig] == '*') {
                operandStack.push(operand1 * operand2);
            } else if (str[ig] == '/') {
                if (operand2 == 0) {
                    std::cout << "Erreur : division par zéro\n";
                    return;
                }
                operandStack.push(operand1 / operand2);
            }
        } else {
            std::cout << "Erreur : caractère non valide dans l'expression\n";
            return;
        }

        ig++;
    }

    if (operandStack.size() == 1) {
        std::cout << "Résultat : " << operandStack.top() << std::endl;
    } else {
        std::cout << "Erreur : expression mal formée, trop d'opérandes\n";
    }
}

