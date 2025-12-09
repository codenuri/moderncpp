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

	const int c = 0;
	c = 10; // error
}









