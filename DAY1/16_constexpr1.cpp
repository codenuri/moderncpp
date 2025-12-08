// 16_constexpr1

// 왜 컴파일 시간 상수를 알아야 하나요 ?
// 1. 컴파일 시간에 값을 알수 있다면 최적화가 훨씬 잘됩니다.
// => 즉, const 보다 constexpr 이 최적화 잘됨

// 2. C++ 일부 문맥에서는 컴파일 시간 상수를 요구합니다.
// => 배열의 크기
// => template 인자

int main()
{
	int n = 10;
	const int c1 = 10; 
	const int c2 = n;  
	constexpr int c3 = 10;
	
	int arr1[10]; 
	int arr2[n ]; 
	int arr3[c2]; 
	int arr4[c3]; 
	int arr5[c1];

}
