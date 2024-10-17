/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:25:29 by bfaisy            #+#    #+#             */
/*   Updated: 2024/10/17 11:06:31 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){(void)other;}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){(void)other; return *this;}

int BitcoinExchange::check(std::string ligne) {
    int year = std::atoi(ligne.substr(0, 4).c_str());
    int month = std::atoi(ligne.substr(5, 2).c_str());
    int day = std::atoi(ligne.substr(8, 2).c_str());

    // Vérification de l'année
    if (year > 2024 || year < 2009) {
        return 1;
    }

    // Vérification du mois
    if (month > 12 || month < 1) {
        return 1;
    }

    // Vérification des jours par mois
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day > 31 || day < 1) {
            return 1;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30 || day < 1) {
            return 1;
        }
    } else if (month == 2) {
        // Vérification pour février (année bissextile)
        bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (leapYear) {
            if (day > 29 || day < 1) {
                return 1;
            }
        } else {
            if (day > 28 || day < 1) {
                return 1;
            }
        }
    }

    // Si toutes les vérifications passent, renvoyer 0
    return 0;
}