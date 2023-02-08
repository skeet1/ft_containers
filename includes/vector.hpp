/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:44:52 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/08 17:42:08 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef vector_HPP
#define vector_HPP

#include "all_headers.hpp"
#include "../utils/iterator_traits.hpp"
#include "vector_iter.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T> > 
	class vector {
		public:
			typedef T 																					value_type;
			typedef Allocator																			allocator_type;
			typedef typename allocator_type::reference													reference;
			typedef typename allocator_type::const_reference											const_reference;
			typedef typename allocator_type::size_type													size_type;
			typedef typename allocator_type::difference_type											difference_type;
			typedef typename allocator_type::pointer													pointer;
			typedef typename allocator_type::const_pointer												const_pointer;
			typedef typename ft::vector_Iter<std::random_access_iterator_tag, T>						iterator;
			typedef typename ft::vector_Rev_Iter<std::random_access_iterator_tag, T>					reverse_iterator;

		private:
			size_t				_size;
			size_t				_capacity;
			value_type*			_arr;
			allocator_type		_alloc;
			
		public:
			
			iterator begin()
			{
				return _arr;
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(_arr + (_size - 1));
			}
			
			const iterator begin() const
			{
				return _arr;
			}
			
			iterator end()
			{
				return _arr + _size;
			}

			reverse_iterator rend()
			{
				return reverse_iterator(_arr - 1);
			}
			
			const iterator end() const
			{
				return _arr + _size;
			}
			// **************************************************************** //
			// ------------------------- Constructors ------------------------- //
			// **************************************************************** //
			
			// default
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				_size = 0;
				_capacity = 0;
				_alloc = alloc;
				_arr = nullptr;
			}

			// fill
			explicit vector (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type())
			{
				_size = n;
				_capacity = n;
				_alloc = alloc;
				_arr = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(_arr + i);
				for (size_type i = 0; i < _size; i++)
					_arr[i] = val;
			}

			// range
			template <class InputIterator>
				vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 0)
			{
				InputIterator beg = first;
				size_t size = 0;
				while (beg != last)
				{
					beg++;
					size++;
				}
				_size = size;
				_capacity = size;
				_alloc = alloc;
				_arr = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(_arr + i);
				size_type i = 0;
				while (first != last)
				{
					_arr[i++] = *first;
					first++;
				}
			}

			// copy
			vector(const vector&x)
			{
				_size = x._size;
				_capacity = x._size;
				_alloc = x._alloc;
				_arr = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(_arr + i);
				for (size_t i = 0; i < _size; i++)
				{
					_arr[i] = x._arr[i];
				}
			}
			
			// copy assignment
			vector& operator=(const vector& x)
			{
				_alloc.destroy(_arr);
				_alloc.deallocate(_arr, _capacity);
				this->_alloc = x._alloc;
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_arr = this->_alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(this->_arr + i);
				for (size_type i = 0; i < _size; i++)
				{
					this->_arr[i] = x._arr[i];
				}
				return *this;
			}		

			// **************************************************************** //
			// --------------------------- DESTRUCTOR ------------------------- //
			// **************************************************************** //
			
			~vector(){
				if (_arr)
				{
					_alloc.destroy(_arr);
					_alloc.deallocate(_arr, _capacity);
				}
			}
			
			// **************************************************************** //
			// -------------------------- CAPACITY ---------------------------- //
			// **************************************************************** //
			
			size_type	size() const
			{
				return _size;
			}
			
			size_type max_size() const
			{
				return powl(2, 64)/sizeof(T) - 1;
			}

			void resize (size_type n, value_type val = value_type())
			{
				value_type*	tmp;
				size_t save_capacity = _capacity;
				
				if (n < _size)
				{
					tmp = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _capacity; i++)
						_alloc.construct(tmp + i);
					for (size_type i = 0; i < n; i++)
						tmp[i] = _arr[i];
				}
				else
				{
					size_type	i;
					if (n > _capacity)
						_capacity *= 2;
					if (n > _capacity)
						_capacity = n;
					tmp = _alloc.allocate(_capacity);
					for (i = 0; i < _capacity; i++)
						_alloc.construct(tmp + i);
					for (i = 0; i < _size; i++)
					{
						tmp[i] = _arr[i];
					}
					for (; i < _capacity; i++)
						tmp[i] = val;
				}
				_alloc.destroy(_arr);
				_alloc.deallocate(_arr, save_capacity);
				this->_arr = tmp;
				_size = n;
				// value_type *	temp;
				// temp = _alloc.allocate(n);
				// for (size_type i = 0; i < n; i++)
				// 	_alloc.construct(temp + i);
				// for (size_type i = 0; i < n; i++)
				// {
				// 	temp[i] = val;
				// }
				// for (size_type i = 0; i < n && i < _size; i++)
				// {
				// 	temp[i] = _arr[i];
				// }
				// for (size_type i = 0; i < _size; i++)
				// {
				// 	_alloc.destroy(_arr + i);
				// }
				// _alloc.deallocate(_arr, _size);
				// _arr = temp;
				// _size = n;
			}

			size_type	capacity() const 
			{
				return _capacity;
			}
			
			bool 	empty() const
			{
				return (_size == 0);
			}

			void    reserve(size_type newCapacity)
			{
				if (_capacity < newCapacity)
				{
					_capacity = newCapacity;
				}
			}
			
			// **************************************************************** //
			// ------------------------- ELEMENT ACCES ------------------------ //
			// **************************************************************** //
			
			reference operator[](size_type n)
			{
				return _arr[n];
			}
			
			const_reference operator[](size_type n) const
			{
				return _arr[n];
			}

			reference at(size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("vector");
				return _arr[n];
			}
			
			const_reference at(size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("vector");
				return _arr[n];
			}
			
			reference	front()
			{
				return _arr[0];
			}
			
			const_reference	front() const
			{
				return _arr[0];
			}
			
			reference back()
			{
				return _arr[_size - 1];
			}
			
			const_reference back() const
			{
				return _arr[_size - 1];
			}
			
			// **************************************************************** //
			// --------------------------- MODIFIERS -------------------------- //
			// **************************************************************** //
			
			// assign: range
			void assign (size_type n, const value_type& val)
			{
				if (n < _capacity)
				{
					for (size_t i = 0; i < n; i++)
						_arr[i] = val;
				}
				else
				{
					value_type	*tmp;
					_alloc.destroy(_arr);
					_alloc.deallocate(_arr, _capacity);
					_capacity *= 2;
					if (n > _capacity)
						_capacity = n;
					tmp = _alloc.allocate(_capacity);
					for (size_t i = 0; i < _capacity; i++)
						_alloc.construct(tmp+i);
					for (size_t i = 0; i < _capacity; i++)
						tmp[i] = val;
					_arr = tmp;
				}
				_size = n;
			}
			
			// assign: fill
			template <class InputIterator>
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type
			assign (InputIterator first, InputIterator last)
			{
				InputIterator beg = first;
				size_type size = 0;
				while (beg != last)
				{
					beg++;
					size++;
				}
				if (size < _capacity)
				{
					for (size_type i = 0; i < size; i++)
					{
						_arr[i] = *first;
						first++;
					}
				}
				else
				{
					value_type	*tmp;
					_alloc.destroy(_arr);
					_alloc.deallocate(_arr, _capacity);
					_capacity *= 2;
					if (size > _capacity)
						_capacity = size;
					tmp = _alloc.allocate(_capacity);
					for (size_t i = 0; i < _capacity; i++)
						_alloc.construct(tmp + i);
					for (size_t i = 0; first != last; first++)
					{
						tmp[i] = *first;
						i++;
					}
					_arr = tmp;
				}
				_size = size;
			}

			void	push_back(const value_type& val)
			{
				value_type *	temp;
				if (_capacity == _size)
				{
					_capacity *= 2;
					if (_capacity == 0) _capacity = 1;
					temp = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _capacity; i++)
						_alloc.construct(temp + i);
					for (size_type i = 0; i < _size; i++)
					{
						temp[i] = _arr[i];
					}
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.destroy(_arr + i);
					}
					_alloc.deallocate(_arr, _size);
					_arr = temp;
				}
				_arr[_size] = val;
				_size++;
			}

			void	pop_back()
			{
				_size--;
			}

			//insert 1: single element
			iterator insert (iterator position, const value_type& val)
			{
				value_type *	temp;
				size_type i = 0;
				iterator beg = this->begin();
				size_type ret = 0;

				if (_size == _capacity)
					_capacity *= 2;
				temp = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(temp + i);
				while (i < _size)
				{
					if (beg == position)
						break;
					temp[i] = _arr[i];
					i++;
					beg++;
				}
				ret = i;
				temp[i++] = val;
				while (i < _size + 1)
				{
					temp[i] = _arr[i-1];
					i++;
				}
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.destroy(_arr + i);
				}
				_alloc.deallocate(_arr, _size);
				_arr = temp;
				_size++;
				return _arr + ret;
			}
			
			// insert 2: insert N elements
			void insert (iterator position, size_type n, const value_type& val)
			{
				value_type * temp;
				size_type i = 0;
				iterator beg = this->begin();
				if (_capacity < _size + n)
				{
					_capacity *= 2;
					if (_capacity < _size + n)
						_capacity = _size + n;
				}
				temp = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(temp + i);
				while (i < _size)
				{
					if (beg == position)
						break;
					temp[i] = _arr[i];
					i++;
					beg++;
				}
				for (size_type j = 0; j < n; j++)
					temp[i++] = val;
				while (i < _size + n)
				{
					temp[i] = _arr[i-n];
					i++;
				}
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.destroy(_arr + i);
				}
				_alloc.deallocate(_arr, _size);
				_arr = temp;
				_size += n;
			}
			
			// insert 3: insert range of iterators
			template <class InputIterator>
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type
			insert (iterator position, InputIterator first, InputIterator last)
			{
				value_type*			temp;
				size_type 			i = 0;
				iterator 			beg = this->begin();
				difference_type		n = last - first;
				if (_capacity < _size + n )
				{
					_capacity *= 2;
					if (_capacity < _size + n)
						_capacity = _size + n;
				}
				temp = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(temp + i);
				i = 0;
				while (i < _size)
				{
					if (beg == position)
						break;
					temp[i] = _arr[i];
					i++;
					beg++;
				}
				while (first != last)
				{
					temp[i++] = *first;
					first++;
				}
				while (i < _size + n)
				{
					temp[i] = _arr[i-n];
					i++;
				}
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.destroy(_arr + i);
				}
				_alloc.deallocate(_arr, _size);
				_arr = temp;
				_size += n;
			}

			// erase one position
			iterator erase(iterator pos)
			{
				iterator it = this->begin();
				iterator ret;
				size_type i = 0;

				while (it != this->end())
				{
					if (it == pos)
					{
						ret = it;
						while (1)
						{
							if (it == this->end())
								break;
							_arr[i] = _arr[i+1];
							it++;
							i++;
						}
						break;
					}
					it++;
					i++;
				}
				_size--;
				return ret;
			}

			// erase range
			iterator erase(iterator first, iterator last)
			{
				iterator ret = first;
				iterator beg = first;
				while (beg != last)
				{
					erase(first);
					beg++;
				}
				return ret;
			}

			void	clear()
			{
				_size = 0;
			}
			
			// **************************************************************** //
			// --------------------------- ALLOCATOR -------------------------- //
			// **************************************************************** //
			
			// get allocator
			allocator_type get_allocator() const
			{
				return _alloc;
			}
			
			//swap
			void	swap(vector &x)
			{
				value_type*		tmp;
				size_type		tmp_size;
				size_type		tmp_capacity;
				allocator_type	tmp_alloc;

				tmp = x._arr;
				tmp_size = x._size;
				tmp_capacity = x._capacity;
				tmp_alloc = x._alloc;

				x._arr = _arr;
				x._size = _size;
				x._capacity = _capacity;
				x._alloc = _alloc;
				
				_arr = tmp;
				_size = tmp_size;
				_capacity = tmp_capacity;
				_alloc = tmp_alloc;

				// std::swap(_arr, x._arr);
				// std::swap(_capacity, x._capacity);
				// std::swap(_arr, x._arr);
				// std::swap(_alloc, x._alloc);
			}
			
			template <class T1, class Alloc>
			friend bool operator==(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs);
			
			template <class T1, class Alloc>
			friend bool operator!=(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs);
			
			template <class T1, class Alloc>
			friend bool operator<(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs);
			
			template <class T1, class Alloc>
			friend bool operator<=(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs);
			
			template <class T1, class Alloc>
			friend bool operator>(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs);
			
			template <class T1, class Alloc>
			friend bool operator>=(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs);
			
	};

	template <class T1, class Alloc>
	bool operator==(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size() && lhs.capacity() == rhs.capacity() && lhs.get_allocator() == lhs.get_allocator())
		{
			for (size_t i = 0; i < lhs._size; i++)
			{
				if (lhs._arr[i] != rhs._arr[i])
					return false;
			}
			return true;
		}
		return false;
	}

	template <class T1, class Alloc>
	bool operator!=(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T1, class Alloc>
	bool operator<(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs)
	{
		if (lhs.size() < rhs.size())
			return true;
		if (lhs.size() == rhs.size())
		{
			for (size_t i = 0; i < lhs.size(); i++)
			{
				if (lhs._arr[i] >= rhs._arr[i])
					return false;
			}
			return true;
		}
		return false;
	}

	template <class T1, class Alloc>
	bool operator<=(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs)
	{
		if (lhs.size() < rhs.size())
			return true;
		if (lhs.size() == rhs.size())
		{
			for (size_t i = 0; i < lhs.size(); i++)
			{
				if (lhs._arr[i] > rhs._arr[i])
					return false;
			}
			return true;
		}
		return false;
	}

	template <class T1, class Alloc>
	bool operator>(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs)
	{
		if (lhs.size() > rhs.size())
			return true;
		if (lhs.size() == rhs.size())
		{
			for (size_t i = 0; i < lhs.size(); i++)
			{
				if (lhs._arr[i] <= rhs._arr[i])
					return false;
			}
			return true;
		}
		return false;
	}

	template <class T1, class Alloc>
	bool operator>=(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs)
	{
		if (lhs.size() > rhs.size())
			return true;
		if (lhs.size() == rhs.size())
		{
			for (size_t i = 0; i < lhs.size(); i++)
			{
				if (lhs._arr[i] < rhs._arr[i])
					return false;
			}
			return true;
		}
		return false;
	}

}

#endif