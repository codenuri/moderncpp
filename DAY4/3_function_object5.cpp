//  137 page 

       int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); // 호출
	int n2 = Add2(1, 2); // 기계어 코드 치환, 장점은 "빠르다"


	int(*f)(int, int) = &Add2;

//	if (사용자입력 == 1) f = &Add1;

	f(1, 2);  // ? 호출 ? 치환 ?
}

// 1. 인라인 치환은 "컴파일" 문법이다.
// 2. 위 코드에서 f 는 변수(변할수 있다.) 이다.
// 핵심 : 인라인 함수라도 "함수포인터에 담아서 호출" 하면 
//       인라인 치환 될수 없다.
// => 함수의 "이름" 으로 호출하는 경우만 인라인 치환된다.