/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:12:10 by mkarim            #+#    #+#             */
/*   Updated: 2022/12/08 14:38:40 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.hpp"

size_t getCapacity(size_t _size)
{
	size_t findCapacity = 1;

	while (findCapacity < _size)
	{
		findCapacity = findCapacity << 1;
	}
	return findCapacity;
}
