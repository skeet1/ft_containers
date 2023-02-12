/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:30:09 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/12 15:00:56 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.hpp"
#include <vector>

/*
	some helper functions, you will need those function when you want to print
	the content to see the difference between ft and std;

	even if you test (map, set or stack contaienrs), use std::vector 
	to store the result and then you can easly check the diff.

	else that you are a programmer you don't need me
	to teach you how to check a code ;)
*/

/* start Helper functions */

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

/* end helper functions */

void    vector_test()
{
	// constructor test
	// NAME::vector<int> v;

	// NAME::vector<int> first;
	// NAME::vector<int> second (4,100);
	// NAME::vector<int> third (second.begin(),second.end());
	// NAME::vector<int> fourth (third);

	// int myints[] = {16,2,77,29};
	// NAME::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	// std::cout << "The contents of fifth are:";
	// for (NAME::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// assing test
	// NAME::vector<int> first;
	// NAME::vector<int> second;
	// NAME::vector<int> third;

	// first.assign (7,100);

	// NAME::vector<int>::iterator it;
	// it=first.begin()+1;

	// second.assign (it,first.end()-1);

	// int myints[] = {1776,7,4};
	// third.assign (myints,myints+3);

	// std::cout << "Size of first: " << int (first.size()) << '\n';
	// std::cout << "Size of second: " << int (second.size()) << '\n';
	// std::cout << "Size of third: " << int (third.size()) << '\n';

	// at test
	// NAME::vector<int> myvector (10);

	// for (unsigned i=0; i<myvector.size(); i++)
	// 	myvector.at(i)=i;

	// std::cout << "myvector contains:";
	// for (unsigned i=0; i<myvector.size(); i++)
	// 	std::cout << ' ' << myvector.at(i);
	// std::cout << '\n';

	// back test
	// NAME::vector<int> myvector;

	// myvector.push_back(10);

	// while (myvector.back() != 0)
	// {
	// 	myvector.push_back ( myvector.back() -1 );
	// }

	// std::cout << "myvector contains:";
	// for (unsigned i=0; i<myvector.size() ; i++)
	// 	std::cout << ' ' << myvector[i];
	// std::cout << '\n';

	// begin test
	// NAME::vector<int> myvector;
	// for (int i=1; i<=5; i++) myvector.push_back(i);

	// std::cout << "myvector contains:";
	// for (NAME::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// capacity test
	// NAME::vector<int> myvector;
	// for (int i=0; i<100; i++)
	// 	myvector.push_back(i);
	// std::cout << "size: " << (int) myvector.size() << '\n';
	// std::cout << "capacity: " << (int) myvector.capacity() << '\n';
	// std::cout << "max_size: " << (int) myvector.max_size() << '\n';

	// clear test
	// NAME::vector<int> myvector;
	// myvector.push_back (100);
	// myvector.push_back (200);
	// myvector.push_back (300);

	// std::cout << "myvector contains:";
	// for (unsigned i=0; i<myvector.size(); i++)
	// 	std::cout << ' ' << myvector[i];
	// std::cout << '\n';

	// myvector.clear();
	// myvector.push_back (1101);
	// myvector.push_back (2202);

	// std::cout << "myvector contains:";
	// for (unsigned i=0; i<myvector.size(); i++)
	// 	std::cout << ' ' << myvector[i];
	// std::cout << '\n';

	// empty test
	// NAME::vector<int> myvector;
	// int sum (0);
	// for (int i=1;i<=10;i++) myvector.push_back(i);
	// while (!myvector.empty())
	// {
	// 	sum += myvector.back();
	// 	myvector.pop_back();
	// }
	// std::cout << "total: " << sum << '\n';

	// end test
	// NAME::vector<int> myvector;
	// for (int i=1; i<=5; i++) myvector.push_back(i);

	// std::cout << "myvector contains:";
	// for (NAME::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// erase test
	// NAME::vector<int> myvector;
	// for (int i=1; i<=10; i++) myvector.push_back(i);
	// myvector.erase (myvector.begin()+5);
	// myvector.erase (myvector.begin(),myvector.begin()+3);
	// std::cout << "myvector contains:";
	// for (unsigned i=0; i<myvector.size(); ++i)
	// 	std::cout << ' ' << myvector[i];
	// std::cout << '\n';

	// front test
	// NAME::vector<int> myvector;
	// myvector.push_back(78);
	// myvector.push_back(16);
	// myvector.front() -= myvector.back();
	// std::cout << "myvector.front() is now " << myvector.front() << '\n';

	// get_allocator test
	// NAME::vector<int> myvector;
	// int * p;
	// unsigned int i;
	// p = myvector.get_allocator().allocate(5);
	// for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
	// std::cout << "The allocated array contains:";
	// for (i=0; i<5; i++) std::cout << ' ' << p[i];
	// std::cout << '\n';
	// for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	// myvector.get_allocator().deallocate(p,5);

	// insert test
	// NAME::vector<int> myvector (3,100);
	// NAME::vector<int>::iterator it;
	// it = myvector.begin();
	// it = myvector.insert ( it , 200 );
	// myvector.insert (it,2,300);
	// it = myvector.begin();
	// NAME::vector<int> anothervector (2,400);
	// myvector.insert (it+2,anothervector.begin(),anothervector.end());
	// int myarray [] = { 501,502,503 };
	// myvector.insert (myvector.begin(), myarray, myarray+3);
	// std::cout << "myvector contains:";
	// for (it=myvector.begin(); it<myvector.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// max_size test
	// NAME::vector<int> myvector;
	// for (int i=0; i<100; i++) myvector.push_back(i);
	// std::cout << "size: " << myvector.size() << "\n";
	// std::cout << "capacity: " << myvector.capacity() << "\n";
	// std::cout << "max_size: " << myvector.max_size() << "\n";

	// operator[]
	// NAME::vector<int> myvector (10);
	// NAME::vector<int>::size_type sz = myvector.size();
	// for (unsigned i=0; i<sz; i++) myvector[i]=i;
	// for (unsigned i=0; i<sz/2; i++)
	// {
	// 	int temp;
	// 	temp = myvector[sz-1-i];
	// 	myvector[sz-1-i]=myvector[i];
	// 	myvector[i]=temp;
	// }
	// std::cout << "myvector contains:";
	// for (unsigned i=0; i<sz; i++)
	// 	std::cout << ' ' << myvector[i];
	// std::cout << '\n';

	// operator= test
	// NAME::vector<int> foo (3,0);
	// NAME::vector<int> bar (5,0);

	// bar = foo;
	// foo = NAME::vector<int>();

	// std::cout << "Size of foo: " << int(foo.size()) << '\n';
	// std::cout << "Size of bar: " << int(bar.size()) << '\n';

    // pop_back test
	// NAME::vector<int> myvector;
	// int sum (0);
	// myvector.push_back (100);
	// myvector.push_back (200);
	// myvector.push_back (300);

	// while (!myvector.empty())
	// {
	// 	sum+=myvector.back();
	// 	myvector.pop_back();
	// }

	// std::cout << "The elements of myvector add up to " << sum << '\n';

	// push_back test
	// NAME::vector<int> myvector;
	// int myint;

	// std::cout << "Please enter some integers (enter 0 to end):\n";

	// do {
	// 	std::cin >> myint;
	// 	myvector.push_back (myint);
	// } while (myint);

	// std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";

	// rbegin test
	// NAME::vector<int> myvector (5);

	// int i=0;

	// NAME::vector<int>::reverse_iterator rit = myvector.rbegin();
	// for (; rit!= myvector.rend(); ++rit)
	// 	*rit = ++i;

	// std::cout << "myvector contains:";
	// for (NAME::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// rend test
	// NAME::vector<int> myvector (5);
	// NAME::vector<int>::reverse_iterator rit = myvector.rbegin();

	// int i=0;
	// for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
	// 	*rit = ++i;
	// std::cout << "myvector contains:";
	// for (NAME::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// reserve test
	// NAME::vector<int>::size_type sz;
	// NAME::vector<int> foo;
	// sz = foo.capacity();
	// std::cout << "making foo grow:\n";
	// for (int i=0; i<100; ++i) {
	// 	foo.push_back(i);
	// 	if (sz!=foo.capacity()) {
	// 	sz = foo.capacity();
	// 	std::cout << "capacity changed: " << sz << '\n';
	// 	}
	// }

	// NAME::vector<int> bar;
	// sz = bar.capacity();
	// bar.reserve(100);
	// std::cout << "making bar grow:\n";
	// for (int i=0; i<100; ++i) {
	// 	bar.push_back(i);
	// 	if (sz!=bar.capacity()) {
	// 	sz = bar.capacity();
	// 	std::cout << "capacity changed: " << sz << '\n';
	// 	}
	// }

	// resize test
	// NAME::vector<int> myvector;

	// for (int i=1;i<10;i++) myvector.push_back(i);

	// myvector.resize(5);
	// myvector.resize(8,100);
	// myvector.resize(12);

	// std::cout << "myvector contains:";
	// for (size_t i=0;i<myvector.size();i++)
	// 	std::cout << ' ' << myvector[i];
	// std::cout << '\n';

	// size test
	// NAME::vector<int> myints;
	// std::cout << "0. size: " << myints.size() << '\n';

	// for (int i=0; i<10; i++) myints.push_back(i);
	// 	std::cout << "1. size: " << myints.size() << '\n';

	// myints.insert (myints.end(),10,100);
	// std::cout << "2. size: " << myints.size() << '\n';

	// myints.pop_back();
	// std::cout << "3. size: " << myints.size() << '\n';

	// swap test
	// NAME::vector<int> foo (3,100);   // three ints with a value of 100
	// NAME::vector<int> bar (5,200);   // five ints with a value of 200

	// foo.swap(bar);

	// std::cout << "foo contains:";
	// for (unsigned i=0; i<foo.size(); i++)
	// 	std::cout << ' ' << foo[i];
	// std::cout << '\n';

	// std::cout << "bar contains:";
	// for (unsigned i=0; i<bar.size(); i++)
	// 	std::cout << ' ' << bar[i];
	// std::cout << '\n';

	// non member overload test
	// NAME::vector<int> foo (3,100);   // three ints with a value of 100
	// NAME::vector<int> bar (3,200);   // two ints with a value of 200

	// if (foo==bar) std::cout << "foo and bar are equal\n";
	// if (foo!=bar) std::cout << "foo and bar are not equal\n";
	// if (foo< bar) std::cout << "foo is less than bar\n";
	// if (foo> bar) std::cout << "foo is greater than bar\n";
	// if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	// if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	// swap(foo, bar);
	// if (foo==bar) std::cout << "foo and bar are equal\n";
	// if (foo!=bar) std::cout << "foo and bar are not equal\n";
	// if (foo< bar) std::cout << "foo is less than bar\n";
	// if (foo> bar) std::cout << "foo is greater than bar\n";
	// if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	// if (foo>=bar) std::cout << "foo is greater than or equal to bar\n"; 
}