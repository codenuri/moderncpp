// 58 page
// => C++98 부터 사용되던 문법 설명

class Vector
{
	int sz;
public:
	// explicit 생성자(C++98 부터 있던 문법)
	// => 직접 초기화만 사용가능하고, 복사 초기화는 사용할수 없다.
	// => 아래 main 에서 "copy initialization" 부분은 모두 에러.
	explicit Vector(int s) : sz(s) {}

	// copy initialization vs direct initialization
	// => C++98 시절에는 차이점이 많았지만(내일 move 배운후 설명)
	// => C++11 이후는 유일한 차이점은 "생성자가 explicit" 일때
	//    direct 만 가능, copy 는 에러. 
};

void foo(Vector v) {} 				  

int main()
{
	// #1. 인자가 한개인 생성자가 있다면 아래 처럼 사용가능
	Vector v1(10);		// C++98 스타일 direct initialization
	Vector v2 = 10;		// C++98 스타일 copy   initialization
	Vector v3{ 10 };	// C++11 스타일 direct initialization
	Vector v4 = { 10 }; // C++11 스타일 copy   initialization

	//----------------
	foo(10); // "Vector v = 10" 즉, 인자의 전달은 "copy 초기화"
}







