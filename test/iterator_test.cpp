#include <bits/stdc++.h>

void	print(std::vector<int> &v);

int main()
{
	std::vector<int> v;
	
	v.push_back(3);
	v.push_back(6);
	v.push_back(9);

	std::vector<int>::iterator b = v.begin();
	std::vector<int>::iterator e = v.end();

	while (b != e)
	{
		std::cout << *b << std::endl;
		b++;
	}
	return 0;
}
