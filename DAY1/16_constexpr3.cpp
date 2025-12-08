// C++ 에서 constexpr 의 3가지 종류
// 1. constexpr 상수 - C++11  2번 예제 참고. 
// 2. constexpr 함수 - C++11  아래 예제 <== 중요!
// 3. constexpr if  - C++17

// constexpr function
// => 인자의 값을 "컴파일 시간에 알수 있고"
// => 함수 호출결과를 컴파일 시간에 알아야 하는 문맥에서 호출된다면
// => 함수 실행자체를 컴파일 시간에 해달라는 것
constexpr int Factorial(int n)
{
	return n == 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n = 5;

	int arr1[Factorial(5)]; 
	int arr2[Factorial(n)]; 
						
	int s1 = Factorial(n); 
	int s2 = Factorial(5);

}