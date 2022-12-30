#include <bits/stdc++.h>

void print(std::vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i < v.size() - 1) std::cout << " ";
	}
	std::cout << std::endl;
}

void print_infos(std::vector<int> &v)
{
	std::cout << "size is : " << v.size() << " , and capacity is : " << v.capacity() << std::endl;
}

