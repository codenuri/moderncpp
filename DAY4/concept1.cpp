#include <iostream>
#include <vector>
#include <type_traits>  // import std.vector

// C++11 : move, perfect forwarding, lambda, variadic template....
// C++20 : concept, module, ranges, coroutine...
template<typename T>
concept container = requires(T & c)
{
//	c.begin();
//	c.end();

//	std::begin(c);
//	std::end(c);

	{ std::begin(c) } -> std::input_iterator;
	{ std::end(c) } -> std::input_iterator;

	// std::input_iterator<T> : 표준에서 이미 제공하는 컨셉
	//							T가 반복자라면 true
	//							위에 사용시에는 <> 인자 없이!!
};

template<typename T>
void foo(const T& arg)
{
	// type traits - C++11기술, template 부분 특수화로 만드는 기술
	bool b1 = std::is_pointer_v<T>;

	// T가 컨테이너인지 알고 싶다 ??
	// => 어떻게 구현 해야 할까 ?? 보다... 
	// => 더 중요한것은, "컨테이너의 정의"를 어떻게 할까 ?
	// => "컨테이너 라는 개념을 정의" 를 하자!!
	// => 그래서, concept 이름은 is_ 로 시작하지 말라. 

	bool b2 = container<T>;	// T가 container concept 을 만족하면 true
						
	std::cout << b2 << std::endl;
}

class A
{
public:
	void begin() {}
	void end() {}
};

int main()
{
	std::vector<int> v = { 1,2,3 };
	foo(v);

	int x[3] = { 1,2,3 };
	foo(x);

	A a;
	foo(a);
}