#include <iostream>
#include <vector>
#include <type_traits>

// C++11 type traits : 타입의 특성을 "조사" 하는 것      is_xxx 시작
// C++20 concept     : "개념(concept)" 을 정의 하는 것. is 로시작하지 말라

template<typename T>
concept Container = requires(T & c)
{
	{ c.begin() } -> std::input_iterator;
	{ c.end() } -> std::input_iterator;
};



template<typename T>
void foo(T a)
{
	// T가 포인터 인지 알고 싶다.
	bool b1 = std::is_pointer_v<T>;

	// T가 STL 의 컨테이너인지 알고 싶다.
	// => 어떻게 조사할까가 중요한것이 아닙니다.
	// => "컨테이너를 어떻게 정의할까?" 가 중요합니다.
	bool b2 = Container<T>;
}

void use_container(Container auto& c)
{

}

int main()
{
	std::vector<int> v = { 1,2,3 };
	foo(v);

	use_container(v); // ok
	use_container(3); // error
}