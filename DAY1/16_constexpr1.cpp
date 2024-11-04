// C++11 에서 추가된 constexpr

// 1. constexpr 상수
// 2. constexpr 함수
// 3. constexpr if 문 - 51 page

// constexpr 상수이야기

// 프로그램에서 사용되는 상수의 2가지 의미
// #1. 컴파일 할때 값을 알수 있는것
// #2. 실행시 변경할수 없는 것

int main()
{
	int n = 10;
	const int c1 = 10; // 컴파일 할때 c1값을 알수 있다.
	const int c2 = n;  // 컴파일 할때 c2값을 알수 없다

	// c1, c2 모두 값을 변경할수 없다.

	// 다음중 에러를 모두 고르세요
	int arr1[10]; // ok
	int arr2[n ]; // error. 
	int arr3[c1]; // ok
	int arr4[c2]; // error.
	// => 배열의 크기는 컴파일 할때 값을 알아야 합니다.
	// => 템플릿 인자도 컴파일 할때 값을 알아야 합니다.
	// => 따라서, 같은 const 라도 될수도 있고 안될수도 있습니다.
}

// C#
// const : 컴파일 시에 값을 알아야 한다.
// readonly : 값을 변경할수 없다.

// Rust
// const : 컴파일 시에 값을 알아야 한다.
// immut : 값을 변경할수 없다.

// C++11
// constexpr : 컴파일 할때 값을 알아야 한다.
// const     : 값을 변경할수 없다.