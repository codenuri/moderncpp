// decltype 2.
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };
	
	// 규칙 #2. () 안에 "심볼의이름 + 다른 연산자등"이 있을때
	// => 해당 표현식이 등호의 왼쪽에 올수 있다면 "참조"
	// => 그렇지 않으면 "값" 타입

	decltype(p)	d1; // 규칙 #1. int* p 이므로 int* d1

	decltype(*p)	d2; // "*p = 0" 이 가능하므로 참조 타입. int& d2 인데, 초기값없으므로 error
	decltype(x[0])	d3; // "x[0] = 10" 이 ok.. int& d3

	decltype(n) d; 	    // "n = 10" 이 가능하지만, () 안에 이름만 있다.
			    // 규칙 2가 아닌 규칙 1 사용. int d
					

	decltype(n + n) d4; // "n + n = 10" 은 안됨. int d4
	decltype(++n)   d5; // "++n = 10" 은 ok.    int& d5
						
						
	decltype(n++)   d6; // "n++ = 10" 은 error.  int d6
			




}

