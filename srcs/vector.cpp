/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:12:10 by mkarim            #+#    #+#             */
/*   Updated: 2022/12/06 10:34:16 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.hpp"
#include <vector>

size_t getCapacity(size_t _size)
{
	size_t findCapacity = 1;

	while (findCapacity < _size)
	{
		findCapacity = findCapacity << 1;
	}
	return findCapacity;
}

template <typename T>
void	setZeros(T& arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}

using namespace ft;

int main()
{
    ft::vector<int> vi;
    // ft::vector<char> vf(60);
    // ft::vector<double> vd(600);

    // std::cout << vi.size() << std::endl;
    // std::cout << vf.size() << std::endl;
    // std::cout << vd.size() << std::endl;

    vi.push_back(3);
    vi.push_back(5);
    vi.push_back(7);
    vi.push_back(1);
    vi.push_back(4);
    // vi.push_back(3);
    // vi.push_back(3);
    // vi.push_back(3);
    // vi.push_back(3);
    // vi.push_back(3);

    // std::cout << vi.size() << std::endl;
    // std::cout << vi.capacity() << std::endl;
    vi.resize(7);
    vi.print();
    
    return 0;
}