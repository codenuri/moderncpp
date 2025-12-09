// decltype 추론 - 71page
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;
	
	// auto : 우변의 표현식으로 타입 추론
	auto a = r; // 
	
	// decltype : () 안의 표현식으로 타입 추론	
	// => 언제 사용하나요 ? => 주로 template 만들때 사용(뒤에 예제 참고)
	
	// 추론 규칙 #1. () 안에 변수 이름만 있을때
	// => 변수의 선언을 보고 타입 결정
	decltype(n) d1; // int d1
	decltype(r) d2; // int& d2  인데, 초기값 없으므로 error
	decltype(c) d3; // const int d3 인데, 초기값 없으므로 error
	decltype(p) d4; // int* d4
}



