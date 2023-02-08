/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:01:30 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/08 18:28:56 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include <iterator>
#include "iterator_traits.hpp"

namespace ft
{
	template <class Category,			// iterator::iterator_category
	class T,							// iterator::value_type
	class Node,							// Node_type
	class Distance = ptrdiff_t,			// iterator::difference_type
	class Pointer = T*,					// iterator::pointer
	class Reference = T&				// iterator::reference
	>
	class TreeIterator : public ft::iterator<std::bidirectional_iterator_tag, T>
    {
		public:
			typedef typename ft::iterator_traits<iterator<Category, T> >::value_type				value_type;
			typedef typename ft::iterator_traits<iterator<Category, T> >::difference_type			difference_type;
			typedef typename ft::iterator_traits<iterator<Category, T> >::pointer					pointer;
			typedef typename ft::iterator_traits<iterator<Category, T> >::reference					reference;
			typedef typename ft::iterator_traits<iterator<Category, T> >::iterator_category			iterator_tag;
		
		private:
			Node*	curr_node;
		public:
			TreeIterator() : curr_node(nullptr)
			{
			}

			~TreeIterator()
			{
			}
			
			TreeIterator(Node* node) : curr_node(node)
			{
			}

			value_type*    operator->()
			{
				return &curr_node->_val;
			}

			value_type      operator*()
			{
				return  this->curr_node->_val;
			}

			bool    operator==(const TreeIterator it)
			{
				return this->curr_node == it.curr_node;
			}

			bool    operator!=(const TreeIterator it)
			{
				return this->curr_node != it.curr_node;
			}

			TreeIterator    operator++()
			{
				Node*   succ = curr_node->_right;

				while (succ && succ->_left)
					succ = succ->_left;
				if (succ)
					curr_node = succ;
				else
				{
					while (curr_node && curr_node->_parent && curr_node == curr_node->_parent->_right)
						curr_node = curr_node->_parent;
					curr_node = curr_node->_parent;
				}
				return curr_node;
			}
			
			TreeIterator    operator++(int)
			{
				Node*   save_curr_node = curr_node;
				Node*   succ = curr_node->_right;

				while (succ && succ->_left)
					succ = succ->_left;
				if (succ)
					curr_node = succ;
				else
				{
					while (curr_node && curr_node->_parent && curr_node == curr_node->_parent->_right)
						curr_node = curr_node->_parent;
					curr_node = curr_node->_parent;
				}
				return save_curr_node;
			}
			
			TreeIterator    operator--()
			{
				Node*   predec = curr_node->_left;
				
				while (predec && predec->_right)
					predec = predec->_right;
				if (predec)
					curr_node = predec;
				else
				{
					while (curr_node && curr_node->_parent && curr_node == curr_node->_parent->_left)
						curr_node = curr_node->_parent;
					curr_node = curr_node->_parent;
				}
				return curr_node;
			}
			
			TreeIterator    operator--(int)
			{
				Node*   save_curr_node = curr_node;
				Node*   predec = curr_node->_left;
				
				while (predec && predec->_right)
					predec = predec->_right;
				if (predec)
					curr_node = predec;
				else
				{
					while (curr_node && curr_node->_parent && curr_node == curr_node->_parent->_left)
						curr_node = curr_node->_parent;
					curr_node = curr_node->_parent;
				}
				return save_curr_node;
			}
    };
	template <class Category,
	class T,
	class Node,
	class Distance = ptrdiff_t,
	class Pointer = T*,
	class Reference = T&
	>
	class TreeRevIterator {
		public:
			typedef typename ft::iterator_traits<iterator<Category, T> >::value_type				value_type;
			typedef typename ft::iterator_traits<iterator<Category, T> >::difference_type			difference_type;
			typedef typename ft::iterator_traits<iterator<Category, T> >::pointer					pointer;
			typedef typename ft::iterator_traits<iterator<Category, T> >::reference					reference;
			typedef typename ft::iterator_traits<iterator<Category, T> >::iterator_category			iterator_tag;

		private:
			TreeIterator<Category, T, Node> _it;

		public:
			TreeRevIterator(): _it()
			{
			}

			TreeRevIterator(TreeIterator<Category, T, Node> it) : _it(it)
			{
			}
			
			~TreeRevIterator()
			{
			}

			TreeIterator<Category, T, Node>    operator->()
			{
				return _it;
			}

			value_type      operator*()
			{
				return  this->curr_node->_val;
			}

			bool    operator==(const TreeRevIterator it)
			{
				return this->_it == it._it;
			}

			bool    operator!=(const TreeRevIterator it)
			{
				return !(_it == it._it);
			}

			TreeRevIterator    operator++()
			{
				return TreeRevIterator(--_it);
			}
			
			TreeRevIterator    operator++(int)
			{
				return TreeRevIterator(_it--);
			}
			
			TreeRevIterator    operator--()
			{
				return TreeRevIterator(++_it);
			}
			
			TreeRevIterator    operator--(int)
			{
				return TreeRevIterator(_it++);
			}
	};
}

#endif
