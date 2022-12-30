/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:13:16 by mkarim            #+#    #+#             */
/*   Updated: 2022/12/28 12:14:49 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

class myClass {
	public:

		myClass(){};
		template <typename T>
		void 	add(T a, T b)
		{
			cout << "this is a template function" << endl;
		}
	
		void add(int a, int b)
		{
			cout << "if int i will say goodbye!" << endl;
		}
		
};

int main()
{
	myClass obj;

	obj.add(2, 6)
	obj.add(1.2, 3.0);
	obj.add(1, 2);
	return 0;
}

