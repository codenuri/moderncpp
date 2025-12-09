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
	
	? p2 = &x;
	? r2 = x;

}





