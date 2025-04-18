#include <iostream>

// 이 예제는 "specialization" 문법 연습!!

template<typename T, typename U> struct Object
{
	static void foo() { std::cout << "T, U" << std::endl; }
};

template<typename T, typename U> struct Object<T*, U*>
{
	static void foo() { std::cout << "T*, U*" << std::endl; }
};

template<typename T, typename U> struct Object<T*, U>
{
	static void foo() { std::cout << "T*, U" << std::endl; }
};

// 핵심 
// => primary template 의 인자가 2개 라도
// => 부분 특수화 할때 인자의 갯수는 달라 질수 있습니다
// => 하지만 "부분 특수화 표기("Object<T, T>") 에는 2개로 해야 합니다.

template<typename T> struct Object<T, T>
{
	static void foo() { std::cout << "T, T" << std::endl; }
};

// 아래의 경우는
// "partial specialization" 이 아니라 "specialization" 입니다.
// template 인자가 없어야 합니다.
template<> struct Object<int, short>
{
	static void foo() { std::cout << "int, short" << std::endl; }
};


template<typename T, typename U, typename V> struct Object<T, Object<U, V> >
{
	static void foo() { std::cout << "T, Object<U, V>" << std::endl; }
};

int main()
{
	// 아래 처럼 나오게 만들어 보세요.
	Object<int,  double >::foo();// T, U
	Object<int*, double*>::foo();// T*, U*
	Object<int*, double> ::foo();// T*, U
	Object<int,  int>::foo();    // T, T
	Object<int, short>::foo();   // int, short

	// 아래 처럼 나오게 해보세요
	Object<double, Object<short, char>>::foo();
							// T, Object<U, V>  나오게 해보세요
}

