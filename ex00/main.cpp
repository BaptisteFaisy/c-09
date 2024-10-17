/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:26:41 by bfaisy            #+#    #+#             */
/*   Updated: 2024/10/17 11:21:36 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

float utils(std::string ligne);
float chartofloat(std::string str);
int find(std::string str);


bool estBisextile(int annee) {
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}
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
		if (ligne.empty() || ligne == "date | value"){
			i++;
			continue;
		}
		else if (i != 0)
		{
			if (utils(ligne) == -1)
				continue ;
		}

		find(ligne);
	}
}

float utils(std::string ligne) {
    int j = 13;
    std::string nbr;
    BitcoinExchange bit;
    char* end;
    errno = 0;

    while (ligne[j] != '\0') {
        nbr += ligne[j];
        j++;
    }

    double nbrd = std::strtod(nbr.c_str(), &end);

    if (nbrd < 0 || nbrd > 1000 || *end != '\0' || errno == ERANGE) {
        std::cout << "Error: invalid number\n";
        return -1.0f;
    }

    if (bit.check(ligne)) {
        std::cout << "Error: input not valid\n";
        return -1.0f;
    }

    return static_cast<float>(nbrd);
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
		if (ligne == "date,exchange_rate" || (std::atoi(ligne.substr(0, 4).c_str()) > 2024 || std::atoi(ligne.substr(0, 4).c_str()) < 2009) || (std::atoi(ligne.substr(5, 2).c_str()) > 12 || std::atoi(ligne.substr(5, 2).c_str()) < 0)
					|| (std::atoi(ligne.substr(8,2).c_str()) > 31 || std::atoi(ligne.substr(8,2).c_str()) < 0))
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
	float array[2] = {0,0};
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