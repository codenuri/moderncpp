// constexpr function
// => 인자의 값을 "컴파일 시간에 알수 있고"
//    "함수 호출 표현식이" 컴파일시간에 값을 알아야 하는 곳에 있다면
//    함수 호출을 컴파일 시간에 해달라.

constexpr int Factorial(int n)
{
	return n == 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n = 5;

	int arr1[Factorial(5)];  // ok

	int arr2[Factorial(n)]; 
		
	int s1 = Factorial(5);
	int s2 = Factorial(n); 
}
