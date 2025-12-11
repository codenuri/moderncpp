#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }

class IsMod
{
	int value;
public:
	IsMod(int n) : value{ n } {}

	bool operator()(int n)
	{
		return n % value == 0;
	}
};

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3;

	// 주어진 구간에서 "k의 배수"를 찾고 싶다. 
	// => foo 안에서 "3" 대신 "k" 로 변경해야 하는데.
	// => foo 에서는 main 의 지역변수 사용못함!!
	auto p1 = std::find_if(v.begin(), v.end(), foo);

	//------------------------------------------------
	IsMod f{ k }; // f는 내부적으로 k 보관(k 값 캡쳐)

	bool b = f(10); // "10 % k == 0" 의 의미 - 즉, 단항함수인데, main 의 k사용

	auto p2 = std::find_if(v.begin(), v.end(), f);

	// IsMod 객체를 한번만 사용하면 "임시객체"로 전달
	auto p2 = std::find_if(v.begin(), v.end(), IsMod{k} );
			// => 임시객체를 만드는 모양이지만
			// => 마치 "IsMod + 지역변수 k" 를 같이 전달하는 느낌
}

// 일급객체 : 함수 인자로 전달 가능한 객체
// => C 언어에서 함수도 함수 인자로 전달 가능하므로 일급 객체

// 클로져(Closure)
// => 자신이 속한 문맥의 지역변수를 캡쳐할수 있는 일급객체

// 일반 함수 : 일급객체지만 클로져 아님
// 함수 객체 : 일급객체이고 클로져 !!!

// Rust, Swift 는 람다 표현식을 "Closure" 라고 부릅니다.





