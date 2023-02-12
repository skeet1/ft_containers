/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:30:43 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/12 13:42:45 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include "../utils/red_black_tree.hpp"
#include "../utils/lexicographical_compare.hpp"

namespace ft {
	template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> > 
	class set
	{
		public:
			typedef Key																					key_type;
			typedef key_type																			value_type;
			typedef Compare																				key_compare;
			typedef key_compare																			value_compare;
			typedef Allocator																			allocator_type;
			typedef typename allocator_type::reference													reference;
			typedef typename allocator_type::const_reference											const_reference;
			typedef typename allocator_type::size_type													size_type;
			typedef typename allocator_type::difference_type											difference_type;
			typedef typename allocator_type::pointer													pointer;
			typedef typename allocator_type::const_pointer												const_pointer;
			typedef typename RBT<value_type, value_compare, allocator_type>::iterator					iterator;
			typedef typename RBT<value_type, value_compare, allocator_type>::const_iterator				const_iterator;
			typedef typename RBT<value_type, value_compare, allocator_type>::reverse_iterator			reverse_iterator;
			typedef typename RBT<value_type, value_compare, allocator_type>::const_reverse_iterator		const_reverse_iterator;

		private:
			RBT<value_type, value_compare, allocator_type>	_tree;
			key_compare										_comp;
			allocator_type									_alloc;
		
		public:
			explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _comp(comp), _alloc(alloc)
			{
			}

			template <class InputIterator>
			set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc)
			{
				while (first != last)
				{
					this->insert(*first);
					first++;
				}
			}

			set(const set& x)
			{
				this->_alloc = x._alloc;
				this->_comp = x._comp;
				if (x.size())
					insert(x.begin(), x.end());
			}

			set&	operator=(const set& x)
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

			bool	empty()
			{
				return size() == 0;
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

			iterator	find(const value_type& val)
			{
				ft::pair<iterator, bool> p = _tree.find(val);
				if (p.second)
					return p.first;
				return end();
			}

			iterator	find(const value_type& val) const
			{
				ft::pair<iterator, bool> p = _tree.find(val);
				if (p.second)
					return p.first;
				return end();
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
				iterator save_first = first;
				difference_type diff = 0;
				while (save_first != last)
				{
					diff++;
					save_first++;
				}
				while (first != last)
				{
					save_first = first;
					save_first++;
					erase(first);
					first = save_first;
				}
			}

			key_compare	key_comp() const
			{
				return _comp;
			}

			value_compare	value_comp() const
			{
				return _comp;
			}

			iterator	lower_bound(const value_type& k)
			{
				iterator it = find(k);
				if (it != _tree.end())
					return it;
				return _tree.upper_bound(k);
			}

			const_iterator	lower_bound(const value_type& k) const
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

			const_iterator	upper_bound(const value_type& k) const
			{
				return _tree.upper_bound(k);
			}

			pair<iterator, iterator>	equal_range(const key_type& k)
			{
				return pair<iterator, iterator>(lower_bound(k), upper_bound(k));
			}

			pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
			{
				return pair<iterator, iterator>(lower_bound(k), upper_bound(k));
			}

			void	swap(set& x)
			{
				set	_tmp_tree(begin(), end());
				this->clear();
				this->insert(x.begin(), x.end());
				x.clear();
				x.insert(_tmp_tree.begin(), _tmp_tree.end());
				_tmp_tree.clear();
			}

			void    print()
			{
				_tree.printTree();
			}

			iterator    begin()
			{
				return _tree.begin();
			}

			reverse_iterator	rbegin()
			{
				return _tree.rbegin();
			}

			const_iterator    begin() const
			{
				return _tree.begin();
			}

			iterator    end()
			{
				return _tree.end();
			}

			reverse_iterator	rend()
			{
				return _tree.rend();
			}

			const_iterator    end() const
			{
				return _tree.end();
			}

			allocator_type  get_allocator() const
			{
				return _alloc;
			}
			template <class Key1, class Compare1, class Alloc1>
			friend	bool operator==(const set<Key1, Compare1, Alloc1>& lhs, const set<Key1, Compare1, Alloc1>& rhs);

			template <class Key1, class Compare1, class Alloc1>
			friend	bool operator!=(const set<Key1, Compare1, Alloc1>& lhs, const set<Key1, Compare1, Alloc1>& rhs);

			template <class Key1, class Compare1, class Alloc1>
			friend	bool operator<(const set<Key1, Compare1, Alloc1>& lhs, const set<Key1, Compare1, Alloc1>& rhs);

			template <class Key1, class Compare1, class Alloc1>
			friend	bool operator<=(const set<Key1, Compare1, Alloc1>& lhs, const set<Key1, Compare1, Alloc1>& rhs);
			
			template <class Key1, class Compare1, class Alloc1>
			friend	bool operator>(const set<Key1, Compare1, Alloc1>& lhs, const set<Key1, Compare1, Alloc1>& rhs);

			template <class Key1, class Compare1, class Alloc1>
			friend	bool operator>=(const set<Key1, Compare1, Alloc1>& lhs, const set<Key1, Compare1, Alloc1>& rhs);

			template <class T1, class Compare1, class Alloc1>
			friend void swap (set<T1, Compare1, Alloc1>& x, set<T1, Compare1, Alloc1>& y);
	};

	template <class Key1, class Compare1, class Alloc1>
	bool operator==(const set<Key1, Compare1, Alloc1>& lhs, const set<Key1, Compare1, Alloc1>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key1, class Compare1, class Alloc1>
	bool operator!=(const set<Key1, Compare1, Alloc1>& lhs, const set<Key1, Compare1, Alloc1>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key1, class Compare1, class Alloc1>
	bool operator<(const set<Key1, Compare1, Alloc1>& lhs, const set<Key1, Compare1, Alloc1>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key1, class Compare1, class Alloc1>
	bool operator<=(const set<Key1, Compare1, Alloc1>& lhs, const set<Key1, Compare1, Alloc1>& rhs)
	{
		return ((lhs == rhs) || (lhs < rhs));
	}

	template <class Key1, class Compare1, class Alloc1>
	bool operator>(const set<Key1, Compare1, Alloc1>& lhs, const set<Key1, Compare1, Alloc1>& rhs)
	{
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template <class Key1, class Compare1, class Alloc1>
	bool operator>=(const set<Key1, Compare1, Alloc1>& lhs, const set<Key1, Compare1, Alloc1>& rhs)
	{
		return ((lhs == rhs) || (lhs > rhs));
	}

	template <class T1, class Compare1, class Alloc1>
	void swap (set<T1, Compare1, Alloc1>& x, set<T1, Compare1, Alloc1>& y)
	{
		x.swap(y);
	}
}

#endif
