/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:43:06 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/07 07:48:09 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "pair.hpp"
#include "iterator_traits.hpp"

template<class _Tp, class _Compare, class _Allocator>
class RBT {
	public:
		typedef _Tp									value_type;
		typedef _Tp*								pointer;
		typedef _Tp&								reference;
		typedef _Compare							value_compare;
		typedef _Allocator							allocator_type;

	private:
		struct Node {
			value_type  _val;
			Node*       _parent;
			Node*       _left;
			Node*       _right;
			Node*       _uncle;
			size_t      _black_height;
			size_t      _height;
			char        _color;

			Node(const value_type& val)
			{
				_val = val;
				_parent = NULL;
				_left = NULL;
				_right = NULL;
				_uncle = NULL;
				_color = 'R';
				_black_height = 1;
			}

			Node()
			{
				_val = value_type();
				_parent = NULL;
				_left = NULL;
				_right = NULL;
				_uncle = NULL;
				_color = 'B';
				_black_height = 1;
			}
		};
	public:
			typedef typename allocator_type::template rebind<Node>::other       allocator_node;
			
		// template <class Category, class Type = Node, class Distance = ptrdiff_t, class Pointer = Type*, class Reference = Type&>
		class iterator {
			private:
				Node*   		curr_node;
			public:
				// typedef Type			iter_value_type;
				// typedef Distance		iter_difference_type;
				// typedef Pointer			iter_pointer;
				// typedef Reference		iter_reference;
				// typedef Category		iter_iterator_category;
				iterator() : curr_node(nullptr)
				{
				}

				~iterator()
				{
				}
				
				iterator(Node* node) : curr_node(node)
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

				bool    operator==(const iterator it)
				{
					return this->curr_node == it.curr_node;
				}

				bool    operator!=(const iterator it)
				{
					return this->curr_node != it.curr_node;
				}

				iterator    operator++()
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
				
				iterator    operator++(int)
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
				
				iterator    operator--()
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
				
				iterator    operator--(int)
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
		class reverse_iterator {
			private:
				iterator _it;
			public:
				reverse_iterator()
				{
				}

				~reverse_iterator()
				{
				}
				
				reverse_iterator(iterator it) : _it(it)
				{
				}

				iterator    operator->()
				{
					return _it;
				}

				value_type      operator*()
				{
					return  this->curr_node->_val;
				}

				// pointer    operator->()
				// {
				// 	return &(operator*());
				// }

				// reference      operator*()
				// {
				// 	return  _it;
				// }

				bool    operator==(const reverse_iterator it)
				{
					return this->_it == it._it;
				}

				bool    operator!=(const reverse_iterator it)
				{
					return !(_it == it._it);
				}

				reverse_iterator    operator++()
				{
					return reverse_iterator(--_it);
				}
				
				reverse_iterator    operator++(int)
				{
					return reverse_iterator(_it--);
				}
				
				reverse_iterator    operator--()
				{
					return reverse_iterator(++_it);
				}
				
				reverse_iterator    operator--(int)
				{
					return reverse_iterator(_it++);
				}
		};
		
		// typedef typename iterator<std::bidirectional_iterator_tag> iterator;
	private:
		Node*					end_node;
		size_t                  _size;
		allocator_type          alloc;
		allocator_node          alloc_node;

	protected:
		
		ft::pair<iterator, bool>    insert_node(const value_type& val)
		{
			Node*  child;
			Node*   find = search(end_node->_left, val);
			if (find)
			{
				return ft::pair<iterator, bool>(iterator(find), false);
			}
			_size++;
			Node*   newNode = alloc_node.allocate(1);
			alloc_node.construct(newNode, Node(val));
			child = insert_node(end_node->_left, newNode);
			end_node->_left = child;
			child->_parent = end_node;
			check_violation(newNode);
			return ft::pair<iterator, bool>(iterator(newNode), true);
		}

		Node*   search(Node* root, const value_type& val) const
		{
			while (root)
			{
				if (value_compare()(val, root->_val))
				{
					root = root->_left;
				}
				else if (value_compare()(root->_val, val))
				{
					root = root->_right;
				}
				else
					break;
			}
			return root;
		}

		void    swap_node(Node*& n1, Node*& n2)
		{
			value_type  tmp_val;

			tmp_val = n1->_val;
			n1->_val = n2->_val;
			n2->_val = tmp_val;
		}

		Node*   insert_node(Node* node, Node* newNode)
		{
			if (node == NULL)
				return newNode;
			if (value_compare()(newNode->_val, node->_val))
			{
				node->_left = insert_node(node->_left, newNode);
				node->_left->_parent = node;
			}
			else if (value_compare()(node->_val, newNode->_val))
			{
				node->_right = insert_node(node->_right, newNode);
				node->_right->_parent = node;
			}
			return node;
		}

		void    right_rotation(Node*& root, Node* node)
		{
			Node* node_left = node->_left;

			node->_left = node_left->_right;

			if (node->_left != NULL)
				node->_left->_parent = node;
				
			node_left->_parent = node->_parent;

			if (node->_parent == NULL)
				root = node_left;

			else if (node == node->_parent->_right)
				node->_parent->_right = node_left;

			else
				node->_parent->_left = node_left;

			node_left->_right = node;
			node->_parent = node_left;
		}

		void left_rotation(Node*& root, Node* node)
		{
			Node *node_right = node->_right;

			node->_right = node_right->_left;

			if (node->_right != NULL)
				node->_right->_parent = node;

			node_right->_parent = node->_parent;

			if (node->_parent == NULL)
				root = node_right;

			else if (node == node->_parent->_left)
				node->_parent->_left = node_right;

			else
				node->_parent->_right = node_right;

			node_right->_left = node;
			node->_parent = node_right;
		}

		void    swap_colors(Node*& n1, Node*& n2)
		{
			char    tmp;

			tmp = n1->_color;
			n1->_color = n2->_color;
			n2->_color = tmp;
		}

		void    check_violation(Node *node)
		{
			Node*	root = end_node->_left;
			Node* parent = nullptr;
			Node* grandpa = nullptr;
			Node* uncle = nullptr;
			
			while (node != root && node->_color == 'R' && node->_parent->_color == 'R')
			{
				parent = node->_parent;
				grandpa = node->_parent->_parent;
				if (parent == grandpa->_left)
				{
					uncle = grandpa->_right;
					if (uncle && uncle->_color == 'R')
					{
						uncle->_color = 'B';
						parent->_color = 'B';
						grandpa->_color = 'R';
						node = grandpa;
					}
					else
					{
						if (node == parent->_left)
						{
							right_rotation(end_node->_left, grandpa);
							swap_colors(grandpa, parent);
						}
						else
						{
							left_rotation(end_node->_left, parent);
							right_rotation(end_node->_left, grandpa);
							swap_colors(grandpa, node);
						}
						node = parent;
					}
				}
				else if (parent == grandpa->_right)
				{
					uncle = grandpa->_left;
					if (uncle && uncle->_color == 'R')
					{
						uncle->_color = 'B';
						parent->_color = 'B';
						grandpa->_color = 'R';
						node = grandpa;
					}
					else
					{
						if (node == parent->_left)
						{
							right_rotation(end_node->_left, parent);
							parent = grandpa->_right;
							node = parent->_right;
						}
						left_rotation(end_node->_left, grandpa);
						swap_colors(grandpa, parent);
						node = parent;
					}
				}
			}
			end_node->_left->_color = 'B';
		}

		Node*   find_successor(Node* node)
		{
			while (node->_left)
			{
				node = node->_left;
			}
			return node;
		}

		Node*   find_predecessor(Node* node)
		{
			while (node->_right)
			{
				node = node->_right;
			}
			return node;
		}

		void    case_black_leaf(Node*& node)
		{
			Node* parent = node->_parent;
			if (node == parent->_left)
			{
				Node* brother = parent->_right;
				swap_colors(parent, brother);
				
			}
		}
		
		Node*   search(const value_type& val) const
		{
			return search(end_node->_left, val);
		}

		char    get_sibling_color(Node* node)
		{
			Node* parent = node->_parent;

			if (parent && node == parent->_left)
			{
				Node* sibling = parent->_right;
				if (sibling)
					return sibling->_color;
			}
			else if (parent && node == parent->_right)
			{
				Node* sibling = parent->_left;
				if (sibling)
					return sibling->_color;
			}
			return 'N';
		}

		Node*   get_sibling(Node* node)
		{
			Node* parent = node->_parent;
			if (parent && node == parent->_left)
				return parent->_right;
			else if (parent && node == parent->_right)
				return parent->_left;
			return nullptr;
		}

		void    remove_node(Node*& node)
		{
			if (node == NULL)
				return ;
			if (!node->_left && !node->_right)
			{
				Node* parent = node->_parent;
				Node* save_node = node;
				
				if (save_node == parent->_left)
					parent->_left = NULL;
				else if (save_node == parent->_right)
					parent->_right = NULL;
				alloc_node.destroy(save_node);
				alloc_node.deallocate(save_node, 1);
				save_node = nullptr;
			}
			else if (!node->_right)
			{
				move_data(node, node->_left);
				check_cases(node->_left);
				remove_node(node->_left);
			}
			else if (!node->_left)
			{
				move_data(node, node->_right);
				check_cases(node->_right);
				remove_node(node->_right);
			}
			else
			{
				Node* succ = find_successor(node->_right);
				move_data(node, succ);
				check_cases(succ);
				remove_node(succ);
			}
		}

		// explain of cases functions

		// case one ==> it's the simple case the color of node is red so there's no violation
		void    case_one(Node*& node)
		{
			(void)node;
			// nothing to do here
		}

		// case two ==> when we are in root nothing to do
		void    case_two(Node*& node)
		{
			(void)node;
			return ;
		}

		// case three ==> sibling black and their childs also black
		void    case_three(Node*& node)
		{
			Node*  parent = node->_parent;
			Node*  sibling = get_sibling(node);

			sibling->_color = 'R';
			if (parent->_color == 'R')
				parent->_color = 'B';
			else
			{
				check_cases(parent);
			}
		}

		// case four ==> when sibling color is red
		void    case_four(Node*& node)
		{
			Node*& parent = node->_parent;
			if (parent && node == parent->_left)
			{
				Node*& sibling = parent->_right;
				swap_colors(sibling, parent);
				left_rotation(end_node->_left, parent);
				check_cases(node);
			}
			else if (parent && node == parent->_right)
			{
				Node*& sibling = parent->_left;
				swap_colors(sibling, parent);
				right_rotation(end_node->_left, parent);
				check_cases(node);
			}
		}

		// case five ==> sibling is black and far nephew is black and near nephew is red
		void    case_five(Node*& node)
		{
			Node*   parent = node->_parent;
			Node*   sibling = get_sibling(node);
			Node*   near_nephew = get_near_nephew(node);

			swap_colors(sibling, near_nephew);
			if (sibling == parent->_left)
				left_rotation(end_node->_left, sibling);
			else
				right_rotation(end_node->_left, sibling);
			case_six(node);
		}

		// case six ==> sibling is black and far nephew is red
		void    case_six(Node*& node)
		{
			Node*   parent = node->_parent;
			Node*   sibling = get_sibling(node);
			Node*   far_nephew = get_far_nephew(node);
			
			swap_colors(parent, sibling);
			if (sibling == parent->_left)
				right_rotation(end_node->_left, parent);
			else
				left_rotation(end_node->_left, parent);
			change_color(far_nephew);
		}

		Node*   get_far_nephew(Node* node)
		{
			Node* parent = node->_parent;
			Node* sibling = get_sibling(node);
			if (node == parent->_left)
			{
				if (sibling && sibling->_right)
					return sibling->_right;
			}
			else if (node == parent->_right)
				if (sibling && sibling->_left)
					return sibling->_left;
			return nullptr;
		}
		bool    far_nephew_is_black(Node* node)
		{
			Node* far_nephew = get_far_nephew(node);
			if (far_nephew && far_nephew->_color == 'B')
				return true;
			return false;
		}

		void    change_color(Node*& node)
		{
			if (node && node->_color == 'R')
				node->_color = 'B';
			else if (node && node->_color == 'B')
				node->_color = 'R';
		}

		Node*  get_near_nephew(Node* node)
		{
			Node* parent = node->_parent;
			Node* sibling = get_sibling(node);

			if (node == parent->_left)
			{
				if (sibling && sibling->_left)
					return sibling->_left;
			}
			else if (node == parent->_right)
			{
				if (sibling && sibling->_right)
					return sibling->_right;
			}
			return nullptr;
		}

		bool    near_newphew_is_red(Node*& node)
		{
			Node* near_nephew = get_near_nephew(node);
			if (near_nephew && near_nephew->_color == 'R')
				return true;
			return false;
		}

		void    check_cases(Node*& node)
		{
			if (node->_color == 'R')
			{
				case_one(node);
			}
			else if (node == end_node->_left)
			{
				case_two(node);
				return ;
			}
			else if (get_sibling_color(node) == 'B' && black_child(get_sibling(node)))
			{
				case_three(node);
			}
			else if (get_sibling_color(node) == 'R')
			{
				case_four(node);
			}
			else if (get_sibling_color(node) == 'B' && far_nephew_is_black(node) && near_newphew_is_red(node))
			{
				case_five(node);
			}
			else if (get_sibling_color(node) == 'B' && !far_nephew_is_black(node))
			{
				case_six(node);
			}
		}

		void    remove(Node*& node, const value_type& val)
		{
			if (!node)
				return ;
			if (value_compare()(val, node->_val))
				remove(node->_left, val);
			else if (value_compare()(node->_val, val))
				remove(node->_right, val);
			else
			{
				if (node->_left == NULL && node->_right == NULL)
				{
					if (node == end_node->_left)
					{
						alloc_node.destroy(node);
						alloc_node.deallocate(node, 1);
						node = nullptr;
					}
					else
					{
						check_cases(node);
						remove_node(node);
					}
				}
				else
				{
					remove_assist(node);
				}
			}
		}

		void    remove_assist(Node*& node)
		{
			if (node->_left == NULL)
			{
				move_data(node, node->_right);
				check_cases(node->_right);
				remove_node(node->_right);
			}
			else if (node->_right == NULL)
			{
				move_data(node, node->_left);
				check_cases(node->_left);
				remove_node(node->_left);
			}
			else
			{
				Node* succ = find_successor(node->_right);
				move_data(node, succ);
				check_cases(succ);
				remove_node(succ);
			}
		}

		void    move_data(Node*&n1, Node* n2)
		{
			n1->_val = n2->_val;
		}

		bool    black_child(Node* node)
		{
			if (node->_left && node->_left->_color == 'R')
				return false;
			if (node->_right && node->_right->_color == 'R')
				return false;
			return true;
		}

		void    printTree(Node* root, int depth)
		{
			if (root == NULL)
				return ;
			printTree(root->_right, depth+1);
			for (int i = 0; i < depth; i++)
				std::cout << "               ";
			if (root->_color == 'R')
				std::cout << "\033[31m";
			else
				std::cout << "\033[30m";
			std::cout << "(" << root->_val.first << ":" << root->_val.second << ")";
			if (root->_parent)
				std::cout << " P is : " << root->_parent->_val.first;
			else
				std::cout << " i am the root";
			std::cout << std::endl << std::endl;
			printTree(root->_left, depth+1);
			std::cout << "\033[0m";
		}

		void    clear(Node*& node)
		{
			if (!node)
				return ;
			clear(node->_left);
			clear(node->_right);
			if (node)
			{
				alloc_node.destroy(node);
				alloc_node.deallocate(node, 1);
				node = NULL;
			}
		}

		Node*  find_the_smallest(Node* node) const
		{
			while (node->_left)
				node = node->_left;
			return node;
		}

		Node*   find_the_biggest(Node* node) const
		{
			while (node->_right)
				node = node->_right;
			return node;
		}
		
	public:

		RBT()
		{
			end_node = alloc_node.allocate(1);
			alloc_node.construct(end_node, Node());
			_size = 0;
		}

		~RBT()
		{
			clear();
			alloc_node.destroy(end_node);
			alloc_node.deallocate(end_node, 1);
			end_node = nullptr;
		}

		ft::pair<iterator, bool>    insert(const value_type& val)
		{
			ft::pair<iterator, bool> p = insert_node(val);
			return p;
		}

		void    remove(const value_type& val)
		{
			remove(end_node->_left, val);
		}

		ft::pair<iterator, bool>    find(const value_type& val) const
		{
			Node* node = search(val);
			if (node)
				return ft::pair<iterator, bool>(iterator(node), true);
			return ft::pair<iterator, bool>(iterator(node), false);
		}

		void    clear()
		{
			if (_size == 0)
				return ;
			clear(end_node->_left);
			_size = 0;
		}

		size_t  size() const
		{
			return _size;
		}

		void    printTree()
		{
			printTree(end_node->_left, 0);
		}

		iterator	upper_bound(const value_type& val)
		{
			Node*	root = end_node->_left;
			Node*	upper = root;

			while (root)
			{
				if (value_compare()(val, root->_val))
				{
					upper = root;
					root = root->_left;
				}
				else
				{
					root = root->_right;
				}
			}
			return (iterator(upper));
		}

		iterator   begin()
		{
			Node*   smallest = find_the_smallest(end_node->_left);
			return iterator(smallest);
		}

		reverse_iterator	rbegin()
		{
			iterator it = end();
			it--;
			return reverse_iterator(it);
		}

		const iterator   begin() const
		{
			Node*   smallest = find_the_smallest(end_node->_left);
			return iterator(smallest);
		}
		
		iterator    end()
		{
			return iterator(end_node);
		}

		reverse_iterator	rend()
		{
			iterator it = begin();
			it--;
			return reverse_iterator(it);
		}
		
		const iterator    end() const
		{
			return iterator(end_node);
		}
};

#endif 



