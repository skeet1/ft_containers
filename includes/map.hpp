/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:05:33 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/09 13:07:34 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include <iostream>
# include "../utils/red_black_tree.hpp"

#define RED     0
#define BLACK   1
#define LEFT    3
#define RIGHT   4

// namespace ft {
//     template <class Key,
//     class T,
//     class Compare = std::less<Key>,
//     class Allocator = std::allocator<std::pair<const Key, T> >
//     > class map
//     {
//         public:
//             // types:
//             typedef Key                                      key_type;
//             typedef T                                        mapped_type;
//             typedef std::pair<const key_type, mapped_type>        value_type;
//             typedef Compare                                  key_compare;
//             typedef Allocator                                allocator_type;
//             typedef typename allocator_type::reference       reference;
//             typedef typename allocator_type::const_reference const_reference;
//             typedef typename allocator_type::pointer         pointer;
//             typedef typename allocator_type::const_pointer   const_pointer;
//             typedef typename allocator_type::size_type       size_type;
//             typedef typename allocator_type::difference_type difference_type;

//             // typedef implementation-defined                   iterator;
//             // typedef implementation-defined                   const_iterator;
//             // typedef std::reverse_iterator<iterator>          reverse_iterator;
//             // typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
            
//             map()
//             {
//                 RBT _tree;
//             }
            
//             map(Key key, T value)
//             {
//                 RBT _tree(T, value);
//             }

//             void    insert(Key key, T value)
//             {
//                 _tree.
//             }
//         private:
//             RBT _tree;
//     };
// }

#endif