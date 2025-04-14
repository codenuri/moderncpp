
// constexpr  : 컴파일 시간 상수를 만드는 키워드
// const      : immutable 을 만드는 키워드. 

int main()
{
	int n = 3;

	// 아래 c1, c2는 변경할수 없다는 것
	const int c1 = n; // ok
	const int c2 = 3; // ok

	// 아래 c3, c4 는 반드시 컴파일할때 알아야 하고
	// 변경할수도 없다는것
	constexpr int c3 = n; // error
	constexpr int c4 = 3; // ok


	// 많이 나오는 질문
	// "const int c3 = 리터럴" 이 컴파일 시간 상수로 

	int arr1[c1];
	int arr2[c2];
	int arr3[c4];
}
