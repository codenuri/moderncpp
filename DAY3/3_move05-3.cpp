// move05-3.cpp
#include <iostream>
#include <string>

int main()
{
	// #1. primitive type 에 대한 move 는 아무 효과 없습니다. 에러도 아님
	// => 단지, 캐스팅 한것
	int n1 = 10;
	int n2 = std::move(n1); // static_cast<int&&>(n1)


	// #2. raw pointer 도 결국 이동생성자같은 개념은 없습니다.
	// => 따라서, std::move() 는 아무런 효과도 없습니다.
	int* p1 = new int;
	int* p2 = std::move(p1); // int* p2 = p1 과 동일
							// p1 이 0 으로 reset 되는것 아님. 

	// #3. move 된 객체를 사용할수 있는가 ?
	// => 클래스의 구현에 따라 달라집니다.
	// => 따라서, 일반적으로는 사용하지 말라고 권장.
	// => 표준에서 명확히 정의하지 않음 (undefined) C++ 단점)
	std::string s1 = "to be or not to be";
	std::string s2 = std::move(s1);

	std::cout << s1 << std::endl; // 안전하지 않음. 

	
	// #4. move 된 객체가 다시 자원을 빼앗아서 사용가능한가 ?
	// => 가능. swap()이 되려면 보장해야 한다.
	std::string s3 = "a";
	s1 = s3;	// 이렇게
	s1 = std::move(s3); // 또는 이렇게..

	std::cout << s1 << std::endl; // ok. 안전
}

// C++ : 아주 어렵지만, 약간만 알아도 개발 가능, 진입장벽이 낮다.
//       => 단, 최적화는 고급 기술을 알아야 한다.

// Rust : C++ 보다 쉽다, 하지만, 모든 것을 알아야 개발 가능, 진입장벽이 높다
//		 => 컴파일만되면, 최적화된 코드!
/*
let s1 = "aa";
let s2 = s1; // s1 은 move 됨
println!("{s1}"); // error. move  된 변수 사용
*/