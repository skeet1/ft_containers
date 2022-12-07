#include <iostream>

using namespace std;

template<typename T>
T min(T& a, T& b)
{
	if (a < b) return a;
	return b;
}

int main()
{
	cout << min(2, 4) << endl;
	cout << min('a', 'c') << endl;
	cout << min("hello", "world") << endl;
	cout << min(2.3, 2.4) << endl;
	return 0;
}
