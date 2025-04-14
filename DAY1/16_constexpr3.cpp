// C++ 에서 constexpr 은 3가지 용도로 사용됩니다.
// 1. constexpr 상수 - C++11 - 이전예제
// 2. constexpr 함수 - C++11 - 지금 예제
// 3. constexpr if   - C++17


// constexpr 함수
// => 함수 앞에 "constexpr" 붙인것
// 1. 인자 값을 컴파일 시간에 알수 있고
// 2. 함수의 결과를 컴파일 시간에 알아야 한다면
// => 함수 호출을 컴파일 할때 수행하겠다는 것

constexpr int Factorial(int n)
{
	return n == 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n = 5;

	int arr1[Factorial(5)]; 

	int arr2[Factorial(n)]; 
						
	int s2 = Factorial(n); 

	int s = Factorial(5);
}
