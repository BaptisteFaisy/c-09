/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:16:57 by bfaisy            #+#    #+#             */
/*   Updated: 2024/10/17 11:52:26 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <list>
#include <cstdlib>


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
		return (std::cout << "Error\n", 1);
	std::cout << "Before : ";
	while (i != ac)
	{
			std::cout << av[i] << ' ';
			i++;
	}
	std::cout << std::endl;
	i = 1;
	clock_t start_time = clock();
	if (estUneChaineDeChiffres(av[1]))
	{
		std::vector<std::vector<int> > vector(ac - 1, std::vector<int>(2, 0));
		while (j != ((ac - 1)  / 2))
		{
			vector[j][0] = std::atoi(av[i]);
			i++;
			vector[j][1] = std::atoi(av[i]);

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
				nbr = std::atoi(av[ac - 1]);
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
    	clock_t end_time = clock();
		i = 0;
		std::cout << "After : ";
		while (i != ac - 1)
		{
			std::cout << listfinal[i] << ' ';
			i++;
		}
		std::cout << std::endl;
    	double duration = static_cast<double>(end_time - start_time) * 1000 / CLOCKS_PER_SEC;
		std::cout << "Time to process a range of " << (ac - 1) << " elements with std::vector: " 
              << duration << " us " << std::endl;
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// list
		container2(ac, av);
	}
}

static bool estUneChaineDeChiffres(const std::string& chaine) {
     for (std::string::size_type i = 0; i < chaine.size(); ++i) {
        if (!std::isdigit(chaine[i])) {
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
	int ij = 0;
	bool cond2 =false;
	bool cond = false;
	int nbr = 0;
	std::cout << "Before : ";
	while (i != ac)
	{
			std::cout << av[i] << ' ';
			i++;
	}
	i = 0;
	std::cout << std::endl;
	clock_t start_time2 = clock();
	std::list<int> list;
	while ( i != ac -1)
	{
		list.push_back(std::atoi(av[j]));
		j++;
		i++;
	}
	std::list<int> finallist;
	std::list<int>::iterator in = list.begin();
	std::list<int>::iterator ip = list.begin();
	std::list<int>::iterator it = finallist.begin();
	i = 0;
	j = 0;
	while (i != (ac -1) / 2)
	{
		cond = false;
		ij = 0;
		if (static_cast<unsigned long>(j + 1) <= list.size())
		{
			if (cond2 == false)
			{
				in++;
				cond2 = true;
			}
			else
			{
				in++;
				in++;
			}
			ip = in;
			ip--;
			if (*in >= *ip)
			{
				if (finallist.empty())
					finallist.push_back(*in);
				else
				{
					it = finallist.begin();
					while (static_cast<unsigned long>(ij) < finallist.size())
					{
						if (*in <= *it)
						{
							finallist.insert(it, *in);
							cond = true;
							break ;
						}
						it++;
						ij++;
					}
					if (cond == false)
						finallist.push_back(*in);
				}
			}
			else
			{
				if (finallist.empty())
					finallist.push_back(*ip);
				else
				{
					it = finallist.begin();
					while (static_cast<unsigned long>(ij) < finallist.size())
					{
						if (*ip <= *it)
						{
							finallist.insert(it, *ip);
							cond = true;
							break ;
						}
						ij++;
						++it;
					}
					if (cond == false)
						finallist.push_back(*ip);
				}
			}
		}
		i++;
		j+= 2;
	}
	i = 0;
	j = 0;
	in = list.begin();
	ip = list.begin();
	cond2 = false;
	// for (std::list<int>::iterator it = finallist.begin(); it != finallist.end(); it++) {
    //     std::cout << *it << " ";
    // }
	while (i != (ac -1) / 2)
	{
		cond = false;
		ij = 0;
		if (static_cast<unsigned long>(j + 1) <= list.size())
		{
			if (cond2 == false)
			{
				std::advance(in, 1);
				cond2 = true;
			}
			else
				std::advance(in, 2);
			ip = in;
			ip--;
			// std::cout << *in << std::endl;
			if (*in <= *ip)
			{
				it = finallist.begin();
				while (static_cast<unsigned long>(ij) < finallist.size())
				{
					if (*in <= *it)
					{
						finallist.insert(it, *in);
						cond = true;
						// std::cout << *in;
						break ;
					}
					ij++;
					it++;
				}
				if (cond == false)
					finallist.push_back(*in);
			}
			else
			{
				it = finallist.begin();
				while (static_cast<unsigned long>(ij) < finallist.size())
				{
					if (*ip <= *it)
					{
						finallist.insert(it, *ip);
						cond = true;
						// std::cout << *ip;
						break ;
					}
					ij++;
					++it;
				}
				if (cond == false)
					finallist.push_back(*ip);
			}
		}
		j+=2;
		i++;
	}
	cond = false;
	nbr = list.back();
	if ((ac  - 1 ) % 2 == 1)
	{
		it = finallist.begin();
		while (static_cast<unsigned long>(ij) < finallist.size())
		{
			if (nbr <= *it)
			{
				finallist.insert(it, nbr);
				cond = true;
				// std::cout << *ip;
				break ;
			}
			ij++;
			++it;
		}
		if (cond == false)
			finallist.push_back(nbr);
	}
	clock_t end_time2 = clock();	std::cout << "After : ";
	for (std::list<int>::iterator it = finallist.begin(); it != finallist.end(); it++) {
        std::cout << *it << " ";
    }
	std::cout << std::endl;
	double duration2 = static_cast<double>(end_time2 - start_time2) * 1000 / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << (ac - 1) << " elements with std::list: " 
              << duration2  << " us " << std::endl;}

