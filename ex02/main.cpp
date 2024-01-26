/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:16:57 by bfaisy            #+#    #+#             */
/*   Updated: 2024/01/26 16:44:53 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <chrono>
#include <list>


static bool estUneChaineDeChiffres(const std::string& chaine);
static void container2(int ac, char **av);
static bool estUneChaineDeChiffres2(int ac ,char **av);


int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "no argument\n";
		return (1);
	}
	int i = 1;
	int j = 0;
	int ij = 0;
	int nbr = 0;
	bool cond = false;
	if (estUneChaineDeChiffres2(ac,av) == false)
		return (1);
	std::cout << "Before : ";
	while (i != ac)
	{
			std::cout << av[i] << ' ';
			i++;
	}
	std::cout << std::endl;
	i = 1;
	auto start_time = std::chrono::high_resolution_clock::now();
	if (estUneChaineDeChiffres(av[1]))
	{
		std::vector<std::vector<int>> vector(ac - 1, std::vector<int>(2, 0));
		while (j != ((ac - 1)  / 2))
		{
			vector[j][0] = std::stoi(av[i]);
			i++;
			vector[j][1] = std::stoi(av[i]);
			i++;
			j++;
		}
		j = 0;
		i = 0;
		std::vector<int> listfinal;
		std::vector<int>::iterator it = listfinal.begin();
		while (i != ((ac - 1)  / 2))
		{
			cond = false;
			it = listfinal.begin();
			ij = 0;
			if (vector[j][1] < vector[j][0])
			{
				if (listfinal.empty())
					listfinal.insert(it, vector[j][0]);
				else
				{
					while (listfinal[ij])
					{
						if (listfinal[ij] >= vector[j][0])
						{
							listfinal.insert(it, vector[j][0]);
							cond = true;
							break ;
						}
						ij++;
						it++;
					}
					if (cond == false)
						listfinal.insert(listfinal.end(), vector[j][0]);
				}
			}
			else
			{
				if (listfinal.empty())
						listfinal.insert(it, vector[j][1]);
				else
				{
					while (listfinal[ij])
					{
						if (listfinal[ij] >= vector[j][1]) 
						{
							listfinal.insert(it, vector[j][1]);
							cond = true ;
							break ;
						}
						ij++;
						it++;
					}
					if (cond  == false)
						listfinal.insert(listfinal.end(), vector[j][1]);
				}
			}
			i++;
			j++;
		}
		j = 0;
		i = 0;
		while (i != ((ac - 1)  / 2))
		{
			it = listfinal.begin();
			ij = 0;
			if (vector[j][1] < vector[j][0])
			{
				while (listfinal[ij])
				{
					if (listfinal[ij] >= vector[j][1])
					{
						listfinal.insert(it, vector[j][1]);
						break ;
					}
					ij++;
					it++;
				}
			}
			else
			{
				while (listfinal[ij])
				{
					if (listfinal[ij] >= vector[j][0])
					{
						listfinal.insert(it, vector[j][0]);
						break ;
					}
					ij++;
					it++;
				}
			}
			i++;
			j++;
		}
		if ((ac  - 1 ) % 2 == 1)
		{
			i = 0;
			if (estUneChaineDeChiffres(av[ac -1]))
			{
				it = listfinal.begin();
				nbr = std::stoi(av[ac - 1]);
				while (listfinal[i])
				{
					if (listfinal[i] >= nbr)
					{
							listfinal.insert(it, nbr);
							break ;
					}
					i++;
					it++;
				}
			}
		}
		auto end_time = std::chrono::high_resolution_clock::now();
		i = 0;
		std::cout << "After : ";
		while (i != ac - 1)
		{
			std::cout << listfinal[i] << ' ';
			i++;
		}
		std::cout << std::endl;
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector :" << duration.count() << " us " << std::endl;
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// list
		container2(ac, av);
	}
}

static bool estUneChaineDeChiffres(const std::string& chaine) {
    for (char caractere : chaine) {
        if (!std::isdigit(caractere)) {
            return false;
        }
    }
    return true;
}

static bool estUneChaineDeChiffres2(int ac ,char **av)
{
	int i = 1;
	while (i != ac)
	{
		if (estUneChaineDeChiffres(av[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

static void container2(int ac, char **av)
{
	int i = 1;
	int j = 1;
	bool cond = false;
	std::cout << "Before : ";
	while (i != ac)
	{
			std::cout << av[i] << ' ';
			i++;
	}
	i = 0;
	std::cout << std::endl;
	std::list<int> list;
	while ( i != ac -1)
	{
		list.push_back(std::stoi(av[j]));
		j++;
		i++;
	}
	std::list<int> finallist;
	std::list<int>::iterator in = finallist.begin();
	std::list<int>::iterator ip = finallist.begin();
	i = 0;
	j = 1;
	while (i != (ac -1) / 2)
	{
		cond = false;
		if (j + 1 <= list.size())
		{
			std::advance(in, j);
			std::advance(ip, j - 1);
			if (*in >= *ip)
			{
				if (list.empty())
					finallist.push_back(*in);
				else
				{
					ip = list.begin();
					while (*ip != list.back())
					{
						cond = true;
						if (*in <= *ip)
							finallist.insert(ip, *in);
						ip++;
						ip++;
					}
					if (cond == false)
						finallist.push_back(*in);
				}
			}
			else
			{
				if (list.empty())
					finallist.push_back(*ip);
				else
				{
					in = list.begin();
					while (*in != list.back())
					{
						cond = true;
						if (*ip <= *in)
							finallist.insert(in, *ip);
						in++;
						in++;
					}
					if (cond == false)
						finallist.push_back(*ip);
				}
			}
		}
		i++;
		j+= 2;
	}
    std::cout << finallist.size() << std::endl;
}