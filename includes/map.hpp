/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:05:33 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/12 15:38:44 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef map_HPP
#define map_HPP

# include <iostream>
# include "../utils/red_black_tree.hpp"
# include "../utils/lexicographical_compare.hpp"

namespace ft {
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key                                                                 				key_type;
			typedef T                                                                   				mapped_type;
			typedef ft::pair<const key_type, mapped_type>                               	        	value_type;
			typedef Compare                                                             				key_compare;
			typedef Allocator                                                           				allocator_type;
			typedef typename allocator_type::reference                                  				reference;
			typedef typename allocator_type::const_reference                            				const_reference;
			typedef typename allocator_type::pointer                                    				pointer;
			typedef typename allocator_type::const_pointer                              				const_pointer;
			typedef typename allocator_type::size_type                                  				size_type;
			typedef typename allocator_type::difference_type                            				difference_type;

			class value_compare
			{
				friend class map;

				public:
					Compare comp;
					value_compare(){};
					value_compare (Compare c) : comp(c) {}
				
				public:
					bool    operator()(const value_type& x, const value_type& y)
					{
						return comp(x.first, y.first);
					}
			};
			typedef typename RBT<value_type, value_compare, allocator_type>::iterator					iterator;
			typedef typename RBT<value_type, value_compare, allocator_type>::const_iterator				const_iterator;
			typedef typename RBT<value_type, value_compare, allocator_type>::reverse_iterator			reverse_iterator;
			typedef typename RBT<value_type, value_compare, allocator_type>::const_reverse_iterator		const_reverse_iterator;
		private:
			RBT<value_type, value_compare, allocator_type>			_tree;
			key_compare												_comp;
			allocator_type											_alloc;

		public:
			map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
			}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
				while (first != last)
				{
					_tree.insert(ft::pair<key_type, mapped_type>(first->first, first->second));
					first++;
				}
			}

			map(const map& x)
			{
				this->_alloc = x._alloc;
				this->_comp = x._comp;
				if (x.size())
					this->insert(x.begin(), x.end());
			}

			map&    operator=(const map& x)
			{
				this->clear();
				this->_alloc = x._alloc;
				this->_comp = x._comp;
				if (x.size())
					this->insert(x.begin(), x.end());
				return *this;
			}
			
			void    clear()
			{
				_tree.clear();
			}

			size_type   count(const key_type& k) const
			{
				ft::pair<iterator, bool> p = _tree.find(ft::pair<key_type, mapped_type>(k, mapped_type()));
				if (p.second)
					return 1;
				return 0;
			}

			bool    empty()
			{
				return size() == 0;
			}

			size_type   size() const
			{
				return _tree.size();
			}

			size_type   max_size() const
			{
				return _alloc.max_size();
			}

			pair<iterator, bool>    insert(const value_type& val)
			{
				
				pair<iterator, bool> it = _tree.insert((reference)val);
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
					_tree.insert(ft::pair<key_type, mapped_type>(first->first, first->second));
					first++;
				}
			}

			iterator    find(const key_type& k)
			{
				ft::pair<key_type, mapped_type> val(k, mapped_type());
				ft::pair<iterator, bool> p = _tree.find(val);
				if (p.second)
					return p.first;
				return _tree.end();
			}

			mapped_type&    operator[](const key_type& k)
			{
				pair<key_type, mapped_type> val;
				
				val.first = k;
				val.second = mapped_type();
				pair<iterator, bool> p = insert(val);
				iterator it = p.first;
				return it->second;
			}

			void    erase(iterator  position)
			{
				_tree.remove(ft::make_pair(position->first, position->second));
			}

			size_type   erase(const key_type& k)
			{
				iterator it = find(k);
				if (it == _tree.end())
					return 0;
				erase(it);
				return 1;
			}

			void    erase(iterator first, iterator last)
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
				return value_compare();
			}

			iterator	lower_bound(const key_type& k)
			{
				iterator it = find(k);
				ft::pair<key_type, mapped_type> p(k, mapped_type());
				if (it != _tree.end())
					return it;
				return _tree.upper_bound(p);
			}

			iterator	upper_bound(const key_type& k)
			{
				return _tree.upper_bound(ft::pair<key_type, mapped_type>(k, mapped_type()));
			}

			pair<iterator, iterator>	equal_range(const key_type& k)
			{
				return pair<iterator, iterator>(lower_bound(k), upper_bound(k));
			}

			const_iterator	lower_bound(const key_type& k) const
			{
				iterator it = find(k);
				ft::pair<key_type, mapped_type> p(k, mapped_type());
				if (it != _tree.end())
					return it;
				return _tree.upper_bound(p);
			}

			const_iterator	upper_bound(const key_type& k) const
			{
				return _tree.upper_bound(ft::pair<key_type, mapped_type>(k, mapped_type()));
			}

			pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
			{
				return pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
			}

			void	swap(map& x)
			{
				map	_tmp_tree(begin(), end());
				this->clear();
				this->insert(x.begin(), x.end());
				x.clear();
				x.insert(_tmp_tree.begin(), _tmp_tree.end());
				_tmp_tree.clear();
			}

			iterator    begin()
			{
				return _tree.begin();
			}

			const_iterator    begin() const
			{
				return _tree.begin();
			}

			reverse_iterator	rbegin()
			{
				return _tree.rbegin();
			}

			const_reverse_iterator	rbegin() const
			{
				return _tree.rbegin();
			}

			iterator    end()
			{
				return _tree.end();
			}

			const_iterator    end() const
			{
				return _tree.end();
			}

			reverse_iterator	rend()
			{
				return _tree.rend();
			}

			const_reverse_iterator	rend() const
			{
				return _tree.rend();
			}

			allocator_type  get_allocator() const
			{
				return _alloc;
			}
			
			template <class Key1, class T1, class Compare1, class Alloc1>
			friend	bool operator==(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs);

			template <class Key1, class T1, class Compare1, class Alloc1>
			friend	bool operator!=(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs);

			template <class Key1, class T1, class Compare1, class Alloc1>
			friend	bool operator<(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs);

			template <class Key1, class T1, class Compare1, class Alloc1>
			friend	bool operator<=(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs);
			
			template <class Key1, class T1, class Compare1, class Alloc1>
			friend	bool operator>(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs);

			template <class Key1, class T1, class Compare1, class Alloc1>
			friend	bool operator>=(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs);

			template <class Key1, class T1, class Compare1, class Alloc1>
  			friend void swap (map<Key1, T1, Compare1, Alloc1>& x, map<Key1, T1, Compare1, Alloc1>& y);
	};

	template <class Key1, class T1, class Compare1, class Alloc1>
	bool operator==(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key1, class T1, class Compare1, class Alloc1>
	bool operator!=(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key1, class T1, class Compare1, class Alloc1>
	bool operator<(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key1, class T1, class Compare1, class Alloc1>
	bool operator<=(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs)
	{
		return ((lhs == rhs) || (lhs < rhs));
	}

	template <class Key1, class T1, class Compare1, class Alloc1>
	bool operator>(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs)
	{
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template <class Key1, class T1, class Compare1, class Alloc1>
	bool operator>=(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs)
	{
		return ((lhs == rhs) || (lhs > rhs));
	}

	template <class Key1, class T1, class Compare1, class Alloc1>
	void swap (map<Key1, T1, Compare1, Alloc1>& x, map<Key1, T1, Compare1, Alloc1>& y)
	{
		x.swap(y);
	}
}

#endif