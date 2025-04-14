// 빌드 하는법 : Ctrl + F5

int main()
{
	int n1 = 0;

	// auto : 우변의 표현식으로 좌변 변수의 타입을 결정
	// => 1. 컴파일러가 컴파일 시간에 결정. 성능저하 없음
	auto a1 = 3;	// int    a1 = 3
	auto a2 = 3.4;	// double a2 = 3.4

	// auto 는 꽤 복잡합니다.
	const int c = 0;
	auto a3 = c; // 1. int a3 = c;  =>> 정답
				 // 2. const int a3 = c;

	// auto 외에 decltype 도 있습니다.
	// auto : 우변으로 타입 추론
	// decltype() : () 안의 표현식으로 타입추론
	decltype(a1) d1; // int d1
}

