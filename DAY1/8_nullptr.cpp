// 8_nullptr - 29page

int main()
{
	// C++98 시절
	// => 포인터 초기화를 위해 리터럴 "0" 사용가능
	int  n1 = 0;	// 0은 int 타입이지만
	int* p1 = 0;	// 포인터로도 암시적 형변환 됩니다.

//	int* p2 = n1;   // error.리터럴 0이 아닌 0을 가진 변수 n1
					// 리터럴 형태의 0 만 포인터 초기화 사용가능

	// C++11 부터는 포인터 0을 의미하는 새로운 리터럴 도입
	int* p3 = nullptr; // good
	int* p4 = 0;	   // bad. 에러는 아니지만 나쁜 코드

	int n2 = nullptr; // error. 
					  // nullptr 은 포인터 초기화만 사용가능
}