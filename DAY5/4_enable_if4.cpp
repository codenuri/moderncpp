#include <iostream>
#include <type_traits>

// 현재 C++은 "특정 타입" 에 따른 함수 오버로딩을
// 지원 합니다.
void foo(int)    {}
void foo(double) {}

// "타입"이 아닌 "특정 조건을 만족하는 타입들"에 따른 오버로딩은 있으면
// 좋지 않을까요 ?
//void goo(가상함수가있는클래스들) {}
//void goo(가상함수가없는클래스들) {}

// std::enable_if_t<조건, 반환타입>
// std::enable_if_t<조건>   <== 이렇게 하면 반환 타입은 void


template<typename T>
//std::enable_if_t<std::is_polymorphic_v<T>, void>
std::enable_if_t<std::is_polymorphic_v<T>>
goo(T a)
{
	std::cout << "가상함수가 있는 경우\n";
}

template<typename T>
//std::enable_if_t<!std::is_polymorphic_v<T>, void>
std::enable_if_t<!std::is_polymorphic_v<T>>
goo(T a)
{
	std::cout << "가상함수가 없는 경우\n";
}

class A
{
	virtual void foo() {}
};
int main()
{
	A a;
	goo(a);
	goo(3); // int 는 가상함수 없습니다.

}
