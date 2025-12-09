//  std::initializer_list - 62page
#include <iostream>
#include <initializer_list> // C++11 부터 사용가능



void foo(std::initializer_list<int> e)
{
}

int main()
{
	// 아래 한줄의 메모리 그림을 정확히 이해 해야 합니다.
	// 1. 우변의 초기값을 배열과 동일한 구조체 메모리에 생성
	// 2. e 는 
	//    => g++ : 2개의 포인터로 구현(시작, 마지막 다음 요소주소)
	//    => vc  : 1개 포인터 + 갯수 로 구현. 
	// 3. e 는 결국, 배열과 유사한 메모리의 데이타를 접근할때 사용
	std::initializer_list<int> e = { 1,2,3,4,5 };

	// 이후 e 를 사용하는 방법은 
	// => STL 의 반복자 처럼 사용
}


