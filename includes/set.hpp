/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:30:43 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/05 12:57:29 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include "../utils/red_black_tree.hpp"

namespace ft {
	template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> > 
	class set
	{
		public:
			typedef Key																				key_type;
			typedef key_type																		value_type;
			typedef Compare																			key_compare;
			typedef key_compare																		value_compare;
			typedef Allocator																		allocator_type;
			typedef typename allocator_type::reference												reference;
			typedef typename allocator_type::const_reference										const_reference;
			typedef typename allocator_type::size_type												size_type;
			typedef typename allocator_type::difference_type										difference_type;
			typedef typename allocator_type::pointer												pointer;
			typedef typename allocator_type::const_pointer											const_pointer;
			typedef typename RBT<value_type, value_compare, allocator_type>::iterator				iterator;

		private:
			RBT<value_type, value_compare, allocator_type>	_tree;
			key_compare										_comp;
			allocator_type									_alloc;
		
		public:
			explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
			}

			template <class InputIterator>
			set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
				while (first != last)
				{
					_tree.insert(first);
					first++;
				}
			}

			set(set& x)
			{
				*this = x;
			}

			set&	operator=(set& x)
			{
				this->clear();
				_alloc = x._alloc;
				_comp = x._comp;
				this->insert(x.begin(), x.end());
				return *this;
			}

			void	clear()
			{
				_tree.clear();
			}

			size_type   count(const value_type& k) const
			{
				ft::pair<iterator, bool> p = _tree.find(k);
				if (p.second)
					return 1;
				return 0;
			}

			void	empty()
			{
				return size() = 0;
			}

			size_type	size() const
			{
				return _tree.size();
			}

			size_type	max_size() const
			{
				return _alloc.max_size();
			}

			pair<iterator, bool>	insert(const value_type& val)
			{
				pair<iterator, bool> it = _tree.insert(val);
				return it;
			}

			iterator    insert(iterator position, const value_type& val)
			{
				ft::pair<iterator, bool> p;

				p = _tree.insert(val);
				(void)position;
				return p.first;
			}

			template <class InputIterator>
			void    insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					_tree.insert(*first);
					first++;
				}
			}

			iterator	find(const value_type& val) const
			{
				ft::pair<iterator, bool> p = _tree.find(val);
				if (p.second)
					return p.first;
				return _tree.end();
			}

			void	erase(iterator position)
			{
				_tree.remove(*position);
			}

			size_type	erase(const value_type& val)
			{
				iterator it = find(val);
				if (it == _tree.end())
					return 0;
				erase(it);
				return 1;
			}

			void	erase(iterator first, iterator last)
			{
				ft::stack<key_type> st;
				ft::stack<key_type> to_erase;
				
				while (first != last)
				{
					st.push(*first);
					first++;
				}

				while (!st.empty())
				{
					to_erase.push(st.top());
					st.pop();
				}

				while (!to_erase.empty())
				{
					erase(to_erase.top());
					to_erase.pop();
				}
			}

			key_compare	key_comp() const
			{
				return _comp;
			}

			value_compare	value_compare() const
			{
				return value_compare();
			}

			iterator	lower_bound(const value_type& k)
			{
				iterator it = find(k);
				if (it != _tree.end())
					return it;
				return _tree.upper_bound(k);
			}

			iterator	upper_bound(const value_type& k)
			{
				return _tree.upper_bound(k);
			}

			pair<iterator, iterator>	equal_range(const key_type& k)
			{
				return pair<iterator, iterator>(lower_bound(k), upper_bound(k));
			}

			void    print()
			{
				_tree.printTree();
			}

			iterator    begin()
			{
				return _tree.begin();
			}

			const iterator    begin() const
			{
				return _tree.begin();
			}

			iterator    end()
			{
				return _tree.end();
			}

			const iterator    end() const
			{
				return _tree.end();
			}

			allocator_type  get_allocator() const
			{
				return _alloc;
			}
	};
}

#endif
