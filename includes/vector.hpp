/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:44:52 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/04 13:13:56 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

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
			class iterator {
				
				private:
					value_type * _ptr;
				public:
					iterator()
					{
						// _ptr = NULL;
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

					iterator operator+(int val)
					{
						_ptr += val;
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
			};
			// class reverse_iterator {
				
			// 	private:
			// 		value_type * _ptr;
			// 	public:
			// 		reverse_iterator()
			// 		{
			// 			// _ptr = NULL;
			// 		}
			// 		reverse_iterator(value_type* ptr)
			// 		{
			// 			_ptr = ptr;
			// 		}

			// 		reverse_iterator operator++()
			// 		{
			// 			++_ptr;
			// 			return *this;
			// 		}

			// 		reverse_iterator operator++(int)
			// 		{
			// 			_ptr++;
			// 			return *this;
			// 		}

			// 		reverse_iterator operator+(int val)
			// 		{
			// 			_ptr += val;
			// 			return *this;
			// 		}

			// 		T& operator*() const
			// 		{
			// 			return *_ptr;
			// 		}

			// 		bool operator!=(const reverse_iterator &obj)
			// 		{
			// 			return _ptr != obj._ptr;
			// 		}

			// 		bool operator==(const reverse_iterator &obj)
			// 		{
			// 			return _ptr == obj._ptr;
			// 		}
			// };
			typedef		iterator								iterator;
			typedef		const iterator							const_iterator;
			// typedef		reverse_iterator						reverse_iterator;
			// typedef		const reverse_iterator 				const_reverse_iterator;
	
			iterator begin()
			{
				return _arr;
			}
			const_iterator begin() const
			{
				return _arr;
			}
			iterator end()
			{
				return _arr + _size;
			}
			const_iterator end() const
			{
				return _arr + _size;
			}
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
				for (size_type i = 0; i < _size; i++)
					_arr[i] = val;
			}

			// range
			template <class InputIterator>
				vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type())
			{
				iterator beg = first;
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
				size_t i = 0;
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
				_capacity = x._capacity;
				_alloc = x._alloc;
				_arr = _alloc.allocate(_capacity);
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
				setValue(temp, n, val);
				for (size_type i = 0; i < n && i < _size; i++)
				{
					temp[i] = _arr[i];
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
				// if (n >= _size)
					// throw std::out_of_range("out of range");
				return _arr[n];
			}
			
			const_reference operator[](size_type n) const
			{
				// if (n >= _size)
				// 	throw std::out_of_range("out of range");
				return _arr[n];
			}

			reference at(size_type n)
			{
				if (n > _size)
					throw std::out_of_range("out of range");
				return _arr[n];
			}
			
			const_reference at(size_type n) const
			{
				if (n > _size)
					throw std::out_of_range("out of range");
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
					_alloc.deallocate(_arr, _size);
				}
				while (_capacity < n)
					_capacity *= 2;
				temp = _alloc.allocate(_capacity);
				for (size_type i = 0; i < n; i++)
					temp[i] = val;
				_arr = temp;
				_size = n;
			}
			
			// assign: fill
			template <class InputIterator>
				void assign (InputIterator first, InputIterator last)
			{
				value_type* temp;
				iterator beg = first;
				if (_arr)
				{
					_alloc.deallocate(_arr, _size);
				}
				size_type size = 0;
				while (beg != last)
				{
					beg++;
					size++;
				}
				while (_capacity < size)
					_capacity *= 2;
				temp = _alloc.allocate(_capacity);
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
					for (size_type i = 0; i < _size; i++)
					{
						temp[i] = _arr[i];
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
				while (_capacity < _size + n)
				{
					_capacity *= 2;
				}
				temp = _alloc.allocate(_capacity);
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
				while (_size + n > _capacity)
					_capacity *= 2;
				temp = _alloc.allocate(_capacity);
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

			//print infos
			void	print() const
			{
				for (size_type i = 0; i < _size; i++)
				{
					std::cout << _arr[i];
					if (i < _size - 1) std::cout << " ";
				}
				std::cout << "\n";
			}
			void	print_info() const {
				std::cout << "size is : " << _size << " , and capacity is : " << _capacity << std::endl;
			}
	};
}

#endif