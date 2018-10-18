#include <stdio.h>


#define DUMP(func, call) \
    printf("%s: func = %p, called by = %p\n", __FUNCTION__, func, call)


void __attribute__((no_instrument_function))
__cyg_profile_func_enter(void *this_func, void *call_site)
{
    DUMP(this_func, call_site);
}


void __attribute__((no_instrument_function))
__cyg_profile_func_exit(void *this_func, void *call_site)
{
    DUMP(this_func, call_site);
}


int do_multi(int a, int b)
{
    return a * b;
}


int do_calc(int a, int b)
{
    int c =  do_multi(a, b);
    return c;
}


int main()
{
    int a = 4, b = 5;
    int c = do_calc(a, b);
    printf("result: %d\n", c );
    return 0;
}
