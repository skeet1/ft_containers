#include <iostream>

class MyClass {
	public:
		MyClass()
		{
			std::cout << "This is the constructor" << std::endl;
		}
};

int main()
{
	std::allocator<MyClass> alloc;
	MyClass* p = alloc.allocate(10);
	alloc.construct(p);

	return 0;
}
