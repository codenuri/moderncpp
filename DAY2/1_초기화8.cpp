// 1_초기화8 - 62page
#include <iostream>
#include <initializer_list> // 핵심

void foo(std::initializer_list<int> e)
{
	// e에는 begin, end, size 멤버 함수가 있습니다.
	for (auto n : e)
	{

	}
}
int main()
{
	// 1. 초기값을 배열과 동일한 구조로 메모리에 만들고
	//    (메모리 위치는 undefined 이지만 대부분 스택에 )
	// 2. e 에는 시작 주소와 last 다음 주소 또는 갯수가 있습니다.
	// visual studio : 포인터 2개
	// g++           : 포인터 1개와 갯수
	std::initializer_list<int> e = { 1,2,3,4,5 };

	// vector 와의 차이점
	// => vector 는 모든 요소가 힙에 있습니다.

	// 배열과 차이점.
	// => 배열 자체를 함수 인자로 할수 없습니다.
	// => 포인터로 전달, 갯수를 별도로 전달해야 합니다.
	// => foo( int x[5] )

	// initializer_list 는 함수인자로 전달가능
	foo(e);

	// 함수가 initializer_list를 받으면 아래 처럼 보내도 됩니다.
	foo({ 1,2,3 });
	foo({ 1,2,3, 4,5 });

	// 어떨때 사용하나요 ??
	// => 생성자 인자로 사용하기 위해 만든것 입니다.(대부분 생성자에서 사용)
	// => 다음소스... 
}


