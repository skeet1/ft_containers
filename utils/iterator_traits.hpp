/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 06:47:57 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/06 06:38:29 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <iterator>
#include "red_black_tree.hpp"

template <class Iterator>
class iterator_traits
{
	typedef typename Iterator::differene_type       difference_type;
	typedef typename Iterator::value_type           value_type;
	typedef typename Iterator::pointer              pointer;
	typedef typename Iterator::reference            reference;
	typedef typename Iterator::iterator_category    iterator_category;
};

template <class T>
class iterator_traits<T*>
{
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef std::random_access_iterator_tag iterator_category;
};

template <class T>
class iterator_traits<const T*>
{
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef const T* pointer;
	typedef const T& reference;
	typedef std::random_access_iterator_tag iterator_category;
};

#endif
