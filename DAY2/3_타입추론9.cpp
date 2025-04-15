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

	decltype(*p)	d2; // "*p = 10" 가능하다. int& d2  인데 초기값때문에 에러
	decltype(x[0])	d3; // "x[0] = 10" ok..   int& d3

	decltype(n) d;	// "n = 10" 도 되지만, id-expression 이므로
					// 규칙 #1 적용 해서  선언을 보고 결정
					// int d
					
	decltype(n + n) d4;  // "n + n = 10" 안된다. 따라서 rvalue
						 // int d4;
							
	decltype(++n)   d5; // "++n = 10" 은 된다.!!!
						// int& d5  
						// 초기값 없기 때문에 에러
						
						
	decltype(n++)   d6; // "n++ = 10" 은 안된다.
						// int d6
			
}

// 규칙 #1 : () 안에 id 만있을때
// => id 의 선언과 동일한 타입

// 규칙 #2 : () 안에 id 만 있는 경우가 아닐때
// => 해당 표현식이 등호의 왼쪽에 올수있는가 없는가를 조사
// lvalue 라면 reference type
// rvalue 라면 value type
