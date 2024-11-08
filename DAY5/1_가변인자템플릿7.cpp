#include <iostream>

// 재귀의 종료를 위해(C++11 버전)
void safe_printf(const char* s)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                throw "invalid format string: missing arguments";
            }
        }
        std::cout << *s++;
    }
}

template<typename T, typename... Args>
void safe_printf(const char* s, const T& value, Args... args)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                std::cout << value;
                safe_printf(s + 1, args...); // recursive
                return;
            }
        }
        std::cout << *s++;
    }
    throw "extra arguments provided to printf";
}
int main()
{
    // printf 문제점
    // => 인자의 갯수를 잘못 사용하면 미정의 동작 발생
//  printf("%d, %d\n", 1);    
//  printf("%d, %d\n", 1, 2, 3);

    try
    {
        safe_printf("%, %\n", 1, 2); // ok
        //      safe_printf("%, %\n", 1);    // 인자 갯수 부족 => 예외 발생
        //      safe_printf("%, %\n", 1, 2, 3);// 인자 갯수 초과 => 예외 발생
    }
    catch (const char* e)
    {
        std::cout << e << std::endl;
    }
}