#include <bits/stdc++.h>

using namespace std;
int main()
{
	vector<int> v;
	
	int c = v.capacity();
	for (int i = 1; i < 100; i++)
	{
		v.push_back(i);
		if (c != v.capacity())
		{
			c = v.capacity();
			cout << "capacity changed : " << c << "\n";
		}
	}
	v.reserve(100);
	c = v.capacity();
	cout << "now capacity is : " << c << "\n";
	for (int i = 1; i <= 500; i++)
	{
		v.push_back(i);
		if (c != v.capacity())
		{
			c = v.capacity();
			cout << "capacity changed : " << c << "\n";
		}
	}
}
