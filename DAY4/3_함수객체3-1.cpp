#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }


struct IsDivide
{
	int value;
	IsDivide(int n) : value(n) {}

	bool operator()(int n)  { return n % value == 0; }
};

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3;

	IsDivide f(k);	// f 는 내부적으로 k 값을 캡쳐(보관) 합니다.
					// f 는 단항함수 처럼 사용 가능합니다.

	bool ret = f(10); // "10 % k(3) == 0" 을 조사하는 함수


	auto p2 = std::find_if(v.begin(), v.end(), f );

	std::cout << *p2 << std::endl;// 6


	// IsDivide 객체를 find_if 에 한번만 전달할 목적이면
	// 임시객체가 좋습니다.

	auto p2 = std::find_if(v.begin(), v.end(), IsDivide{k} );
						// => 단항함수와 main 지역변수 k를 같이 보내는 의미입니다.
						// => 즉, 지역변수를 k의 값을 캡쳐해서 같이 전달
						// 이런것을 "Closure" 라고 합니다.

//	std::find_if(v.begin(), v.end(), cmp );    // 함수만 전달
// 
//	std::find_if(v.begin(), v.end(), IsDivide{ k }); // 함수 + k값 전달
}

// 클로져(Closure)
// => 자신의 외부 함수(위예제는 main) 의 지역변수를 캡쳐할수 있는 함수

// C++ 은 "함수객체" 가 closure 입니다.

// 구글에서 "python closure"
//			"rust closure", "go closure", "java closure"

