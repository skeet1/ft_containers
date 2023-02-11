/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:44:43 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/11 20:29:17 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR

#include "iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class ReverseIterator {
		public:
			typedef Iterator                                                            iterator_type;
			typedef typename ft::iterator_traits<Iterator>::value_type				    value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type			    difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer					    pointer;
			typedef typename ft::iterator_traits<Iterator>::reference					reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category			iterator_tag;

		private:
			iterator_type _it;

		public:
			ReverseIterator()
			{}
			ReverseIterator(iterator_type it): _it(it)
			{}

			~ReverseIterator()
			{}

			iterator_type   base() const
			{
				return _it;
			}

			ReverseIterator operator+(difference_type n) const
			{
				ReverseIterator tmp;
				tmp._it = _it;
				while (n--)
					tmp++;
				return tmp;
			}

			ReverseIterator    operator++()
			{
				return ReverseIterator(--_it);
			}

			ReverseIterator    operator++(int)
			{
				return ReverseIterator(_it--);
			}

			ReverseIterator&    operator+=(difference_type n)
			{
				_it -= n;
				return &ReverseIterator(_it);
			}

			ReverseIterator operator-(difference_type n) const
			{
				ReverseIterator tmp;
				tmp._it = _it;
				while (n--)
					tmp--;
				return tmp;
			}

			ReverseIterator    operator--()
			{
				return ReverseIterator(++_it);
			}

			ReverseIterator    operator--(int)
			{
				return ReverseIterator(_it++);
			}

			ReverseIterator&    operator-=(difference_type n)
			{
				_it += n;
				return &ReverseIterator(_it);
			}

			value_type   operator*() const
			{
				iterator_type copy = _it;
				copy--;
				return *copy;
			}

			iterator_type operator->() const
			{
				iterator_type copy = _it;
				copy--;
				return copy;
			}

			reference operator[] (difference_type n) const
			{
				return &(base()[-n-1]);
			}

			bool operator!=(const ReverseIterator &obj)
			{
				return _it != obj._it;
			}

			bool operator==(const ReverseIterator &obj)
			{
				return _it == obj._it;
			}

			bool operator>(const ReverseIterator &obj)
			{
				return _it > obj._it;
			}
			
			bool operator<(const ReverseIterator &obj)
			{
				return _it < obj._it;
			}

			bool operator>=(const ReverseIterator &obj)
			{
				return _it >= obj._it;
			}
			
			bool operator<=(const ReverseIterator &obj)
			{
				return _it <= obj._it;
			}
	};
}

#endif
