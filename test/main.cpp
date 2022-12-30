#include <bits/stdc++.h>
#include <vector>

void	print(std::vector<int> &v);
void	print_infos(std::vector<int> &v);

int main()
{
	std::vector<int> v;

	for (int i = 1; i <= 5; i++)
		v.push_back(i);

	std::enable_if
	// Print the first and last elements of the vector using rbegin, rend, begin, and end
	// std::cout << "First element (using rbegin): " << *v.rbegin() << std::endl;
	// std::cout << "Last element (using rend): " << *(v.rend() - 1) << std::endl;
	// std::cout << "First element (using begin): " << *v.begin() << std::endl;
	// std::cout << "Last element (using end): " << *(v.end() - 1) << std::endl;
	// std::vector<int>::reverse_iterator it = v.rbegin();
	// f.erase(f.begin() + 2, f.begin() + 6);
	// print_infos(f);
	// print(f);
}