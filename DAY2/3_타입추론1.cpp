// 타입추론 - 69 page
// 
template<typename T>
void foo(T a) {}

int main()
{
	int x[3] = { 1,2,3 };

	// auto : 우변의 표현식으로 좌변의 타입을 결정
	auto a = x[0];	// int a = x[0];

	// decltype : () 안의 표현식으로 타입을 결정
	// => 주로 template 에서 널리 사용
	decltype(a) d;  // int d;

	// template : 함수 인자를 보고 타입을 결정
	foo(3); // T = int 로 결정

}
