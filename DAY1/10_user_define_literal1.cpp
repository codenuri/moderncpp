// 34 page
// 
// 리터럴 표기법
// =>prefix 값 postfix


int main()
{
	// #1. 접두사는 진법(radix) 입니다.
	int a1 = 0x10;	// 16진수
	int a2 = 0b10;	// 2진수 - C++14
	int a3 = 010;	// 8진수
	int a4 = 10;	// 10진수


	// #2. 접미사는 "해당 리터럴의 타입" 을 결정합니다.
	auto n1 = 10;	// int n1 = 10. 정수형 리터럴에 접미사가 없으면 int 타입
	auto n2 = 10ll;	// long long n2 = 10
	
	auto f1 = 3.4;	// double f1 = 3.4  즉, 실수형 리터럴은 접미사가 없으면 double
	auto f2 = 3.4f;	// float f2 = 3.4   f 는 float 타입

	// C++, C# 등 : 일부 타입 표기만 가능
	// Rust       : 모든 표준 타입에 해당하는 접미사 제공
	
	// C++11 : 사용자가 접미사를 만드는 문법을 제공합니다.!				
	// => 아래 코드는 에러.. 실제 예제는 다음소스에서
	auto g = 30gram;

	auto m = 30cm;
}




