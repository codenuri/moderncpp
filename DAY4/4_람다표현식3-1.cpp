#include <iostream>

int main()
{
	// 람다 표현식을 auto 에 담아 사용하려고 합니다.
	// => 다음 중 최선의 코드는 ???
	auto f1        = [](int a, int b) { return a + b; }; 
	const auto& f2 = [](int a, int b) { return a + b; }; 
	auto&& f3      = [](int a, int b) { return a + b; }; 

	// #1. f1 에 대해서
	Point pt = Point(0, 0);
	// 1. 우변에서 임시객체 생성
	// 2. 임시객체를 pt에 복사(이동생성자 또는 복사 생성자)
	// => 하지만 대부분의 컴파일러는 아래 코드처럼 최적화
	Point pt(0, 0); // 즉 오버헤드 없음!!! 단지 한개의 객체를 만든것
					// 그래서, 위 f1도 오버헤드 없음.

	int n1 = 0;
	int& r = n1;
	r = 10; // 내부원리는 포인터
			// 즉, 이 코드는 (*r) = 10 이므로
			// 메모리를 따라가서 원본에 접근, 따라가므로 성능저하
			
			// f2, f3 은 모두 포인터를 사용해서 객체에() 연산자 접근
			// 오버헤드 있음.
}

