// 3_함수객체4 -  137 page 

       int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); // 호출
	int n2 = Add2(1, 2); // 기계어 코드 치환, 
						 // 장점: 빠르다.

	int(*f)(int, int) = &Add2;

//	if (사용자 입력 == 1) f = &Add1; // 실행시간에 f가 가리키는 곳은 변경될수있다

	f(1, 2);  // 호출
}

// 핵심 #1. 인라인 치환은 컴파일 시간에 수행되는 문법이다.
// 핵심 #2. 인라인 함수라도 "함수 포인터에 담아서 사용하면"
//          인라인 치환될수 없다.
//			빨라질수 없다는 의미. 