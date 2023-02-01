/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 06:01:38 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/31 11:56:11 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <stack>

namespace ft
{

    template <class T, class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef Container                                container_type;
            typedef typename container_type::value_type      value_type;
            typedef typename container_type::size_type       size_type;

        protected:
            container_type c;

        public:
            bool    empty() const
            {
                return c.size() == 0;
            }

            void    pop()
            {
                c.pop_back();
            }

            void    push(const value_type& val)
            {
                c.push_back(val);
            }

            size_type   size() const
            {
                return c.size();
            }

            value_type& top()
            {
                return c.back();
            }
            
            const   value_type& top() const
            {
                return c.back();
            }
            
            template <class T1, class Container1>
            friend bool operator==(const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
            
            template <class T1, class Container1>
            friend bool operator!=(const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
            
            template <class T1, class Container1>
            friend bool operator<(const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
            
            template <class T1, class Container1>
            friend bool operator<=(const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
            
            template <class T1, class Container1>
            friend bool operator>(const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
            
            template <class T1, class Container1>
            friend bool operator>=(const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
    };
    
    template <class T1, class Container1>
    bool operator==(const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs)
    {
        return lhs.c == rhs.c;
    }
    
    template <class T1, class Container1>
    bool operator!=(const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs)
    {
        return lhs.c != rhs.c;
    }
    
    template <class T1, class Container1>
    bool operator>(const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs)
    {
        return lhs.c > rhs.c;
    }
    
    template <class T1, class Container1>
    bool operator>=(const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs)
    {
        return lhs.c >= rhs.c;
    }
    
    template <class T1, class Container1>
    bool operator<(const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs)
    {
        return lhs.c < rhs.c;
    }
    
    template <class T1, class Container1>
    bool operator<=(const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs)
    {
        return lhs.c <= rhs.c;
    }
}
