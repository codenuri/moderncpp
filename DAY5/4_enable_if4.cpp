#include <iostream>
#include <type_traits>

// 현재 C++은 "특정 타입" 에 따른 함수 오버로딩을
// 지원 합니다.
void foo(int)    {}
void foo(double) {}

// "타입"이 아닌 "특정 조건을 만족하는 타입들"에 따른 오버로딩은 있으면
// 좋지 않을까요 ?
//void goo(가상함수가있는타입) {}
//void goo(가상함수가없는타입) {}

template<typename T>
void goo(T)
{
	std::cout << "가상함수가 있는 타입\n";
}
template<typename T>
void goo(T)
{
	std::cout << "가상함수가 없는 타입\n";
}

int main()
{

}


