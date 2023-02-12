/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:12:10 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/12 14:54:41 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./includes/vector.hpp"
#include "./includes/map.hpp"
#include "./includes/set.hpp"
#include "./includes/stack.hpp"
#include <vector>
#include <map>
#include <set>
#include <stack>

#define NAME std

/* 
    to test any special member function you can go to tests folder,
    there you will found a special file for each container, and for 
    each member function there's at least one test, otherwise you can
    make your own test in the main bellow, don't forget to use NAME
    a namespace and change it (ft/std) to see the difference.
    
    if you found any error, or you want ask me about anything, please 
    contact me :
    via mail      => mkarim@student.1337.ma
    via linkedIn  => https://www.linkedin.com/in/skeet1/
*/




int main()
{
    NAME::vector<int> v;

    for (int i = 1; i < 100; i++)
        v.push_back(i);
    
    v.erase(v.begin()+30, v.end());
    v.push_back(v.front());
    v.push_back(v.empty());
    v.erase(v.begin() + 7);
    v.push_back(*v.rbegin());
	return 0;
}

