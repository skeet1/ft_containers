/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:48:13 by mkarim            #+#    #+#             */
/*   Updated: 2022/12/19 12:10:45 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

void    print(std::vector<int> &v);
void    print_infos(std::vector<int> &v);

int main()
{
    std::vector<int> v;

    // v.push_back(5);
    // v.push_back(15);
    // v.push_back(25);
    // v.push_back(35);
    // v.push_back(45);

    // v.erase(v.begin()+2);
    // v.erase(v.begin()+2);

    std::cout << sizeof(v) << std::endl;
    print(v);
    print_infos(v);
    return 0;
}