/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:26:41 by bfaisy            #+#    #+#             */
/*   Updated: 2024/01/16 03:40:35 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// 2001-42-42

#include <fstream>
#include <string>
#include <cstdlib>
int utils(std::string ligne);
float chartofloat(std::string str);

#include "BitcoinExchange.hpp"
// to do je n'ai pas check le fichier data.csv en terme d'input
int main(int ac, char **av)
{
	std::string ligne;
	int i = 0;
	if (ac != 2){std::cout << "Error : no valid arguments\n";
		return (1);}
	std::ifstream fichier(av[1]);
	if (!fichier.is_open())
		return (std::cout << "Error : open failed\n", 1);
	while (std::getline(fichier, ligne))
	{
		if (i != 0)
		{
			try
			{ // maybe patch pour les mois ect si jamais j'ai le temps
				if ((std::stoi(ligne.substr(0, 4)) > 2024 || std::stoi(ligne.substr(0, 4)) < 2009) || (std::stoi(ligne.substr(5, 7)) > 12 || std::stoi(ligne.substr(5, 7)) < 0)
					|| (std::stoi(ligne.substr(8,10)) > 31 || std::stoi(ligne.substr(8,10)) < 0) || ligne[11] != '|')
				{
					std::cout << "Error : input not valid\n";
					return (1);
				}
			}
			catch (const std::invalid_argument& e) {
            	std::cerr << "Error: Invalid date" << e.what() << std::endl;
            	return 1;
        	} catch (const std::out_of_range& e) {
            	std::cerr << "Error: Out of range : " << e.what() << std::endl;
            	return 1;}
			if (utils(ligne) == -1)
				return (1);
		}
		else if (ligne == "date | value")
			i++;
		find(ligne)
	}
}

int utils(std::string ligne)
{
	int j = 13;
	std::string nbr;
	while (ligne[j] != '\0')
	{
		nbr += ligne[j];
		j++;
	}
	try
	{
		if (std::stoi(nbr) < 0 || std::stoi(nbr) > 1000)
		{
			std::cout << "Error : number\n";
			return (-1);
		}float chartofloat(std::string str)

	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: Invalid number" << e.what() << std::endl;
		return (-1);
	} catch (const std::out_of_range& e) {
		std::cerr << "Error: Out of range"<< std::endl;
		return (-1);}
	return (std::stoi(nbr));
}

int find(std::string str)
{
	std::ifstream fichier("data.csv");
	std::string ligne;
	std::string ligneavant;
	if (!fichier.is_open())
		return (std::cout << "Error : open failed\n", -1);
	while (std::getline(fichier, ligne))
	{
		if ((std::stoi(ligne.substr(0, 4)) > 2024 || std::stoi(ligne.substr(0, 4)) < 2009) || (std::stoi(ligne.substr(5, 7)) > 12 || std::stoi(ligne.substr(5, 7)) < 0)
					|| (std::stoi(ligne.substr(8,10)) > 31 || std::stoi(ligne.substr(8,10)) < 0))
		{
			if (str.substr(0,4) < ligne.substr(0,4))
			{
				std::cout << ligneavant.substr(0,10) << "=>" << utils(str) << '=' << utils(str) * chartofloat(ligneavant) << std::endl;
			}
			if (str.substr(0,4) == ligne.substr(0,4))
			{
				if (str.substr(5,7) < ligne.substr(5,7))
					std::cout << ligneavant.substr(0,10) << "=>" << utils(str) << '=' << utils(str) * chartofloat(ligneavant) << std::endl;
				if (str.substr(5,7) == ligne.substr(5,7))
				{
					if (str.substr(5,7) < ligne.substr(5,7))
				}
			}
			ligneavant = ligne;
		}
	}
}

float chartofloat(std::string str)
{
	int j = 10;
	float nbr = 0;
	int cond = 0;
	while (str[j])
	{
		if (std::isdigit(str[j]))
		{
			nbr += str[j];
			cond = 1;
			j++;
		}
		else if (str[j] == '.')
			j++;
		else
		{
			if (cond == 1)
				return (nbr);
			else
				return (-1);
		}
	}
}