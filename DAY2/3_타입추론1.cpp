// 20_타입추론1 - 69 page
// 타입 추론 문법

int main()
{
	int x[3] = { 1,2,3 };

	auto a = x[0];	// int a = x[0]

	// 타입 추론(type deduction, type inference)
	// => 컴파일러가 표현식(expression, 코드)를 보고
	//    타입을 결정하는 것, 

	// C++ 에서는 3가지 경우가 있습니다.
	// 1. template
	// 2. auto
	// 3. decltype

	// 1, 2 의 규칙 : 거의 동일합니다.
	// ==> template 으로 먼저 학습하는것이 편리합니다.
	// ==> 추론된 타입 조사 가능
	// ==> auto 는 조사하기 쉽지 않음
	// 
	// 3 은 1,2 와는 다른 규칙
}