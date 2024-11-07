#include <iostream>
#include <vector>
#include <type_traits>  
#include <concepts> // C++20 에서 제공하는 이미 만들어진 concept

// 1. concept 만드는 법을 알아야 합니다.
// 2. 이미 만들어진 concept 이 있습니다.
// 3. template 만들때 concept 을 만족하는 것만 사용하게 할수 있습니다.

/*
template<typename T> requires std::input_iterator<T> // concept 또는 traits
void foo(T a)
{
}
*/
// 위와 동일, 단, concept 만 가능. traits 는 안됨
template<std::input_iterator T>  
void foo(T a)
{
}

// 위와 동일, concept 만 가능, T를 사용못함.
void foo(std::input_iterator auto a)
{
}

// 그래서, 아래 코드가 "제약이 없는 템플릿"
void foo(auto a)
{
}
int main()
{
	std::vector<int> v = { 1,2,3 };
	foo(v.begin());
//	foo(3); // error. 반복자 아님.
}
