// decltype 규칙 2.
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };


	// () 안에 이름만 있으므로 규칙 #1 적용
	decltype(p)		d1;		//int* d1
	

	// 규칙 #2. () 안에 이름과 연산자등의 코드가 같이 있을때
	//			(id-expression 이 아닐때)
	// 표현식이 등호의 왼쪽에 올수 있다면(lvalue) : 참조 타입
	// 표현식이 등호의 왼쪽에 올수 없다면(rvalue) : 값 타입

	decltype(*p)	d2; 
	decltype(x[0])	d3; 

	decltype(n) d; 
					

	decltype(n + n) d4; 
	decltype(++n)   d5; 
						
						
	decltype(n++)   d6; 
			
}

