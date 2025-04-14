// 16_constexpr1 - 50page

// 컴퓨터 프로그램에서 "상수" 의 2가지 개념

// #1. 컴파일 시간에 값을 알수 있는가 ?
// => constant expression
// => compile-time constant 의 개념
// => 반드시 초기값을 컴파일 할때 알아야 한다.
// => C++11 의 constexpr 이 이 개념을 만드는 키워드

// #2. 실행시간에 값을 변경할수 없는가 ?
// => immutable, readonly 개념
// => 초기값은 실행할때 결정될수도 있다.
// => C/C++ 의 const 키워드가 이개념을 만드는 키워드!!

// 왜 컴파일 시간에 값을 아는 것이 중요 합니까 ?
// 1. 보다 좋은 최적화, 컴파일 시간에 값을 알면, 모든 연산을 컴파일
//    시간에 할수 있다.

// 2. 일부 C++ 문법은 "컴파일 시간에 값을 알아야 한다."
// => 배열의 크기
// => 템플릿 인자


int main()
{
	int n = 10;
	const int c1 = 10; 
	const int c2 = n;  

	// 다음중 에러를 모두 고르세요
	int arr1[10]; // ok
//	int arr2[n ];	// g++, clang++ ok. 
					// vs error
					// C++ 표준에서는 에러
	int arr3[c1];	// ok
	int arr4[c2];	// error
}




// 배열의 크기로 변수를 사용하는 문법
// VLA ( Variable Length Array ) 라는 문법
// C언어 
// => C89 : 안됨
// => C99 : ok
// => C11 : 컴파일러 선택. 될수도 있고, 안될수도 있다

// C++ 표준 : VLA 지원안함. 배열의 크기는 반드시 컴파일 시간에 알아야한다
// 단, g++, clang++ 은 확장문법으로 지원함..배열의 크기로 변수도 가능
// vs 지원안함. 