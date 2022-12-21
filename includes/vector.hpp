/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:44:52 by mkarim            #+#    #+#             */
/*   Updated: 2022/12/21 17:09:38 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>

template<typename T>
void	set_value(T& arr, size_t size, T value = 0)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = value;
	}
}

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
					iterator(value_type * ptr)
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
			iterator begin()
			{
				return _arr;
			}
			const iterator begin() const
			{
				return _arr;
			}
			iterator end()
			{
				return _arr + _size;
			}
			const iterator end() const
			{
				return _arr + _size;
			}
			// **************************************************************** //
			// ------------------------- Constructors ------------------------- //
			// **************************************************************** //
			
			//default
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				_size = 0;
				_capacity = 0;
				_alloc = alloc;
			}

			//fill
			explicit vector (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type())
			{
				_size = n;
				_capacity = n;
				_alloc = alloc;
				_arr = _alloc.allocate(_capacity);
				set_value(_arr, _size, val);
			}

			//range
			vector (iterator first, iterator last,
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

			//copy
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
			
			// **************************************************************** //
			// -------------------------- CAPACITY ---------------------------- //
			// **************************************************************** //
			size_t	size() const
			{
				return _size;
			}
			size_type max_size() const
			{
				return powl(2, 64)/sizeof(T) - 1;
			}
			void	resize(size_type newSize, T val = 0)
			{
				value_type *	temp;
				temp = _alloc.allocate(newSize);
				setValue(temp, newSize, val);
				for (size_type i = 0; i < newSize && i < _size; i++)
				{
					temp[i] = _arr[i];
				}
				_alloc.deallocate(_arr, _size);
				_arr = temp;
				_size = newSize;
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
			void	assign(iterator first, iterator last)
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

			// at: reference
			reference at(size_type n)
			{
				if (n > _size)
					throw std::out_of_range("something");
				return _arr[n];
			}
			// at: const reference
			const_reference at(size_type n) const
			{
				if (n > _size)
					throw std::out_of_range("something");
				return _arr[n];
			}

			// back: reference
			reference back()
			{
				return _arr[_size - 1];
			}
			// back: const reference
			const_reference back() const
			{
				return _arr[_size - 1];
			}

			// clear
			void	clear()
			{
				_size = 0;
			}
			void	push_back(T val)
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
			iterator insert(iterator pos, const T& val)
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
					if (beg == pos)
						break;
					temp[i] = _arr[i];
					i++;
					beg++;
				}
				ret = i;
				temp[i++] = val;
				while (i < _size+1)
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
			iterator insert(iterator pos, size_type n, const T& val)
			{
				value_type * temp;
				size_type i = 0;
				iterator beg = this->begin();
				size_type ret = 0;
				while (_capacity < _size + n)
				{
					_capacity *= 2;
				}
				temp = _alloc.allocate(_capacity);
				while (i < _size)
				{
					if (beg == pos)
						break;
					temp[i] = _arr[i];
					i++;
					beg++;
				}
				ret = i;
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
				return _arr + ret;
			}
			
			// insert 3: insert range of iterators
			iterator insert(iterator pos, value_type * start, value_type * until)
			{
				value_type * temp;
				size_type i = 0;
				iterator beg = this->begin();
				size_type ret = 0;
				size_type n = 0;
				value_type * first;

				first = start;
				while (first != until)
				{
					n++;
					first++;
				}
				while (_size + n > _capacity)
					_capacity *= 2;
				temp = _alloc.allocate(_capacity);
				while (i < _size)
				{
					if (beg == pos)
						break;
					temp[i] = _arr[i];
					i++;
					beg++;
				}
				ret = i;
				while (start != until)
				{
					temp[i++] = *start;
					start++;
				}
				while (i < _size + n)
				{
					temp[i] = _arr[i-n];
					i++;
				}
				_alloc.deallocate(_arr, _size);
				_arr = temp;
				_size += n;
				return _arr + ret;
			}

			// erase
			iterator erase(iterator pos)
			{
				iterator it = this->begin();
				iterator ret;
				size_type i = 0;

				std::cout << "i have to delete " << *pos << std::endl;
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
			// **************************************************************** //
			// --------------------------- DESTRUCTOR ------------------------- //
			// **************************************************************** //
			~vector(){
				
			}
	};
}

#endif