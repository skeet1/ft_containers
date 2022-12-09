/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:44:52 by mkarim            #+#    #+#             */
/*   Updated: 2022/12/09 11:54:47 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <cmath>

size_t getCapacity(size_t _size);

template<typename T>
void	setZeros(T& arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}

namespace ft {
	template <typename T> 
	class vector {
		private:
			size_t				_size;
			size_t				_capacity;
			T* 					_arr;
			std::allocator<T>	alloc;
		public:
			//******************************************************************//
			// ------------------------- Constructors ------------------------- //
			//******************************************************************//
			vector() {
				_size = 0;
				_capacity = 1;
				_arr = alloc.allocate(1);
			}
			vector(size_t size)
			{
				_size = size;
				_capacity = getCapacity(_size);
				_arr = alloc.allocate(_size);
				setZeros(_arr, _size);
			}
			vector(size_t size, T initVal)
			{
				_size = size;
				_capacity = getCapacity(_size);
				_arr = alloc.allocate(_size);
				for (size_t i = 0; i < _size; i++)
				{
					_arr[i] = initVal;
				}	
			}
			//******************************************************************//
			// -------------------------- ITERATORS --------------------------- //
			//******************************************************************//

			//******************************************************************//
			// -------------------------- CAPACITY ---------------------------- //
			//******************************************************************//
			size_t	size() {
				return _size;
			}
			size_t max_size() {
				return powl(2, 64)/sizeof(T) - 1;
			}
			void	resize(size_t newSize)
			{
				T*	temp;
				temp = alloc.allocate(newSize);
				setZeros(temp, newSize);
				for (size_t i = 0; i < newSize && i < _size; i++)
				{
					temp[i] = _arr[i];
				}
				alloc.deallocate(_arr, _size);
				_arr = temp;
				_size = newSize;
			}
			size_t	capacity()
			{
				return _capacity;
			}
			bool 	empty()
			{
				return (_size == 0);
			}
			void    reserve(size_t newCapacity)
			{
				if (_capacity < newCapacity)
				{
					
				}
			}
			//******************************************************************//
			// --------------------------- MODIFIERS -------------------------- //
			//******************************************************************//
			void	assign(size_t size, T val)
			{
				T* temp;
				if (_arr)
				{
					alloc.deallocate(_arr, size);
				}
				temp = alloc.allocate(size);
				for (size_t i = 0; i < size; i++)
					temp[i] = val;
				_arr = temp;
				_size = size;
			}
			void	push_back(T val)
			{
				T*	temp;
				if (_capacity == _size)
				{
					_capacity *= 2;
					temp = alloc.allocate(_capacity);
					for (size_t i = 0; i < _size; i++)
					{
						temp[i] = _arr[i];
					}
					alloc.deallocate(_arr, _size);
					_arr = temp;
				}
				_arr[_size] = val;
				_size++;
			}
			void	print()
			{
				for (size_t i = 0; i < _size; i++)
				{
					std::cout << _arr[i];
					if (i < _size - 1) std::cout << " ";
				}
				std::cout << "\n";
			}
			//******************************************************************//
			// --------------------------- DESTRUCTOR ------------------------- //
			//******************************************************************//
			~vector(){
				
			}
	};
}

#endif