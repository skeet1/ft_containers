/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:44:54 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/08 18:03:45 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITER
#define VECTOR_ITER

#include <iterator>
#include "../utils/iterator_traits.hpp"

namespace ft
{
	template <class Category,			// iterator::iterator_category
	class T,							// iterator::value_type
	class Distance = ptrdiff_t,			// iterator::difference_type
	class Pointer = T*,					// iterator::pointer
	class Reference = T&				// iterator::reference
	>
	class vector_Iter : public ft::iterator<std::random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator_traits<iterator<Category, T> >::value_type				value_type;
			typedef typename ft::iterator_traits<iterator<Category, T> >::difference_type			difference_type;
			typedef typename ft::iterator_traits<iterator<Category, T> >::pointer					pointer;
			typedef typename ft::iterator_traits<iterator<Category, T> >::reference					reference;
			typedef typename ft::iterator_traits<iterator<Category, T> >::iterator_category			iterator_tag;

		private:
			pointer _ptr;
		public:
			vector_Iter()
			{
				_ptr = NULL;
			}
			vector_Iter(value_type* ptr)
			{
				_ptr = ptr;
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

			T& operator*() const
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

	// reverse
	template <class Category,					// iterator::iterator_category
	class T,									// iterator::value_type
	class Distance = ptrdiff_t,					// iterator::difference_type
	class Pointer = T*,							// iterator::pointer
	class Reference = T&						// iterator::reference
	>
	class vector_Rev_Iter
	{
		public:
			typedef typename ft::iterator_traits<iterator<std::random_access_iterator_tag, T> >::value_type				value_type;
			typedef typename ft::iterator_traits<iterator<std::random_access_iterator_tag, T> >::difference_type		difference_type;
			typedef typename ft::iterator_traits<iterator<std::random_access_iterator_tag, T> >::pointer				pointer;
			typedef typename ft::iterator_traits<iterator<std::random_access_iterator_tag, T> >::reference				reference;
			typedef typename ft::iterator_traits<iterator<std::random_access_iterator_tag, T> >::iterator_category		iterator_tag;

		private:
			vector_Iter<Category, value_type> _it;
		
		public:
			vector_Rev_Iter()
			{}
			vector_Rev_Iter(vector_Iter<Category, value_type> it): _it(it)
			{}

			~vector_Rev_Iter()
			{}

			vector_Rev_Iter	operator++()
			{
				--_it;
				return *this;
			}
			

			vector_Rev_Iter operator++(int)
			{
				_it--;
				return *this;
			}

			vector_Rev_Iter operator--()
			{
				++_it;
				return *this;
			}

			vector_Rev_Iter operator--(int)
			{
				_it++;
				return *this;
			}
			
			vector_Rev_Iter operator+(int val)
			{
				vector_Rev_Iter tmp;
				tmp._it = _it - val;
				return tmp;
			}

			vector_Rev_Iter operator-(int val)
			{
				vector_Rev_Iter tmp;
				tmp._it = _it + val;
				return tmp;
			}

			vector_Rev_Iter& operator+=(int val)
			{
				_it -= val;
				return *this;
			}

			vector_Rev_Iter& operator-=(int val)
			{
				_it += val;
				return *this;
			}

			difference_type operator+(const vector_Rev_Iter& iter)
			{
				return _it + iter._it;
			}

			difference_type operator-(const vector_Rev_Iter& iter)
			{
				return _it - iter._it;
			}

			T& operator*() const
			{
				return *_it;
			}

			bool operator!=(const vector_Rev_Iter &obj)
			{
				return _it != obj._it;
			}

			bool operator==(const vector_Rev_Iter &obj)
			{
				return _it == obj._it;
			}

			bool operator>(const vector_Rev_Iter &obj)
			{
				return _it > obj._it;
			}
			
			bool operator<(const vector_Rev_Iter &obj)
			{
				return _it < obj._it;
			}

			bool operator>=(const vector_Rev_Iter &obj)
			{
				return _it >= obj._it;
			}
			
			bool operator<=(const vector_Rev_Iter &obj)
			{
				return _it <= obj._it;
			}
	};
}

#endif