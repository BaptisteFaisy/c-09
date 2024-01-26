/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:26:41 by bfaisy            #+#    #+#             */
/*   Updated: 2024/01/23 18:18:04 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <array>

float utils(std::string ligne);
float chartofloat(std::string str);
int find(std::string str);


#include "BitcoinExchange.hpp"
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
			{ // maybe patch pour les mois ect si jamais j'ai le temps bisextille
				if ((std::stoi(ligne.substr(0, 4)) > 2024 || std::stoi(ligne.substr(0, 4)) < 2009) || (std::stoi(ligne.substr(5, 2)) > 12 || std::stoi(ligne.substr(5, 2)) < 0)
					|| (std::stoi(ligne.substr(8,2)) > 31 || std::stoi(ligne.substr(8,2)) < 0) || ligne[11] != '|')
				{
					std::cout << "Error : input not valid\n";
					return (1);
				}
			}
			catch (const std::invalid_argument& e) {
            	std::cerr << "Error: Invalid date" << std::endl;
            	continue ;
        	} catch (const std::out_of_range& e) {
            	std::cerr << "Error: Out of range : " << e.what() << std::endl;
            	continue;}
			if (utils(ligne) == -1)
				continue ;
		}
		else if (ligne == "date | value")
			i++;
		find(ligne);
	}
}

float utils(std::string ligne)
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
		if (std::stof(nbr) < 0 || std::stof(nbr) > 1000)
		{
			std::cout << "Error : number\n";
			return (-1);
		}

	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: Invalid number" << e.what() << std::endl;
		return (-1);
	} catch (const std::out_of_range& e) {
		std::cerr << "Error: Out of range"<< std::endl;
		return (-1);}
	return (std::stof(nbr));
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
		if (ligne == "date,exchange_rate" || (std::stoi(ligne.substr(0, 4)) > 2024 || std::stoi(ligne.substr(0, 4)) < 2009) || (std::stoi(ligne.substr(5, 2)) > 12 || std::stoi(ligne.substr(5, 2)) < 0)
					|| (std::stoi(ligne.substr(8,2)) > 31 || std::stoi(ligne.substr(8,2)) < 0))
			continue ;
		else if (str.substr(0,4) < ligne.substr(0,4))
		{
			std::cout << str.substr(0,10) << "=>" << utils(str) << '=' << utils(str) * chartofloat(ligneavant) << std::endl;
			return (0) ;
		}
		if (str.substr(0,4) == ligne.substr(0,4))
		{
			if (str.substr(5,2) < ligne.substr(5,2))
			{
				std::cout << str.substr(0,10) << "=>" << utils(str) << '=' << utils(str) * chartofloat(ligneavant) << std::endl;
				return (0) ;
			}
			if (str.substr(5,2) == ligne.substr(5,2))
			{
				if (str.substr(8,2) < ligne.substr(8,2))
				{
					std::cout << str.substr(0,10) << "=>" << utils(str) << '=' << utils(str) * chartofloat(ligneavant) << std::endl;
					return (0) ;
				}
				if (str.substr(8,10) == ligne.substr(8,2))
				{
					std::cout << str.substr(0,10) << "=>" << utils(str) << '=' << utils(str) * chartofloat(ligne) <<std::endl;
					return (0) ;
				}
			}
		ligneavant = ligne;
		}
	}
	return (0);
}

float chartofloat(std::string str)
{
	int j = 11;
	std::array<float, 2> array = {0,0};
	int cond = 0;
	bool cond2 = false;
	int i = 1;
	// std::cout << str[j];
	while (str[j])
	{
		if (std::isdigit(str[j]) && cond2 == false)
		{
			array[0] *= 10;
			array[0] += (str[j] -'0');
			cond = 1;
			j++;
		}
		else if (std::isdigit(str[j]) && cond2 == true)
		{
			array[1] += (str[j] - '0') * (std::pow(0.1, i));
			cond2 = true;
			i++;
			j++;
		}
		else if (str[j] == '.')
		{
			j++;
			cond2 = true;
		}
		else
		{
			if (cond == 1)
			{
				if (cond2 == true)
					array[0] += array[1];
			return (array[0]);}
			else
				return (-1);
		}
	}
	if (cond2 == true)
		array[0] += array[1];
	// std::cout << "a" << nbr<< "a";
	return (array[0]);
}