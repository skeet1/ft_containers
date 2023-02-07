/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 06:47:57 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/07 16:50:11 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T											value_type;
		typedef Distance									difference_type;
		typedef Pointer										pointer;
		typedef Reference									reference;
		typedef Category									iterator_category;
	};

	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type			difference_type;
		typedef typename Iterator::value_type				value_type;
		typedef typename Iterator::pointer					pointer;
		typedef typename Iterator::reference				reference;
		typedef typename Iterator::iterator_category		iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t									difference_type;
		typedef T											value_type;
		typedef T*											pointer;
		typedef T&											reference;
		typedef std::random_access_iterator_tag				iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t									difference_type;
		typedef T											value_type;
		typedef const T*									pointer;
		typedef const T&									reference;
		typedef std::random_access_iterator_tag				iterator_category;
	};
}
#endif
