#include <bits/stdc++.h>
#include <vector>

class twoVal {
	private:
		int one;
		int two;
	public:
		twoVal(int a = 0, int b = 0): one(a), two(b) {};
		bool operator==(twoVal obj)
		{
			return (one == obj.one && two == obj.two);
		}
};

int main()
{
	twoVal t(2, 0);
	if (t == 2)
		std::cout << "the same" << std::endl;
	else
		std::cout << "not the same" << std::endl;
}
