/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:46:00 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/12 17:28:51 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.hpp"
#include <map>

void	print_map(std::map<char, int> mp)
{
	std::map<char, int>::iterator it = mp.begin();

	while (it != mp.end())
	{
		std::cout << it->first << " " << it->second << std::endl;
		it++;
	}
}

void	print_map(ft::map<char, int> mp)
{
	ft::map<char, int>::iterator it = mp.begin();

	while (it != mp.end())
	{
		std::cout << it->first << " " << it->second << std::endl;
		it++;
	}
}

// for constructor test
bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

void    map_test()
{
    // constructor test
	// NAME::map<char,int> first;

	// first['a']=10;
	// first['b']=30;
	// first['c']=50;
	// first['d']=70;

	// NAME::map<char,int> second (first.begin(),first.end());

	// NAME::map<char,int> third (second);

	// NAME::map<char,int,classcomp> fourth;

	// bool(*fn_pt)(char,char) = fncomp;
	// NAME::map<char,int,bool(*)(char,char)> fifth (fn_pt);
	// print_map(first);
	// std::cout << std::endl;
	// print_map(second);
	// std::cout << std::endl;
	// print_map(third);



	// begin test
	// NAME::map<char,int> mymap;

	// mymap['b'] = 100;
	// mymap['a'] = 200;
	// mymap['c'] = 300;

	// for (NAME::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';



	// clear test
	// NAME::map<char,int> mymap;
	// mymap['x']=100;
	// mymap['y']=200;
	// mymap['z']=300;
	// std::cout << "mymap contains:\n";
	// for (NAME::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';
	// mymap.clear();
	// mymap['a']=1101;
	// mymap['b']=2202;
	// std::cout << "mymap contains:\n";
	// for (NAME::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';



	// count test
	// NAME::map<char,int> mymap;
	// char c;

	// mymap ['a']=101;
	// mymap ['c']=202;
	// mymap ['f']=303;

	// for (c='a'; c<'h'; c++)
	// {
	// 	std::cout << c;
	// 	if (mymap.count(c)>0)
	// 	std::cout << " is an element of mymap.\n";
	// 	else 
	// 	std::cout << " is not an element of mymap.\n";
	// }



	// empty test
    // NAME::map<char,int> mymap;

    // mymap['a']=10;
    // mymap['b']=20;
    // mymap['c']=30;

    // while (!mymap.empty())
    // {
    //     std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    //     mymap.erase(mymap.begin());
    // }



	// end test
    // NAME::map<char,int> mymap;

    // mymap['b'] = 100;
    // mymap['a'] = 200;
    // mymap['c'] = 300;

    // for (NAME::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';



	// equal range tes
    // NAME::map<char,int> mymap;

    // mymap['a']=10;
    // mymap['b']=20;
    // mymap['c']=30;

    // NAME::pair<NAME::map<char,int>::iterator,NAME::map<char,int>::iterator> ret;
    // ret = mymap.equal_range('b');

    // std::cout << "lower bound points to: ";
    // std::cout << ret.first->first << " => " << ret.first->second << '\n';

    // std::cout << "upper bound points to: ";
    // std::cout << ret.second->first << " => " << ret.second->second << '\n';



	// erase test
    // NAME::map<char,int> mymap;
    // NAME::map<char,int>::iterator it;

    // // insert some values:
    // mymap['a']=10;
    // mymap['b']=20;
    // mymap['c']=30;
    // mymap['d']=40;
    // mymap['e']=50;
    // mymap['f']=60;

    // it=mymap.find('b');
    // mymap.erase (it);                   // erasing by iterator

    // mymap.erase ('c');                  // erasing by key

    // it=mymap.find ('e');
    // mymap.erase ( it, mymap.end() );    // erasing by range

    // // show content:
    // for (it=mymap.begin(); it!=mymap.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';



	// find test
    // NAME::map<char,int> mymap;
    // NAME::map<char,int>::iterator it;

    // mymap['a']=50;
    // mymap['b']=100;
    // mymap['c']=150;
    // mymap['d']=200;

    // it = mymap.find('b');
    // if (it != mymap.end())
    //     mymap.erase (it);

    // // print content:
    // std::cout << "elements in mymap:" << '\n';
    // std::cout << "a => " << mymap.find('a')->second << '\n';
    // std::cout << "c => " << mymap.find('c')->second << '\n';
    // std::cout << "d => " << mymap.find('d')->second << '\n';



	// get_allocator test
    // int psize;
    // NAME::map<char,int> mymap;
    // NAME::pair<const char,int>* p;

    // // allocate an array of 5 elements using mymap's allocator:
    // p=mymap.get_allocator().allocate(5);

    // // assign some values to array
    // psize = sizeof(NAME::map<char,int>::value_type)*5;

    // std::cout << "The allocated array has a size of " << psize << " bytes.\n";

    // mymap.get_allocator().deallocate(p,5);



	// insert test
    // NAME::map<char,int> mymap;

    // // first insert function version (single parameter):
    // mymap.insert ( NAME::pair<char,int>('a',100) );
    // mymap.insert ( NAME::pair<char,int>('z',200) );

    // NAME::pair<NAME::map<char,int>::iterator,bool> ret;
    // ret = mymap.insert ( NAME::pair<char,int>('z',500) );
    // if (ret.second==false) {
    //     std::cout << "element 'z' already existed";
    //     std::cout << " with a value of " << ret.first->second << '\n';
    // }

    // // second insert function version (with hint position):
    // NAME::map<char,int>::iterator it = mymap.begin();
    // mymap.insert (it, NAME::pair<char,int>('b',300));  // max efficiency inserting
    // mymap.insert (it, NAME::pair<char,int>('c',400));  // no max efficiency inserting

    // // third insert function version (range insertion):
    // NAME::map<char,int> anothermap;
    // anothermap.insert(mymap.begin(),mymap.find('c'));

    // // showing contents:
    // std::cout << "mymap contains:\n";
    // for (it=mymap.begin(); it!=mymap.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';

    // std::cout << "anothermap contains:\n";
    // for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';


	// key_comp
    // NAME::map<char,int> mymap;

    // NAME::map<char,int>::key_compare mycomp = mymap.key_comp();

    // mymap['a']=100;
    // mymap['b']=200;
    // mymap['c']=300;

    // std::cout << "mymap contains:\n";

    // char highest = mymap.rbegin()->first;     // key value of last element

    // NAME::map<char,int>::iterator it = mymap.begin();
    // do {
    //     std::cout << it->first << " => " << it->second << '\n';
    // } while ( mycomp((*it++).first, highest) );

    // std::cout << '\n';



	// lower_bound
    // NAME::map<char,int> mymap;
    // NAME::map<char,int>::iterator itlow,itup;

    // mymap['a']=20;
    // mymap['b']=40;
    // mymap['c']=60;
    // mymap['d']=80;
    // mymap['e']=100;

    // itlow=mymap.lower_bound ('b');
    // itup=mymap.upper_bound ('d');

	// std::cout << "lower bound is " << itlow->first << " " << itlow->second << std::endl;
	// std::cout << "upper bound is " << itup->first << " " << itup->second << std::endl;



	// max_size test
    // int i;
    // NAME::map<int,int> mymap;

    // if (mymap.max_size()>1000)
    // {
    //     for (i=0; i<1000; i++) mymap[i]=0;
    //     std::cout << "The map contains 1000 elements.\n";
    // }
    // else std::cout << "The map could not hold 1000 elements.\n";



	// operator[] test
	// NAME::map<char,std::string> mymap;

	// mymap['a']="an element";
	// mymap['b']="another element";
	// mymap['c']=mymap['b'];

	// std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	// std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	// std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	// std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	// std::cout << "mymap now contains " << mymap.size() << " elements.\n";



	// operator= test
	// NAME::map<char,int> first;
	// NAME::map<char,int> second;

	// first['x']=8;
	// first['y']=16;
	// first['z']=32;

	// second = first;                // second now contains 3 ints
	// first = NAME::map<char,int>();  // and first is now empty

	// std::cout << "Size of first: " << first.size() << '\n';
	// std::cout << "Size of second: " << second.size() << '\n';



	// rbegin test
	// NAME::map<char,int> mymap;

	// mymap['x'] = 100;
	// mymap['y'] = 200;
	// mymap['z'] = 300;


	// NAME::map<char,int>::reverse_iterator rit;
	// for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
	// 	std::cout << rit->first << " => " << rit->second << '\n';



	// rend()
	// NAME::map<char,int> mymap;

	// mymap['x'] = 100;
	// mymap['y'] = 200;
	// mymap['z'] = 300;

	// // show content:
	// NAME::map<char,int>::reverse_iterator rit;
	// for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
	// 	std::cout << rit->first << " => " << rit->second << '\n';



	// size test
	// NAME::map<char,int> mymap;
	// mymap['a']=101;
	// mymap['b']=202;
	// mymap['c']=302;

	// std::cout << "mymap.size() is " << mymap.size() << '\n';



	// swap test
	// NAME::map<char,int> foo,bar;

	// foo['x']=100;
	// foo['y']=200;

	// bar['a']=11;
	// bar['b']=22;
	// bar['c']=33;

	// foo.swap(bar);

	// std::cout << "foo contains:\n";
	// for (NAME::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';

	// std::cout << "bar contains:\n";
	// for (NAME::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';



	// upper_bound_test
	// std::map<char,int> mymap;
	// std::map<char,int>::iterator itlow,itup;

	// mymap['a']=20;
	// mymap['b']=40;
	// mymap['c']=60;
	// mymap['d']=80;
	// mymap['e']=100;

	// itlow=mymap.lower_bound ('b');  // itlow points to b
	// itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	// mymap.erase(itlow,itup);        // erases [itlow,itup)

	// // print content:
	// for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';



    // value_comp test
	// NAME::map<char,int> mymap;

	// mymap['x']=1001;
	// mymap['y']=2002;
	// mymap['z']=3003;

	// std::cout << "mymap contains:\n";

	// NAME::pair<char,int> highest = *mymap.rbegin();          // last element

	// NAME::map<char,int>::iterator it = mymap.begin();
	// do {
	// 	std::cout << it->first << " => " << it->second << '\n';
	// } while ( mymap.value_comp()(*it++, highest) );



	// relational_operators test
	// NAME::map<char,int> foo,bar;
	// foo['a']=100;
	// foo['b']=200;
	// bar['a']=10;
	// bar['z']=1000;

	// // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	// if (foo==bar) std::cout << "foo and bar are equal\n";
	// if (foo!=bar) std::cout << "foo and bar are not equal\n";
	// if (foo< bar) std::cout << "foo is less than bar\n";
	// if (foo> bar) std::cout << "foo is greater than bar\n";
	// if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	// if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";


	// swap test
	// NAME::map<char,int> foo,bar;
	// foo['x']=100;
	// foo['y']=200;

	// bar['a']=11;
	// bar['b']=22;
	// bar['c']=33;

	// swap(foo,bar);

	// std::cout << "foo contains:\n";
	// for (NAME::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';

	// std::cout << "bar contains:\n";
	// for (NAME::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';

}