﻿// C++98 초기화의 문제점 - 54 page
#include <complex>

// C++11 만들때, 
// => C++98 스타일의 초기화에 문제가 많다고 생각했습니다.
// => 아래 코드를 참고

int main()
{
	// 문제점 1. 변수의 종류에 따라 초기화 방법이 다르다.
	int n1 = 10;
	int n2(10); 
	int x[2] = { 1,2 };
	std::complex<double> c(1, 2);


	// 2. 동적 할당한 배열을 초기화 할수 없다.
	int* p = new int[3];
	x[0] = 0; // 초기화가 아닌, 대입한것!!!

	// 3. std::vector 등을 사용할때 배열 처럼 초기화 할수 없었다.
	std::vector<int> v1(10, 3);      // ok. 10 개를 3으로 초기화
	std::vector<int> v2 = { 1,2,3 }; // 이렇게 사용할수 없을까 ?
									 // C++11 부터는 가능. C++98 은 안됨.
}

class Test
{
	// 4. 클래스 멤버로 있는 배열을 초기화 할수 없다.
	int x[3];
};



