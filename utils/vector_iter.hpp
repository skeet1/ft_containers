/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:44:54 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/12 08:00:24 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITER
#define VECTOR_ITER

#include <iterator>
#include "../utils/iterator_traits.hpp"

namespace ft
{
	template <class T>
	class vector_Iter
	{
		public:
			typedef typename ft::iterator_traits<T>::value_type						value_type;
			typedef typename ft::iterator_traits<T>::difference_type				difference_type;
			typedef typename ft::iterator_traits<T>::pointer						pointer;
			typedef typename ft::iterator_traits<T>::reference						reference;
			typedef typename ft::iterator_traits<T>::iterator_category				iterator_tag;

		private:
			pointer _ptr;
		public:
			pointer base() const 
			{ 
				return (this->_ptr);
			}

			vector_Iter(): _ptr(nullptr)
			{
			}
			
			vector_Iter(pointer ptr): _ptr(ptr)
			{
			}
			
			template <class U> 
			vector_Iter(const vector_Iter<U> &obj) : _ptr(obj.base())
			{
			}
			
			vector_Iter operator++()
			{
				++_ptr;
				return *this;
			}

			vector_Iter operator++(int)
			{
				vector_Iter tmp;
				tmp._ptr = _ptr;
				_ptr++;
				return tmp;
			}

			vector_Iter operator--()
			{
				--_ptr;
				return *this;
			}

			vector_Iter operator--(int)
			{
				vector_Iter tmp;
				tmp._ptr = _ptr;
				_ptr--;
				return tmp;
			}
			
			vector_Iter operator+(int val)
			{
				vector_Iter tmp;
				tmp._ptr = _ptr + val;
				return tmp;
			}

			vector_Iter operator-(int val)
			{
				vector_Iter tmp;
				tmp._ptr = _ptr - val;
				return tmp;
			}

			vector_Iter& operator+=(int val)
			{
				_ptr += val;
				return *this;
			}

			vector_Iter& operator-=(int val)
			{
				_ptr -= val;
				return *this;
			}

			difference_type operator+(const vector_Iter& iter)
			{
				return _ptr + iter._ptr;
			}

			difference_type operator-(const vector_Iter& iter)
			{
				return _ptr - iter._ptr;
			}

			reference operator*() const
			{
				return *_ptr;
			}

			bool operator!=(const vector_Iter &obj)
			{
				return _ptr != obj._ptr;
			}
			
			bool operator==(const vector_Iter &obj)
			{
				return _ptr == obj._ptr;
			}

			bool operator>(const vector_Iter &obj)
			{
				return _ptr > obj._ptr;
			}
			
			bool operator<(const vector_Iter &obj)
			{
				return _ptr < obj._ptr;
			}

			bool operator>=(const vector_Iter &obj)
			{
				return _ptr >= obj._ptr;
			}
			
			bool operator<=(const vector_Iter &obj)
			{
				return _ptr <= obj._ptr;
			}
	};
}

#endif