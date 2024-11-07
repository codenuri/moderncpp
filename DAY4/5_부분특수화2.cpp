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

int main()
{
	// 아래 처럼 나오게 만들어 보세요.
	Object<int,  double >::foo();// T, U
	Object<int*, double*>::foo();// T*, U*
	Object<int*, double> ::foo();// T*, U
	Object<int,  int>::foo();    // T, T
	Object<int, short>::foo();   // int, short
}

