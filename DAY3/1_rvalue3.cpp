// 1_rvalue - 87 page

// lvalue : "값과 이름" 이 있다.
//          주소 연산자로 주소를 구할수 있다
//			참조를 반환하는 함수
//			이름을 가지는 일반 변수(객체)
// 
// [참고.Rust 용어] lvalue 라고 부르지않고 "place expression"
// 
// rvalue : "이름이 없고, 값만 있다."
//			주소연산자로 주소를 구할수 없다.
//			값을 반환하는 함수
//			literal, Point{1,1}등의 temporary

// [참고. Rust 용어] rvalue 라고 부르지않고 "value expression"


int x = 0;
int  foo() { return x; } // "x" 가 아닌 x의 값"0" 을 반환하는 코드
					     // 호출자는 "0" 만 받게되고, x의 메모리 정보는 알수없다
int& goo() { return x; }

int main()
{
	int n = 3;

	int* p1 = &n;
	int* p2 = &3;

	foo() = 5;	// error. "foo()" 라는 표현식은 rvalue
	goo() = 5;	// ok.    "goo()" 라는 표현식은 lvalue

	// QA#1
	const int c = 0;
	c = 10; // error
			// c 는 lvalue ? rvalue => C언어는 rvalue 로 구분
			// C++ 은 좀더 많은 조건을 고려해서 결정
			// => 메모리가 있고, 이름이 있고, 주소를 구할수 있다.
			// => lvalue 인데, 변경불가능한것
			// => immutable lvalue 라고 합니다.

	// QA#2. 모든 rvalue 는 상수 이다. YES ? NO ? 
	// => 답은 NO
	// => 상수라서 왼쪽에 올수 없는게 아니라
	// => 문법상(임시로존재하므로) 왼쪽에 올수 없는것
	Point{ 1,1 }.x = 10; // error
	Point{ 1,1 }.set(10, 20); // ok. 임시객체라도 멤버 함수로 변경 가능.
							  // => 곧 파괴되는데 왜 ???
							  // => move 할때 설명
}









