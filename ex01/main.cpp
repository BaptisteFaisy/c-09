/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:01:49 by bfaisy            #+#    #+#             */
/*   Updated: 2024/01/22 17:16:05 by bfaisy           ###   ########.fr       */
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
	int j = 0;

    while (str[ig] && j < 10) {
        if (isdigit(str[ig]) ) {
            operandStack.push((str[ig] - '0'));
        } 
		else if (str[ig] == ' ')
		{
			ig++;
			continue;
		}
		else if (str[ig] == '+' || str[ig] == '-' || str[ig] == '*' || str[ig] == '/')
		{
			if (operandStack.size() % 2 == 1 && j == 1){
				std::cout << "Trop d'operateur\n";
				return ;}
			else
			{
				if (operandStack.empty()){
					std::cout << "Bad input\n";
					return ;}
				else
				{
					int operand2 = operandStack.top();
					operandStack.pop();

					int operand1 = operandStack.top();
					operandStack.pop();

					if (str[ig] == '+') {
						operandStack.push(operand1 + operand2);
						j++;
					} else if (str[ig] == '-') {
						operandStack.push(operand1 - operand2);
						j++;
					} else if (str[ig] == '*') {
						operandStack.push(operand1 * operand2);
						j++;
					} else if (str[ig] == '/') {
						operandStack.push(operand1 / operand2);
						j++;
					}
				}
			}
        }
		else 
		{
			std::cout << "Bad input\n";
			return ;
		}
		ig++;
    }
    std::cout << operandStack.top() << std::endl;
}