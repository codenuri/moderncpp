#include <iostream>


// 160 page

// 부분 특수화 문법 학습을 위한 코드


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

// T, T
// 핵심 
// 1. primary template 의 타입 인자가 2개라도, 
//    부분 특수화 버전은 달라질수 있습니다.
// 2. 부분 특수화 표시(Object<T, T>) 에는 반드시 2개 있어야 합니다.

template<typename T> struct Object<T, T>
{
	static void foo() { std::cout << "T, T" << std::endl; }
};

// specialization.. 타입이 모두 확정..
template<> struct Object<int, short>
{
	static void foo() { std::cout << "int, short" << std::endl; }
};
int main()
{
	// 아래 처럼 나오게 만들어 보세요.
	Object<int,  double >::foo();// T, U
	Object<int*, double*>::foo();// T*, U*
	Object<int*, double> ::foo();// T*, U
	Object<int,  int>::foo();    // T, T
	Object<int, short>::foo();   // int, short

	Object<double, Object<short, char>>::foo();
								// T, Object<U, V> 라고 로깅해보세요
}

