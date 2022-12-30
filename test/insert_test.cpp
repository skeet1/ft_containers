#include <bits/stdc++.h>

void	print(std::vector<int> &v);

int main()
{
	std::vector<int> v;

	v.push_back(2);
	v.push_back(5);
	v.push_back(12);

	print(v);

	v.insert(1, 100);
}
