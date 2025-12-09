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

	// type deduction(추론)
	// => 컴파일러가 문맥을 보고 타입을 결정하는것
	// => 다른 언어는 "type inference" 라는 용어를 사용

	// C++ 은 3가지 경우에 추론 발생
	// 1. template
	// 2. auto
	// 3. decltype
	// => 1,2 는 동일한 타입 추론 규칙 사용. template 으로 먼저 학습하는것이 쉽다.
	// => 3은 다른 규칙.
}
