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
	const int c1 = 10; 
	const int c2 = n;  

	// 다음중 에러를 모두 고르세요
	int arr1[10]; 
	int arr2[n ]; 
	int arr3[c1]; 
	int arr4[c2]; 

}
