// decltype 타입 추론 - 71page

// decltype(expression)
// => () 안에 있는 표현식으로 타입 추론
// => 표현식의 결과가 lvalue 인지 rvalue 인지 에 따라 달라짐(조사하는 도구)

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	// 규칙 #1. () 안에 변수 이름만 있을때(id - expression)
	// => 변수의 선언을 보고 타입 결정

	decltype(n) d1; // int d1
	decltype(r) d2; // int& d2  인데,  현재 코드는 초기값 없기 때문에 에러
	decltype(c) d3; // const int d3    현재 코드는 초기값 없기 때문에 에러
	decltype(p) d4; // int* d4


	// 따라서 아래 차이점 알아 두세요
	auto a5 = c;		// int a5 = c;
	decltype(c) d5 = c;	// const int d5 = c;
}