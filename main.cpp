/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:12:10 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/09 14:55:27 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vector.hpp"
#include "./includes/map.hpp"
#include <vector>
#include <map>
#include <type_traits>

void print(std::vector<int> &v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i < v.size() - 1) std::cout << " ";
	}
	std::cout << std::endl;
}

void print_infos(std::vector<int> &v)
{
	std::cout << "size is : " << v.size() << " , and capacity is : " << v.capacity() << std::endl;
}

void print(ft::vector<int> &v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i < v.size() - 1) std::cout << " ";
	}
	std::cout << std::endl;
}

void print_infos(ft::vector<int> &v)
{
	std::cout << "size is : " << v.size() << " , and capacity is : " << v.capacity() << std::endl;
}

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

	// std::vector<int> v;
	// std::vector<int> t1, t2;
	// ft::vector<int> to_insert;

	// to_insert.push_back(99);
	// to_insert.push_back(999);
	// to_insert.push_back(9999);

	// for (int i = 1; i <= 5; i++)
	// {
	// 	v.push_back(i);
	// 	// to_insert.push_back(i*5);
	// }
	// v.insert(v.begin()+2, 2, 122);
	// v.insert(v.begin() + 1, to_insert.begin(), to_insert.begin() + 2);
	// v.insert(v.begin() + 5, to_insert.begin(), to_insert.end());
	// 1 99 999 2 122 99 999 9999 122 3 4 5
	// v.print();
	// to_insert.print();
	// v.print_info();
	// print(v);
	// print(to_insert);
	// ft::vector<int>::reverse_iterator it = v.rbegin();

	// std::cout << *it << std::endl;
	// std::cout << "First element (using rbegin): " << *v.rbegin() << std::endl;
	// std::cout << "Last element (using rend): " << *(v.rend() - 1) << std::endl;
	// std::cout << "First element (using begin): " << *v.begin() << std::endl;
	// std::cout << "Last element (using end): " << *(v.end() - 1) << std::endl;

	// t1.push_back(5);
	// t1.push_back(7);
	// t1.push_back(2);
	// t1.push_back(1);
	// t1.push_back(5);

	// std::vector<int> t(t1.begin(), t1.end());
	// std::vector<int> t3(5, 11);

	// ft::vector<int> b;
	// ft::vector<int> vec;

	// b.push_back(5);
	// b.push_back(7);
	// b.push_back(2);
	// b.push_back(1);
	// b.push_back(5);

	// std::vector<int>::iterator it = b.begin();
	// // ft::vector<int>::iterator it1 = b.begin() + 3;

	// it += 10;
	// std::cout << (b == vec) << std::endl;
	// a.swap(b);
	// print(a);
	// print_infos(a);

	// print(b);
	// print_infos(b);

	// system("leaks containers");
	RBT<int, int> tree;

	tree.insert(10, 29);
	tree.insert(20, 12);
	tree.insert(30, 22);
	tree.insert(5, 10);

	tree.printTree();

    return 0;
}
