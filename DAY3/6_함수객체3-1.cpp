#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) 
{
	return n % 3 == 0; 
}
// 함수     : 동작만 있다.
// 함수객체 : 동작과 상태(멤버데이타)가 있다.
//			 "상태를 가지는 함수" 

struct IsDivide
{
	int value;
	IsDivide(int v) : value(v) {}

	bool operator()(int n) { return n % value == 0; }
};

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3;

	IsDivide f(k);  // f는 k값 보관(캡쳐)
					// f는 객체지만 인자가 한개인 단항함수 처럼사용가능.

	bool b = f(10); // 10 % k == 0

	auto p2 = std::find_if(v.begin(), v.end(), f );


	// 단 한번만 사용한다면 "임시객체 형태"로 하면 편리합니다.
	auto p3 = std::find_if(v.begin(), v.end(), IsDivide(k) );
						// => IsDivide(k) 
						// => 단항함수 + k 값을 같이 전달하는 의미

	// Closure : 문맥에 속한 지역변수를 캡쳐할수 있는 함수(객체)
	//			 C++이 아닌, 범용적인 프로그래밍 용어
	// 
	// 일반함수 : Closure 가 될수 없다.
	// 함수객체 : Closure 가 될수 있다.
}



