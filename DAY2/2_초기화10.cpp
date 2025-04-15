// 1_초기화10
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2{ 1,2,3,4,5 };


	// 아래 2줄의 차이점은 ?
	std::vector<int> v3(10, 2);	// vector(int, int) 생성자 호출
								// => 10개요소를 2로 초기화
								// => v3.size() => 10

	std::vector<int> v4{10, 2}; // vector(std::initializer_list)호출
								// => 2개 요소를 10, 2로 초기화
								// => v4.size() => 2


	// 아래 코드에서 에러는 ?
	std::vector<int> v5 = 10;		// error
									// vector(int) 는 explicit 

	std::vector<int> v6 = {10};		// ok
									// vector(std::initializer_list)
									// 는 explicit 아님.

	// 결론 : 객체 생성시 () 와 {} 초기화는
	// 생성자 인자로 "std::initializer_list" 를 사용하는 생성자가
	// 없을때는 동일 합니다.
	// 있을때는 다르게 동작 합니다.
}




