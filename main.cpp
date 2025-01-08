#include <iostream>
#include <concepts>


template <typename T>
concept hasDoMethod = requires(T&& object)
{
    {object.Do()};
};


template <typename T>
int foo(T a) requires std::is_same<T, float>::value
{
    std::cerr << " float overloading " << std::endl;
    return 0;
}

template <typename T>
int foo(T a) requires (!std::is_same<T, float>::value) and (!hasDoMethod<T>)
{
    std::cerr << " other overloading " << std::endl;
    return 0;
}



template <typename T>
int foo(T a) requires hasDoMethod<T>
{
    std::cerr << " do obg overloading " << std::endl;
    return 0;
}

class DoObj
{
public:
    void Do()
    {

    }
};


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
    DoObj d_o;

    foo(d_o);
    return 0;
}
