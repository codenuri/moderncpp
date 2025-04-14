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

	int arr1[Factorial(5)]; // ok. 컴파일 하면 int arr1[120] 이 됩니다.

	int arr2[Factorial(n)]; // error. 인자값을 컴파일 할때 알수 없다.
						
	int s2 = Factorial(n); // ok. 실행시간에 함수 호출

	// 
	int ret1 = Factorial(5); // ok. 컴파일 시간 ? 실행시간 ?
							// => 컴파일러의 종류, 버전에 따라 다름

	const int ret2 = Factorial(5); // ok. 컴파일 시간 ? 실행시간 ?
							// => 컴파일러의 종류, 버전에 따라 다름

	constexpr int ret3 = Factorial(5); // ok. 컴파일 시간 ? 실행시간 ?
							// => 반드시 컴파일 할때 수행해 달라는 것
							// 
}
