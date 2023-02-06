/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:44:52 by mkarim            #+#    #+#             */
/*   Updated: 2023/02/06 09:00:01 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef vector_HPP
#define vector_HPP

#include "all_headers.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T> > 
	class vector {
		public:
			typedef T 											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

		private:
			size_t				_size;
			size_t				_capacity;
			value_type*			_arr;
			allocator_type		_alloc;
			
		public:
			// **************************************************************** //
			// -------------------------- ITERATORS --------------------------- //
			// **************************************************************** //

		// template <class Category = std::random_access_iterator_tag , class T1 = T, class Distance = ptrdiff_t, class Pointer = T1*, class Reference = T1&>
			class iterator {
				public:
					// typedef T1			value_type;
					// typedef Distance	difference_type;
					// typedef Pointer		pointer;
					// typedef Reference	reference;
					// typedef Category	iterator_category;
				private:
					pointer _ptr;
				public:
					iterator()
					{
						_ptr = NULL;
					}
					iterator(value_type* ptr)
					{
						_ptr = ptr;
					}

					iterator operator++()
					{
						++_ptr;
						return *this;
					}

					iterator operator++(int)
					{
						_ptr++;
						return *this;
					}

					iterator operator--()
					{
						--_ptr;
						return *this;
					}

					iterator operator--(int)
					{
						_ptr--;
						return *this;
					}

					iterator operator+(int val)
					{
						_ptr += val;
						return *this;
					}

					iterator operator-(int val)
					{
						_ptr -= val;
						return *this;
					}

					iterator operator+=(int val)
					{
						_ptr += val;
						return *this;
					}

					iterator operator-=(int val)
					{
						_ptr -= val;
						return *this;
					}

					T& operator*() const
					{
						return *_ptr;
					}

					bool operator!=(const iterator &obj)
					{
						return _ptr != obj._ptr;
					}

					bool operator==(const iterator &obj)
					{
						return _ptr == obj._ptr;
					}

					bool operator>(const iterator &obj)
					{
						return _ptr > obj._ptr;
					}
					
					bool operator<(const iterator &obj)
					{
						return _ptr < obj._ptr;
					}

					bool operator>=(const iterator &obj)
					{
						return _ptr >= obj._ptr;
					}
					
					bool operator<=(const iterator &obj)
					{
						return _ptr <= obj._ptr;
					}
			};
			
			// template <class Iterator>
			class reverse_iterator
			{
				public:
					// typedef typename iterator_traits<Iterator>::iterator_category		iterator_category;
					// typedef typename iterator_traits<Iterator>::value_type				value_type;
					// typedef typename iterator_traits<Iterator>::difference_type			difference_type;
					// typedef typename iterator_traits<Iterator>::pointer					pointer;
					// typedef typename iterator_traits<Iterator>::reference				reference;

				private:
					iterator _it;
				
				public:
					reverse_iterator()
					{}
					reverse_iterator(iterator it): _it(it)
					{}

					~reverse_iterator()
					{}

					reverse_iterator operator++()
					{
						--_it;
						return *this;
					}

					reverse_iterator operator++(int)
					{
						_it--;
						return *this;
					}

					reverse_iterator operator--()
					{
						++_it;
						return *this;
					}

					reverse_iterator operator--(int)
					{
						_it++;
						return *this;
					}

					reverse_iterator operator+(int val)
					{
						_it -= val;
						return *this;
					}

					reverse_iterator operator-(int val)
					{
						_it += val;
						return *this;
					}

					reverse_iterator operator+=(int val)
					{
						_it -= val;
						return *this;
					}

					reverse_iterator operator-=(int val)
					{
						_it += val;
						return *this;
					}

					T& operator*() const
					{
						return *_it;
					}

					bool operator!=(const reverse_iterator &obj)
					{
						return _it != obj._it;
					}

					bool operator==(const reverse_iterator &obj)
					{
						return _it == obj._it;
					}

					bool operator>(const reverse_iterator &obj)
					{
						return _it > obj._it;
					}
					
					bool operator<(const reverse_iterator &obj)
					{
						return _it < obj._it;
					}

					bool operator>=(const reverse_iterator &obj)
					{
						return _it >= obj._it;
					}
					
					bool operator<=(const reverse_iterator &obj)
					{
						return _it <= obj._it;
					}
			};
			
			iterator begin()
			{
				return _arr;
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(_arr + (_size - 1));
			}
			
			// const_iterator begin() const
			// {
			// 	return _arr;
			// }
			
			iterator end()
			{
				return _arr + _size;
			}

			reverse_iterator rend()
			{
				return reverse_iterator(_arr - 1);
			}
			
			// const_iterator end() const
			// {
			// 	return _arr + _size;
			// }
			
			// reverse_iterator rbegin()
			// {
			// 	return _arr[_size - 1];
			// }
			// const_reverse_iterator rbegin() const
			// {
			// 	return _arr[_size - 1];
			// }
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
				value_type *	temp;
				temp = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(temp + i);
				for (size_type i = 0; i < n; i++)
				{
					temp[i] = val;
				}
				for (size_type i = 0; i < n && i < _size; i++)
				{
					temp[i] = _arr[i];
				}
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.destroy(_arr + i);
				}
				_alloc.deallocate(_arr, _size);
				_arr = temp;
				_size = n;
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
				value_type * temp;
				if (_arr)
				{
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.destroy(_arr + i);
					}
					_alloc.deallocate(_arr, _size);
				}
				if (n > _capacity)
				{
					_capacity = n;
				}
				temp = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(temp + i);
				for (size_type i = 0; i < n; i++)
					temp[i] = val;
				_arr = temp;
				_size = n;
			}
			
			// assign: fill
			template <class InputIterator>
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type
				assign (InputIterator first, InputIterator last)
			{
				value_type* temp;
				InputIterator beg = first;
				if (_arr)
				{
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.destroy(_arr + i);
					}
					_alloc.deallocate(_arr, _size);
				}
				size_type size = 0;
				while (beg != last)
				{
					beg++;
					size++;
				}
				if (size > _capacity)
				{
					_capacity = size;
				}
				temp = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(temp + i);
				for (size_type i = 0; i < size; i++)
				{
					temp[i] = *first;
					first++;
				}
				_size = size;
				_arr = temp;
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
				value_type * temp;
				size_type i = 0;
				iterator beg = this->begin();
				size_type n = 0;
				InputIterator start;

				start = first;
				while (start != last)
				{
					n++;
					start++;
				}
				if (_capacity < _size + n )
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
				size_type n = 0;
				iterator beg = first;
				while (beg != last)
				{
					beg++;
					n++;
				}
				size_type i = 0;
				iterator ret;
				while (beg != last)
				{
					if (beg == first)
					{
						ret = beg;
						while (beg != last)
						{
							if (i + n > _size)
								break;
							_arr[i] = _arr[i+n];
							i++;
						}
						break;
					}
					i++;
				}
				_size -= n;
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
				std::swap(_arr, x._arr);
				std::swap(_capacity, x._capacity);
				std::swap(_arr, x._arr);
				std::swap(_alloc, x._alloc);
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