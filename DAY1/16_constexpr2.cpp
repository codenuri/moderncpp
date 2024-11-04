// constexpr function
// => 인자의 값을 "컴파일 시간에 알수 있고"
//    "함수 호출 표현식이" 컴파일시간에 값을 알아야 하는 곳에 있다면
//    함수 호출을 컴파일 시간에 해달라.

// => 단, 컴파일 시에 인자값을 알수 없거나
//    컴파일할때 결과를 알아야 되는 곳이 아니면
//    실행할때 수행

// constexpr 을 붙여서 손해볼것은 없다.!!
// => 메모리할당, 파일 열기, 화면 출력등은 할수 없다.

constexpr int Factorial(int n)
{
	// 메모리할당, 파일 열기, 화면 출력 등이 여기 있으면 에러
	return n == 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n = 5;

	int arr1[Factorial(5)];  // ok. int arr1[120]

//	int arr2[Factorial(n)];  // error. 
							// 컴파일 할때 값을 알아야 하는 위치인데
							// 인자값을 컴파일 할때 알수 없다.
		
	int s1 = Factorial(n);  // ok. 실행시간에 수행

	int s2 = Factorial(5); // 컴파일시 ? 실행시 ?
						   // 컴파일러에 따라 다를수 있다.
	const int s3 = Factorial(5); //  컴파일러에 따라 다를수 있다.

	constexpr int s4 = Factorial(5); // ok. 반드시 컴파일시에 해달라.
	constexpr int s5 = Factorial(n); // error. 
}
