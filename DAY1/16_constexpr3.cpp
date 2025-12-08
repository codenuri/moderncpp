// C++ 에서 constexpr 의 3가지 종류
// 1. constexpr 상수 - C++11  2번 예제 참고. 
// 2. constexpr 함수 - C++11  아래 예제 <== 중요!
// 3. constexpr if  - C++17

// constexpr function
// => 인자의 값을 "컴파일 시간에 알수 있고"
// => 함수 호출결과를 컴파일 시간에 알아야 하는 문맥에서 호출된다면
// => 함수 실행자체를 컴파일 시간에 해달라는 것
// => 실행시간에도 사용가능. 
constexpr int Factorial(int n)
{
	return n == 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n = 5;

	int arr1[Factorial(5)]; // 1. 컴파일러는 인자가 5인것을 알수 있다.
							// 2. 배열의 크기로 함수 결과를 사용, 컴파일 할때 알아야 한다.
							// 3. Factorial 이 constexpr 함수 이므로
							// => "Factorial(5)" 의 실행은 컴파일 시간에..

	int arr2[Factorial(n)]; // error. 인자 값을 컴파일 할때 알수 없다.
						
	int s1 = Factorial(n); // ok. 인자값을 컴파일 할때 모르지만,
						   // 함수의 결과를 컴파일 할때 알 필요도 없다.
							// "실행시간 동작"

	int s2 = Factorial(5); // 컴파일 시간 ? 실행시간 ?
							// => 컴파일러에 따라 다를수 있다

	const int s3 = Factorial(5); // 컴파일 시간 ? 실행시간 ?
								// => 컴파일러에 따라 다를수 있다

	constexpr int s5 = Factorial(5); // 반드시 컴파일 할때 실행해 달라는 의미. 
}