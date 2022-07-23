
#include <iostream>
#include <type_traits>

enum one
{
    num = 1,
    num2 = 2
};

enum two
{
    alp = 1,
    alp2 = 2
};

#define one_check(e)                           \
    {                                          \
        std::cout << e << ",one" << std::endl; \
    }
#define two_check(e)                           \
    {                                          \
        std::cout << e << ",two" << std::endl; \
    }

#define mix(a)     if(std::is_same<decltype(a), one>::value) { one_check(a); }else{two_check(a);}
void t_value()
{
    enum one a = num;

    enum two b = alp;
    mix(a);
    mix(b);
}

one returnone()
{
    one a= num;
    return a;
}

two returntwo()
{
    two b =alp;
    return b;

}

void t_func()
{
    mix(returnone());
    mix(returntwo());
}


int main()
{
    //g++ t.cpp -std=c++11
    enum one a = num;
    enum two b = alp;

    one_check(a);
    two_check(b);

    t_value();
    t_func();   
}
