// 1_초기화8 - 62page
#include <iostream>
#include <initializer_list> // 핵심

void foo(std::initializer_list<int> e)
{
}
int main()
{
	// 아래 코드는
	// 1. 우변의 초기값을 배열과 같은 형태로 메모리에 배치
	//    => 메모리 위치는 표준에서 정의하지 않았지만
	//	  => 지역변수로 만든 경우 대부분 컴파일러는 스택사용

	// 2. e 는 "포인터2개" 또는 "포인터+갯수"로 관리
	// vs : 시작 주소와 마지막 다음 주소
	// g++: 시작 주소와 갯수로 관리
	std::initializer_list<int> e = { 1,2,3,4,5 };

	// #2. 요소 접근은 STL 과 같은 반복자 사용
	auto first = e.begin();
	auto last = e.end();

	// #3. 읽기만 가능. 쓰기는 안됨
	int n = *first; // ok.  1

//	*first = 10; // error. 
	
	// #4. std::initializer_list 는 함수 인자로 사용하기 위해
	//     만든것 ( 대부분 생성자 인자)
	// foo 가 std::initializer_list 를 인자로 받으면 아래 처럼전달가능
	foo({ 1,2,3 });
	foo({ 1,2,3,4, 5 });
	// => 동일 타입의 인자를 "가변길이"로 전달가능

	// 배열과 같은 구조인데, 그냥 배열사용하면 안되나요 ?
	// => 배열을 함수 인자로 사용할수 없습니다. 포인터로 변경해서 사용
	// => 그리고, 생성자 문법중 "std::initializer_list" 만의 문법이있습니다.

	// std::vector 사용하면 안되나요 ?
	// => vector 는 모든 데이타가 "힙" 에 놓이게 됩니다.


	// 그럼, std::initializer_list는 언제 ? 왜? 사용하나요 ?
	// => 다음예제
}


