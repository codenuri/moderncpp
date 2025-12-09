// 3_타입추론7-1
#include <iostream>
#include <algorithm>

// 배열을 T 로 받을때
// 값으로 받으면 "포인터" 로 변해서 전달 - 크기 정보 없어짐. decay 발생
// 참조로 받으면 "배열"   로 전달 - 크기 정보 유지

template<typename T> 
//void foo(T arr)	// int* arr. 크기 정보가 사라집니다. decay(퇴화)된다고 표현합니다.
void foo(T& arr)	// int(&arr)[3]. 크기 정보 유지
{
	auto n = std::size(arr); // 배열의 크기 구하기
	
	std::cout << n << std::endl;
}

int main()
{
	int x[3] = {1,2,3};
	foo(x); // T arr = x
		// auto arr = x
}

