#include <type_traits>
#include <iostream>

template <typename T>
typename std::enable_if<!std::is_floating_point<T>::value, T>::type
 abs(T x)
{
    return x < 0 ? -x : x;
}

int main()
{
    std::cout << abs(-3.14) << std::endl;
    std::cout << abs(-42) << std::endl;
    return 0;
}

