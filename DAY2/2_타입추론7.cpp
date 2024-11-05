// decltype 규칙 2.
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };


	// 규칙 #2. id-expression 이 아닌 경우
	// expression 이 등호의 왼쪽에 올수 있으면(lvalue) : 참조타입
	// expression 이 등호의 왼쪽에 올수 없으면(rvalue) : 값타입

	decltype(p)		d1;	// id-expression, 규칙 1적용.
						// int* d1

	decltype(*p)	d2; // *p = 5 가 ok. 따라서, int&
	decltype(x[0])	d3; // x[0] =5가 ok. 따라서, int&

	decltype(n) d;	// n = 5 가 되지만, id-expression 이므로
					// 규칙 1 적용. n 의 선언과 동일 타입
					// int& 가 아니고 int
					

	decltype(n + n) d4; // n+n = 5 는 안됨. int

	decltype(++n)   d5; // ++n = 5 는 ok.   int&
						
						
	decltype(n++)   d6; // n++ = 5 는 error. int

	// 결과가 참조라는 것은 사용자가 만든 메모리라는 의미
	// 결과가 값은 "임시값" 이거나 "지역변수" 라는 것
	// ++을 함수라고 생각해 봅시다.
	++n; // operator++(n)
	n++; // operator++(n, int)
}
int& operator++(int& a)
{
	a = a + 1;
	return a;
}
int operator++(int& a, int)
{
	int temp = a;
	a = a + 1;
	return temp;
}