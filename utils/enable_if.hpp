/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:24:52 by mkarim            #+#    #+#             */
/*   Updated: 2022/12/28 12:16:26 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

#include <iostream>

/*
    def ::
        enable_if it's a template used to enable or disable
        a function or class template based on a boolean condition
    
	How it works ::
        
*/

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