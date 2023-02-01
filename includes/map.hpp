/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:05:33 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/01 07:28:29 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include <iostream>
# include "../utils/red_black_tree.hpp"

namespace ft {
    template <class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> > >
    class map
    {
        public:
            typedef Key                                             key_type;
            typedef T                                               mapped_type;
            typedef ft::pair<const key_type, mapped_type>          value_type;
            typedef Compare                                         key_compare;
            typedef Allocator                                       allocator_type;
            typedef typename allocator_type::reference              reference;
            typedef typename allocator_type::const_reference        const_reference;
            typedef typename allocator_type::pointer                pointer;
            typedef typename allocator_type::const_pointer          const_pointer;
            typedef typename allocator_type::size_type              size_type;
            typedef typename allocator_type::difference_type        difference_type;
            typedef typename RBT<key_type, mapped_type>::iterator   iterator;

        private:
            RBT<Key, T>     _tree;
            size_type       _size;
            key_compare     _comp;
            allocator_type  _alloc;
        
        public:
            explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {
                _size = 0;
                _comp = comp;
                _alloc = alloc;
            }

            // template <class InputIterator>
            // map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            // {
            //     while (first != last)
            //     {
            //         _tree.insert(first->first, first->second);
            //         _size++;
            //         first++;
            //     }
            // }

            // map(const map& x)
            // {
            //     this->_size = x._size;
            //     RBT<key, T>::iterator it = x.begin();

            //     for (; it != x.end(); it++)
            //     {
            //         this->_tree.insert(it->first, it->second);
            //         _size++;
            //     }
            // }
            
            // void    clear()
            // {
            //     _tree.clear();
            // }

            // size_type   count(const key_type& k) const
            // {
            //     RBT<key_type, mapped_type>::iterator it;
            //     size_type                            count;

            //     it = _tree.begin();
            //     count = 0;

            //     for (; it != _tree.end(); it++)
            //     {
            //         if (it->first == k)
            //             count++;
            //     }
            //     return count;
            // }

            // bool    empty() const
            // {
            //     return (_size == 0);
            // }

            // iterator    end()
            // {
            //     return iterator(_tree.end());
            // }

            // const_iterator    end() const;
            // {
            //     return iterator(_tree.end());
            // }

            // iterator    find(const key_type& k)
            // {
                
            // }

            // const_iterator    find(const key_type& k) const
            // {
                
            // }

            // size_type   size() const
            // {
            //     return _size;
            // }

            // insert ==> (1) single element
            pair<iterator, bool>    insert(const value_type& val)
            {
                return _tree.insert(val.first, val.second);
            }

            iterator    insert(iterator position, const value_type& val)
            {
                ft::pair<iterator, bool> p;

                p = _tree.insert(val.first, val.second);
                (void)position;
                return p.first;
            }

            template <class InputIterator>
            void    insert(InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    _tree.insert(first->first, first->second);
                    first++;
                }
            }

            void    print()
            {
                _tree.printTree();
            }

            iterator    begin()
            {
                return _tree.begin();
            }

            iterator    end()
            {
                return _tree.end();
            }
    };
}

#endif