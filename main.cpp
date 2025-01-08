#include <iostream>
#include <concepts>
template <typename T>
int foo(T a) requires std::is_same<T, float>::value
{
    std::cerr << " float overloading " << std::endl;
    return 0;
}

template <typename T>
int foo(T a) requires (!std::is_same<T, float>::value)
{
    std::cerr << " other overloading " << std::endl;
    return 0;
}

int main()
{
    float a;
    double b;
    int c;
    float d;


    foo(a);
    foo(b);
    foo(c);
    foo(d);

    return 0;
}
