/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:18:06 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/12 17:27:13 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/set.hpp"
#include <set>

void    set_test()
{
    // consturctor test
	// NAME::set<int> first;

	// int myints[]= {10,20,30,40,50};
	// NAME::set<int> second (myints,myints+5);

	// NAME::set<int> third (second);

	// NAME::set<int> fourth (second.begin(), second.end());



    // begin test
	// int myints[] = {75,23,65,42,13};
	// NAME::set<int> myset (myints,myints+5);

	// std::cout << "myset contains:";
	// for (NAME::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	// 	std::cout << ' ' << *it;

	// std::cout << '\n';




    // clear test
    // NAME::set<int> myset;
	// myset.insert (100);
	// myset.insert (200);
	// myset.insert (300);

	// std::cout << "myset contains:";
	// for (NAME::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// myset.clear();
	// myset.insert (1101);
	// myset.insert (2202);

	// std::cout << "myset contains:";
	// for (NAME::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';




    // count test
	// NAME::set<int> myset;

	// for (int i=1; i<5; ++i) myset.insert(i*3);

	// for (int i=0; i<10; ++i)
	// {
	// 	std::cout << i;
	// 	if (myset.count(i) != 0)
	// 	std::cout << " is an element of myset.\n";
	// 	else
	// 	std::cout << " is not an element of myset.\n";
	// }




    // empty test
    // NAME::set<int> myset;
	// myset.insert(20);
	// myset.insert(30);
	// myset.insert(10);

	// std::cout << "myset contains:";
	// while (!myset.empty())
	// {
	// 	std::cout << ' ' << *myset.begin();
	// 	myset.erase(myset.begin());
	// }
	// std::cout << '\n';




    // end test
	// int myints[] = {75,23,65,42,13};
	// NAME::set<int> myset (myints,myints+5);
	// std::cout << "myset contains:";
	// for (NAME::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';



    // equal_range test
    // NAME::set<int> myset;

    // for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

    // NAME::pair<NAME::set<int>::const_iterator,NAME::set<int>::const_iterator> ret;
    // ret = myset.equal_range(30);

    // std::cout << "the lower bound points to: " << *ret.first << '\n';
    // std::cout << "the upper bound points to: " << *ret.second << '\n';



    // erase test
	// NAME::set<int> myset;
	// NAME::set<int>::iterator it;

	// // insert some values:
	// for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

	// it = myset.begin();
	// ++it;                                         // "it" points now to 20

	// myset.erase (it);

	// myset.erase (40);

	// it = myset.find (60);
	// myset.erase (it, myset.end());

	// std::cout << "myset contains:";
	// for (it=myset.begin(); it!=myset.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';




    // find test
	// NAME::set<int> myset;
	// NAME::set<int>::iterator it;

	// for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

	// it=myset.find(20);
	// myset.erase (it);
	// myset.erase (myset.find(40));

	// std::cout << "myset contains:";
	// for (it=myset.begin(); it!=myset.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';



    // get_allocator test
	// NAME::set<int> myset;
	// int * p;
	// unsigned int i;

	// // allocate an array of 5 elements using myset's allocator:
	// p = myset.get_allocator().allocate(5);

	// // assign some values to array
	// for (i=0; i<5; i++) p[i]=(i+1)*10;

	// std::cout << "The allocated array contains:";
	// for (i=0; i<5; i++) std::cout << ' ' << p[i];
	// std::cout << '\n';

	// myset.get_allocator().deallocate(p,5);



    // insert test
	// NAME::set<int> myset;
	// NAME::set<int>::iterator it;
	// NAME::pair<NAME::set<int>::iterator,bool> ret;

	// // set some initial values:
	// for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

	// ret = myset.insert(20);               // no new element inserted

	// if (ret.second==false) it=ret.first;  // "it" now points to element 20

	// myset.insert (it,25);                 // max efficiency inserting
	// myset.insert (it,24);                 // max efficiency inserting
	// myset.insert (it,26);                 // no max efficiency inserting

	// int myints[]= {5,10,15};              // 10 already in set, not inserted
	// myset.insert (myints,myints+3);

	// std::cout << "myset contains:";
	// for (it=myset.begin(); it!=myset.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';



    // key_comp test
	// NAME::set<int> myset;
	// int highest;

	// NAME::set<int>::key_compare mycomp = myset.key_comp();

	// for (int i=0; i<=5; i++) myset.insert(i);

	// std::cout << "myset contains:";

	// highest=*myset.rbegin();
	// NAME::set<int>::iterator it=myset.begin();
	// do {
	// 	std::cout << ' ' << *it;
	// } while ( mycomp(*(++it),highest) );

	// std::cout << '\n';



    // lower_bound && upper_bound test
	// NAME::set<int> myset;
	// NAME::set<int>::iterator itlow,itup;

	// for (int i=1; i<10; i++) myset.insert(i*10);

	// itlow=myset.lower_bound (30);
	// itup=myset.upper_bound (60);

	// std::cout << "lower bound is : " << *itlow << std::endl;
	// std::cout << "upper bound is : " << *itup << std::endl;



    // max_size test
	// int i;
	// NAME::set<int> myset;

	// if (myset.max_size()>1000)
	// {
	// 	for (i=0; i<1000; i++) myset.insert(i);
	// 	std::cout << "The set contains 1000 elements.\n";
	// }
	// else std::cout << "The set could not hold 1000 elements.\n";



    // opertor= test
	// int myints[]={ 12,82,37,64,15 };
	// NAME::set<int> first (myints,myints+5);   // set with 5 ints
	// NAME::set<int> second;                    // empty set

	// second = first;                          // now second contains the 5 ints
	// first = NAME::set<int>();                 // and first is empty

	// std::cout << "Size of first: " << int (first.size()) << '\n';
	// std::cout << "Size of second: " << int (second.size()) << '\n';



    // rbegin && rend test
	// int myints[] = {21,64,17,78,49};
	// NAME::set<int> myset (myints,myints+5);

	// NAME::set<int>::reverse_iterator rit;

	// std::cout << "myset contains:";
	// for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
	// 	std::cout << ' ' << *rit;

	// std::cout << '\n';



    // size test
	// NAME::set<int> myints;
	// std::cout << "0. size: " << myints.size() << '\n';

	// for (int i=0; i<10; ++i) myints.insert(i);
	// std::cout << "1. size: " << myints.size() << '\n';

	// myints.insert (100);
	// std::cout << "2. size: " << myints.size() << '\n';

	// myints.erase(5);
	// std::cout << "3. size: " << myints.size() << '\n';



    // swap test
	// int myints[]={12,75,10,32,20,25};
	// NAME::set<int> first (myints,myints+3);     // 10,12,75
	// NAME::set<int> second (myints+3,myints+6);  // 20,25,32

	// first.swap(second);

	// std::cout << "first contains:";
	// for (NAME::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// std::cout << "second contains:";
	// for (NAME::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';




    // value_comp test
	// NAME::set<int> myset;

	// NAME::set<int>::value_compare mycomp = myset.value_comp();

	// for (int i=0; i<=5; i++) myset.insert(i);

	// std::cout << "myset contains:";

	// int highest=*myset.rbegin();
	// NAME::set<int>::iterator it=myset.begin();
	// do {
	// 	std::cout << ' ' << *it;
	// } while ( mycomp(*(++it),highest) );

	// std::cout << '\n';



    // relation operators 
	// NAME::set<int> foo,bar;
	// foo.insert(10);
	// bar.insert(20);
	// bar.insert(30);
	// foo.insert(40);

	// // foo ({10,40}) vs bar ({20,30}):
	// if (foo==bar) std::cout << "foo and bar are equal\n";
	// if (foo!=bar) std::cout << "foo and bar are not equal\n";
	// if (foo< bar) std::cout << "foo is less than bar\n";
	// if (foo> bar) std::cout << "foo is greater than bar\n";
	// if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	// if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";



    // swap test
	// int myints[]={12,75,10,32,20,25};
	// NAME::set<int> first (myints,myints+3);     // 10,12,75
	// NAME::set<int> second (myints+3,myints+6);  // 20,25,32

	// swap(first,second);

	// std::cout << "first contains:";
	// for (NAME::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// std::cout << "second contains:";
	// for (NAME::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';
}