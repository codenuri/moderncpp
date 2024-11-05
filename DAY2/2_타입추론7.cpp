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

	decltype(*p)	d2; 
	decltype(x[0])	d3; 

	decltype(n) d; 
					

	decltype(n + n) d4; 
	decltype(++n)   d5; 
						
						
	decltype(n++)   d6; 
			
}

