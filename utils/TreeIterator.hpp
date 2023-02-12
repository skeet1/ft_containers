/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:01:30 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/12 09:30:16 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include <iterator>
#include "iterator_traits.hpp"

namespace ft
{
	template <class T, class Node, class Alloc>
	class TreeIterator
    {
		public:
			typedef T											value_type;
			typedef T*											pointer;
			typedef T&											reference;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename std::bidirectional_iterator_tag	iterator_tag;
		
		private:
			Node*	curr_node;
		public:
			Node*	base() const
			{
				return curr_node;
			}
			TreeIterator() : curr_node(nullptr)
			{
			}

			~TreeIterator()
			{
			}
			
			TreeIterator(Node* node) : curr_node(node)
			{
			}
			
			pointer    operator->()
			{
				return  &(*(this->curr_node->_val));
			}

			reference      operator*()
			{
				return  *(this->curr_node->_val);
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
				if (!curr_node)
					return TreeIterator(curr_node);
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
				return TreeIterator(curr_node);
			}
			
			TreeIterator    operator++(int)
			{
				if (!curr_node)
					return TreeIterator(curr_node);
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
				return TreeIterator(save_curr_node);
			}
			
			TreeIterator    operator--()
			{
				if (!curr_node)
					return TreeIterator(curr_node);
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
				return TreeIterator(curr_node);
			}
			
			TreeIterator    operator--(int)
			{
				if (!curr_node)
					return TreeIterator(curr_node);
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
				return TreeIterator(save_curr_node);
			}
    };
template <class T, class Node, class Alloc>
	class TreeConstIterator
    {
		public:
			typedef T											value_type;
			typedef T*											pointer;
			typedef T&											reference;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::difference_type	differene_type;
			typedef typename std::bidirectional_iterator_tag	iterator_tag;
		
		private:
			Node*	curr_node;
		public:
			Node*	base() const
			{
				return this->curr_node;
			}
			TreeConstIterator() : curr_node(nullptr)
			{
			}

			template <class T1, class Node1, class Diff1> 
			TreeConstIterator(const TreeIterator<T1, Node1, Diff1> &obj): curr_node(obj.base())
			{
			}

			~TreeConstIterator()
			{
			}
			
			TreeConstIterator(Node* node) : curr_node(node)
			{
			}
			
			pointer    operator->() const
			{
				return  &(*(this->curr_node->_val));
			}

			reference      operator*() const
			{
				return  *(this->curr_node->_val);
			}

			bool    operator==(const TreeConstIterator it)
			{
				return this->curr_node == it.curr_node;
			}

			bool    operator!=(const TreeConstIterator it)
			{
				return this->curr_node != it.curr_node;
			}

			TreeConstIterator    operator++()
			{
				if (!curr_node)
					return TreeConstIterator(curr_node);
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
			
			TreeConstIterator    operator++(int)
			{
				if (!curr_node)
					return TreeConstIterator(curr_node);
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
			
			TreeConstIterator    operator--()
			{
				if (!curr_node)
					return TreeConstIterator(curr_node);
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
			
			TreeConstIterator    operator--(int)
			{
				if (!curr_node)
					return TreeConstIterator(curr_node);
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
}

#endif
