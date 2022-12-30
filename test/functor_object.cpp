#include <bits/stdc++.h>

class Add {
	public:
		Add(int toAdd) : _toAdd(toAdd) {};
		int operator()(int x)
		{
			return x + _toAdd;
		}
		int getAdd()
		{
			return _toAdd;
		}
	private:
		int _toAdd;
};

int main()
{
	Add one(3);
	Add two(9);
	
	one(4);

	std::cout << one.operator()(5) << std::endl;
	return 0;
}
