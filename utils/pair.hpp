/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:02:26 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/11 21:37:30 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

#include <type_traits>

namespace ft {
	template <class T1, class T2>
	struct pair
	{
		typedef T1      first_type;
		typedef T2      second_type;

		first_type      first;
		second_type     second;
		
		pair() : first() , second()
		{
		}

		template< class U1, class U2 >
		pair(const pair<U1, U2>& pr) : first(pr.first) , second(pr.second)
		{
		}

		pair(const first_type& a, const second_type& b): first(a), second(b)
		{
		}

		pair(const pair& p) : first(p.first) , second(p.second)
		{
		}

		pair&   operator=(const pair& pr)
		{
			if (&pr != this)
			{
				this->first = pr.first;
				this->second = pr.second;
			}
			return *this;
		}

		void	swap(pair& pr)
		{
			std::swap(first, pr.first);
			std::swap(second, pr.second);
		}
	};
	// relational operators
	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first != rhs.first || lhs.second != rhs.second);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first <= rhs.first || (lhs.first == rhs.first && lhs.second <= rhs.second));
	}

	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first > rhs.first || (lhs.first == rhs.first && lhs.second > rhs.second));
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first >= rhs.first || (lhs.first == rhs.first && lhs.second >= rhs.second));
	}

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		pair<T1, T2> p;

		p.first = x;
		p.second = y;
		return (p);
	}
}
#endif