/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:12:10 by mkarim            #+#    #+#             */
/*   Updated: 2022/12/21 17:07:42 by mkarim           ###   ########.fr       */
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

    // ft::vector<int> v;

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

    // v.push_back(5);
    // v.push_back(15);
    // v.push_back(25);
    // v.push_back(35);
    // v.push_back(45);
	// std::cout << sizeof(v) << std::endl;
	// v.print();
	// v.print_info();
	// ft::vector<int>::iterator it;
	// ft::vector<int>::iterator end;

	// it = v.begin();
	// end = v.end();
	// v.insert(end, 1222);
	// it = v.begin();
	// end = v.end();
	// v.insert(it + 3, -765);
	// std::cout << "size : " << v.size() << " _capacity is : " << v.capacity() << std::endl;
	// it = v.begin();
	// end = v.end();
	// v.insert(it, 7, 100);
	// while (it != v.end())
	// {
	// 	std::cout << *it << std::endl;
	// 	it++;
	// }
	// int arr[3] = {101, 102, 103};
	
	// arr.push_back(101);
	// arr.push_back(102);
	// arr.push_back(103);

	// v.insert(v.begin() + 2, arr, arr+3);
	// v.print();
	// std::cout << "size : " << v.size() << " _capacity is : " << v.capacity() << std::endl;

	// v.erase(v.begin() + 2);
	// v.erase(v.begin() + 2);
	// ft::vector<int>::iterator it = v.begin();
	// while (it != v.end())
	// {
	// 	std::cout << *it << " ";
	// 	it++;
	// }
	// std::cout << std::endl;
	// v.erase(v.begin() + 2);

	ft::vector<int> v;

	v.push_back(1);
	v.push_back(11);
	v.push_back(1111);
	v.push_back(111);

	ft::vector<int> vv(v);
	vv.insert(vv.begin() + 2, 4);
	vv.print();
	ft::vector<int>::iterator it;
	it = vv.begin() + 3;
	std::cout << *it << std::endl;

	
    return 0;
}
