void foo(int a) 
{
}

int main()
{
	// 포인터 만들기 : 선언문에서 심볼이름 앞에 * 사용
	void (*p)(int)  = &foo; // 정확한 코드
//	void (*p)(int)  = foo;  // function name to pointer conversion 발생
				// 함수 이름은 함수의 주소로 암시적 형변환 될수 있다.

	// 포인터와 참조
	int n = 10;

	int* p1 = &n;	// 포인터 변수
	int& r1 = n;	// 참조변수

	// 아래 코드 ? 부분 완성하세요
	int x[3] = {1,2,3};
	
	int (*p2)[3] = &x;
	int (&r2)[3] = x;
	
	// x의 타입은 int[3] 
	auto a1 = x;	// "int a1[3] = x;" 으로 만들면 컴파일 에러
			// "int* a1 = x;    으로 만들면 에러 아님
			// 따라서 auto 는 int*

	auto& a2 = x;   // auto 를 int[3] 으로 결정하면
			// int(&a2)[3] = x; // 이 코드는 에러 아님
			// 따라서 이때는 auto 가 int[3]

	// 왜 어려워 보일까 ?
	// => 배열 타입을 만들때 []를 심볼 뒤에 붙인것이 실수
	int    n1 = 10;  // n1 타입은 int
	double d1 = 2.3; // d1 타입은 double

	int y[3] = {1,2,3}; // y 타입은 int[3]
	int[3] y = {1,2,3}; // 이렇게 했다면 보다 쉽지 않을까 ? java, C# 스타일
	int[3] *p; // 배열 포인터도 이게 쉽지 않을까?


}













