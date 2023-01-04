/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:39:15 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/04 13:11:27 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include <iostream>

namespace ft {
    template <typename T> struct is_integral : std::integral_constant<bool,
    std::is_same<bool, T>::value ||
    std::is_same<char, T>::value ||
    std::is_same<signed char, T>::value ||
    std::is_same<unsigned char, T>::value ||
    std::is_same<wchar_t, T>::value ||
    std::is_same<short, T>::value ||
    std::is_same<unsigned short, T>::value ||
    std::is_same<int, T>::value ||
    std::is_same<unsigned int, T>::value ||
    std::is_same<long, T>::value ||
    std::is_same<unsigned long, T>::value ||
    std::is_same<long long, T>::value ||
    std::is_same<unsigned long long, T>::value> {};
}
#endif