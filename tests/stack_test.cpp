/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:15:41 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/12 15:18:02 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.hpp"
#include <stack>

void    stack_test()
{
	// constructor test
	// NAME::vector<int> vec1 (3,100);
	// NAME::vector<int> myvector (2,200);

	// NAME::stack<int> first;

	// NAME::stack<int,NAME::vector<int> > third;
	// NAME::stack<int,NAME::vector<int> > fourth (myvector);

	// std::cout << "size of first: " << first.size() << '\n';
	// std::cout << "size of third: " << third.size() << '\n';
	// std::cout << "size of fourth: " << fourth.size() << '\n';

	// empty test
	// NAME::stack<int> mystack;
	// int sum (0);

	// for (int i=1;i<=10;i++) mystack.push(i);

	// while (!mystack.empty())
	// {
	// 	sum += mystack.top();
	// 	mystack.pop();
	// }
	// std::cout << "total: " << sum << '\n';

	// pop and push test
	// NAME::stack<int> mystack;

	// for (int i=0; i<5; ++i) mystack.push(i);

	// std::cout << "Popping out elements...";
	// while (!mystack.empty())
	// {
	// 	std::cout << ' ' << mystack.top();
	// 	mystack.pop();
	// }
	// std::cout << '\n';

	// size test
	// NAME::stack<int> myints;
	// std::cout << "0. size: " << myints.size() << '\n';

	// for (int i=0; i<5; i++) myints.push(i);
	// std::cout << "1. size: " << myints.size() << '\n';

	// myints.pop();
	// std::cout << "2. size: " << myints.size() << '\n';

	// top test
	// NAME::stack<int> mystack;

	// mystack.push(10);
	// mystack.push(20);

	// mystack.top() -= 5;

	// std::cout << "mystack.top() is now " << mystack.top() << '\n';


	// non-member overload - relational operators
	// NAME::stack<int> st1;
	// NAME::stack<int> st2;
	
	// for (int i = 1; i <= 10; i++)
	// {
	// 	st1.push(i);
	// 	st2.push(i*2);
	// }
	// std::cout << std::boolalpha;
	// std::cout << (st1 == st2) << std::endl;
	// std::cout << (st1 != st2) << std::endl;
	// std::cout << (st1 <= st2) << std::endl;
	// std::cout << (st1 >= st2) << std::endl;
	// std::cout << (st1 < st2) << std::endl;
	// std::cout << (st1 > st2) << std::endl;
}