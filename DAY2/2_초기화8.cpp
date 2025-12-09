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
	// => STL 처럼 반복자 를 꺼내서 사용
	// => 3개의 멤버함수만 제공(size(), begin(), end())

	auto first = e.begin();
	auto last = e.end();

	// 읽기만 가능. 쓰기 안됨
	//*first = 20; // error

	// 반복자가 있으므로 range-for 가능
	for (auto n : e)
	{

	}

	// 함수가 std::initializer_list 를 인자로 받으면
	// 아래 처럼 전달 가능
	foo({ 1,2,3 });
	foo({ 1,2,3, 4 });
	foo({ 1,2,3, 4,5 });
}


