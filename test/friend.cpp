#include <iostream>

class Some {
	private:
		int _val;

	public:
		Some(int val): _val(val) {};
		void	setVal(int val)
		{
			_val = val;
		}
		int getVal(const Some& obj)
		{
			return obj._val;
		}
};
/*
int getVal(const Some& obj)
{
	return obj._val;
}
*/
int main()
{
	Some s(3);
	Some v(14);

	s.setVal(45);
	std::cout << s.getVal(v) << std::endl;
	return 0;
}
