/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:49:35 by aben-nei          #+#    #+#             */
/*   Updated: 2024/03/18 23:19:07 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream> // for istringstream
#include <string>
#include <vector>
#include <deque>
#include <utility> // for pair
#include <ctime>
#include <cmath>


typedef std::vector<std::pair<int, int> >	t_pair;
typedef std::vector<int>	t_vector;
typedef std::deque<int>	t_deque;
typedef std::deque<std::pair<int, int> >	t_dequePair;

class PmergeMe
{
	private:
		// Vector
		t_vector	_pend;
		t_pair		_numbers;
		int			_struggler;
		bool		_foundStruggler;
		t_vector	_mainChain;
		// Deque
		t_deque		_pendDeq;
		int			_strugglerDeq;
		bool		_foundStrugglerDeq;
		t_deque		_mainChainDeq;
		t_dequePair	_numbersDeque;
	public:
	/****************** constructor ********************/
		PmergeMe();
		~PmergeMe();
	/****************** methods ***********************/
		void		checkSign(char *av);
		size_t		jacobsthal();
		std::string	takingNumbers(char **av);
		t_vector	getMainChain() const;
		t_deque		getMainChainDeq() const;
		void		printNumberVec();
		void		printNumberDeq();
		/************** Vec *****************/
		void		detecteLarge();
		void		prepareSortPair();
		void		createMainChainAndPend();
		void		mergeNumbers(size_t jac);
		void		mergeStruggler();
		void		sortNumbersVec(const std::string &str);
		/************** Deq *****************/
		void		detecteLargeDeq();
		void		prepareSortPairDeq();
		void		createMainChainAndPendDeq();
		void		mergeNumbersDeq(size_t jac);
		void		sortNumbersDeq(const std::string &str);
		void		mergeStrugglerDeq();
};