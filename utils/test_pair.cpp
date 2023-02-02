/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:56:11 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/28 12:00:22 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "pair.hpp"

int main ()
{
    ft::pair<int,char> foo (10,'z');
    ft::pair<int,char> bar (90,'a');

    ft::pair<int, int> p = ft::make_pair(10, 20);

    std::cout << p.first << " " << p.second << std::endl;

    return 0;
}