#include <iostream>

using namespace std;

namespace ft {
	template<typename Type>
	class SomeOp{
		private:
			int _val;
		public:
			SomeOp(int val): _val(val){};
			int add(int x);
	/*		int min(int x);
			template<typename T>
				T add(T x, T y);
				*/
	};
}

	template<typename Type>
	int ft::SomeOp<Type>::add(int x)
	{
		return _val + x;
	}

int main()
{
	ft::SomeOp<int> op(3);

	std::cout << op.add(5) << std::endl;
//	std::cout << op.add(5, 9) << std::endl;
//	std::cout << op.add(5, 4) << std::endl;
	return 0;
}
