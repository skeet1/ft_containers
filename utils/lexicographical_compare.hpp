/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:54:08 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/12 10:00:44 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_HPP
#define LEXICOGRAPHICAL_HPP

namespace ft
{
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
        {
            while (first1 != last1)
            {
                if (first2 == last2 || *first2 < *first1)
                    return false;
                else if (*first1 < *first2)
                    return true;
                ++first1;
                ++first2;
            }
            return (first2 != last2);
        }

    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || comp(*first2, *first1))
                return false;
            else if (comp(*first1, *first2))
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    template <class InputIterator1, class InputIterator2>
    bool    equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (*first1 != *first2)
                return false;
            first1++;
            first2++;
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool    equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1 != last1)
        {
            if (pred(*first1, *first2) == false)
                return false;
            first1++;
            first2++;
        }
        return true;
    }
}

#endif