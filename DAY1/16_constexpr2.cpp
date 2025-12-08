// 아래 개념은 모든 프로그래밍언어에서 사용되는 중요한 개념.. 반드시 알아 두세요

// "상수" 라는 용어의 2가지 관점

// 1. 실행할때 변경할수 없다. => immutable, readonly, runtime-constance

// 2. 컴파일시 컴파일러가 값을 알수 있다. => compile-time constant
// => 값도 변경안됨.

// C 언어의 const 의 의미는 1 입니다
// => 즉, 컴파일 시간 상수가 아닌 "값을 변경할수 없다" 의 의미
// => 값은 컴파일 시간에 알수도 있고, 모를수도 있습니다.

//					readonly 의미		compile-time 상수
// C				const				X
// C++				const				constexpr  ( C++11 )
// C#				readonly			const
// Rust				모든변수는 readonly	const 
//					변경할때만 mut

int main()
{
	int n = 3;
	std::cin >> n; // n 의 값은 실행시 결정
	
	// const 는 "readonly"
	// 따라서 컴파일 시간에 값을 몰라도 된다.
	const int c1 = n; // ok.
	const int c2 = 3; // ok

	// C++11 constexpr : 컴파일 시간 상수를 만드는 것
	// => 초기값을 반드시 컴파일시간에 알아야 한다.
	constexpr int c3 = n;	// error
	constexpr int c4 = 3;	// ok

	// rust 
	// > immutable(readonly) 변수 : 메모리 사용
	// > const 변수 : 컴파일 시간에 값을 알고 있다. 메모리 잡을 필요 없다
	//				 사용하는 위치에 값으로 변경하면된다.(매크로 치환과유사)
	// 단, C++은 constexpr 도 메모리 사용할수도 있고, 제거될수도 있다.
}