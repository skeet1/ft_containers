/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:12:10 by mkarim            #+#    #+#             */
/*   Updated: 2022/12/16 17:45:42 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vector.hpp"

using namespace ft;

int main()
{
    // ft::vector<int> f;
    // ft::vector<char> vf(60);
    // ft::vector<double> vd(600);

    // std::cout << vi.size() << std::endl;
    // std::cout << vf.size() << std::endl;
    // std::cout << vd.size() << std::endl;

    // vi.push_back(3);
    // vi.push_back(5);
    // vi.push_back(7);
    // vi.push_back(1);
    // vi.push_back(4);
    // vi.push_back(3);
    // vi.push_back(3);
    // vi.push_back(3);
    // vi.push_back(3);
    // vi.push_back(3);

    // std::cout << vi.size() << std::endl;
    // std::cout << vi.capacity() << std::endl;
    // vi.resize(7);
    // vi.print();
    // f.push_back(3);
	// f.push_back(5);
	// f.push_back(134);
	// f.push_back(34);
	// f.push_back(11);
	// f.push_back(34);

	// std::cout << f.size() << std::endl;
	// std::cout << f.capacity() << std::endl;
	// f.print();
    
    // f.pop_back();
    // f.pop_back();
    // f.pop_back();
    // f.pop_back();
    // f.pop_back();
    // f.pop_back();
    // f.pop_back();
    
	// std::cout << f.size() << std::endl;
	// std::cout << f.capacity() << std::endl;
	// f.print();

    ft::vector<int> v;

	// size_t c = v.capacity();
	// for (int i = 1; i < 50; i++)
	// {
	// 	v.push_back(i);
	// 	if (c != v.capacity())
	// 	{
	// 		c = v.capacity();
	// 		std::cout << "capacity changed : " << c << "\n";
	// 	}
	// }
	// v.reserve(100);
	// c = v.capacity();
	// std::cout << "now capacity is : " << c << "\n";
	// for (int i = 1; i <= 500; i++)
	// {
	// 	v.push_back(i);
	// 	if (c != v.capacity())
	// 	{
	// 		c = v.capacity();
	// 		std::cout << "capacity changed : " << c << "\n";
	// 	}
	// }

	v.push_back(3);
	v.push_back(7);

	ft::vector<int>::iterator it;
	ft::vector<int>::iterator end;

	// it = v.begin();
	// end = v.end();
	// v.insert(end, 1222);
	// it = v.begin();
	// end = v.end();
	// v.insert(it + 3, -765);
	std::cout << "size : " << v.size() << " _capacity is : " << v.capacity() << std::endl;
	it = v.begin();
	end = v.end();
	v.insert(it, 7, 100);
	// while (it != v.end())
	// {
	// 	std::cout << *it << std::endl;
	// 	it++;
	// }
	v.print();
	std::cout << "size : " << v.size() << " _capacity is : " << v.capacity() << std::endl;
    return 0;
}
