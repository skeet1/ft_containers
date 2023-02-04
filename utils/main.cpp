/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:15:00 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/04 15:33:47 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "red_black_tree.hpp"
#include <map>
// #include <iostream>
typedef struct s
{
    std::string name;
    size_t      age;
}           st;

typedef std::less<char> Compare;
typedef ft::pair<char, int> value_type;
typedef RBT<value_type, std::less<value_type >, std::allocator<value_type> > Tree;
typedef RBT<value_type, std::less<value_type >, std::allocator<value_type> >::iterator Iterator;

int _main()
{
    Tree tree;
    Iterator it;
    
    for (int i = 0; i <= 6; i++)
        tree.insert(ft::pair<char, int>('a' + i , 2));
    // for (int i = 0; i <= 3; i++)
    //     tree.insert(ft::pair<char, int>('a' + i , 2));
    
    // std::cout << "iterat" << std::endl;
    // for (int i = 20 ; i <= 1000000; i+= 1)
    // {
    //     tree.remove(i);
    // }
    // tree.clear();
    tree.test();
    it = tree.begin();
    // std::map<int, int> mp;

    // for (int i = 1; i <= 10; i++)
    // {
    //     tree.insert(ft::make_pair<char, int>('a' + i - 1, i));
    // }

    // std::map<int, int>::iterator it = mp.begin();
    // std::cout << std::boolalpha;
    
    // std::cout << (tree.end() == it) << std::endl;
    tree.printTree();
    // tree.test();
    // Iterator ite = tree.begin();
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite++;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite++;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite++;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite++;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite++;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite++;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite++;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite--;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite--;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite--;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite--;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite--;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite--;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite--;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite--;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite--;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // ite--;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // std::cout << "right most " << it->first << " " << it->second << std::endl;
    for (; it != tree.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
    // for (; ite != tree.begin(); ite--)
    //     std::cout << it->first << " " << it->second << std::endl;
    // std::cout << ite->first << " " << ite->second << std::endl;

    // ite
    // while (1)
    // {
    //     if (it != tree.end())
    //     {
    //         std::cout << it->first << " " << it->second << std::endl;
    //         it++;
    //     }
    //     else
    //         break;
    // }
    // if (it != tree.end())
    // {
    //     std::cout << it->first << " " << it->second << std::endl;
    //     it++;
    // }
    // if (it != tree.end())
    // {
    //     std::cout << it->first << " " << it->second << std::endl;
    //     it++;
    // }
    // if (it != tree.end())
    // {
    //     std::cout << it->first << " " << it->second << std::endl;
    //     it++;
    // }
    // if (it != tree.end())
    // {
    //     std::cout << it->first << " " << it->second << std::endl;
    //     it++;
    // }
    // if (it != tree.end())
    // {
    //     std::cout << it->first << " " << it->second << std::endl;
    //     it++;
    // }
    // tree.printTree();
    // tree.clear();
    // for (int i = 0; i <= 3; i++)
    //     tree.insert(ft::pair<char, int>('a' + i , 2));
    // tree.printTree();

    // std::cout << it->first << " " << it->second << std::endl;

    // for (; it != tree.end(); ++it)
    // {
    //     std::cout << it->first << " " << it->second << std::endl;
    // }
    // for (; it != tree.end(); it++)
    //     std::cout << (it)->first << std::endl;
    // it--;
    // it--;
    // it--;
    // it--;
    // std::cout << it->first << std::endl;
    // *it;
    // for (; it != tree.end(); ++it)
    // {
    //     *it;
    // }

    // while (it != tree.end())
    // {
    //     std::cout << it->first << " " << it->second << std::endl;
    //     ++it;
    // }


    // system("leaks a.out");
    
    // tree.insert(40, 2);
    // tree.insert(60, 2);
    // tree.insert(20, 2);
    // tree.insert(80, 2);
    // tree.insert(30, 2);
    // tree.insert(10, 2);
    // tree.insert(70, 2);
    // tree.insert(90, 2);
    // tree.insert(100, 2);
    // tree.insert(5, 2);
    // tree.insert(15, 2);
    // tree.insert(105, 2);
    // tree.insert(102, 2);
    // tree.insert(95, 2);



    // tree.remove(40);
    // tree.remove(60);
    // tree.remove(70);
    // tree.remove(80);
    // tree.remove(90);
    // tree.remove(95);
    // tree.remove(100);
    // tree.remove(102);
    // tree.remove(20);
    // tree.remove(30);
    // tree.remove(10);
    // tree.remove(15);
    // tree.remove(105);
    // tree.remove(5);

    // tree.printTree();

    // Tree mymap;

    // Tree::value_compare mycomp = std::less<char>;

    // for (int i = 0; i <= 3; i++)
    //     mymap.insert(ft::pair<char, int>('a' + i , 2));

    // std::cout << "mymap contains:\n";


    // Iterator ite = mymap.end();
    // ite--;
    // std::cout << "seg" << std::endl;
    // std::cout << ite->first << " " << ite->second << std::endl;
    // char highest = ite->first;     // key value of last element
    // std::cout << "seg" << std::endl;

    // Iterator it = mymap.begin();
    // do {
    //     std::cout << it->first << " => " << it->second << '\n';
    // } while ( std::less<char>()((*it++).first, highest) );

	// std::cout << '\n';
    return 0;
    
}

int main()
{
    _main();
    // system("leaks a.out");
}