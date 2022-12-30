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
        };
        int SomeOp::add(int x)
        {
                return _val + x;
        }
}

int main()
{
        ft::SomeOp<int> op(3);

        std::cout << op.add(5) << std::endl;
        return 0;
}

