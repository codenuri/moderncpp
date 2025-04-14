// 1_structure_binding2

int main()
{
	int arr[3] = { 1,2,3 };

	// 파이썬, C#, RUST 등은 관심 없는 멤버의 경우 _를사용합니다.
//	(a1, _, a2) = arr;

	// C++ 은 C++26 부터 _ 지원 합니다.
	// C++26 이전에는 
	auto [a1, _, a3] = arr;	// ok
							// _ 라는 이름의 변수를 선언한것
							// int _ = arr[1]

	auto [b1, _, b3] = arr;	// error
							// int _ = arr[1]를 또 한것
							// 즉, _ 라는 이름의 변수를
							// 다시 선언한것

	// C++26 에서 도입되는 문법
	// => _ 라는 이름의 변수는 여러번 선언될수 있다.
	int _ = 10;
	int _ = 20; // C++26 부터 ok
}

// g++ 사용시
// g++ a.cpp -std=c++2a   , C++20 나오기전 옵션
// g++ a.cpp -std=c++20   , 정식 발표후

// g++ a.cpp -std=c++2b   , C++23 나오기전 옵션
// g++ a.cpp -std=c++23   , 정식 발표후

// g++ a.cpp -std=c++2c   , C++26 나오기전 옵션
// g++ a.cpp -std=c++26   , 정식 발표후