/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:24:52 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/12 14:32:49 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

#include <iostream>

namespace ft {
    template< bool cond, class T = void >
    struct enable_if {
        
    };
    template<typename T>
    struct enable_if<true, T>
    {
        typedef T type;
    };
}

#endif