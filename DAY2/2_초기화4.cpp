// 58 page
class Vector
{
	int sz;
public:
	// explicit 생성자
	// => direct 초기화만 가능하고 copy 초기화는 사용할수 없다.
	// => C++98 시절 부터 사용하던 문법
	// => 아래 main 에서 "copy initialization" 은 모두 에러!
	explicit Vector(int s) : sz(s) {}
};

void foo(Vector v) {} 				  

int main()
{
	// #1. 인자가 한개인 생성자가 있으면 아래의 표기법이 가능합니다.
	Vector v1(10);		// C++98 style direct initialization
	Vector v2 = 10;		// C++98 style copy   initialization
	Vector v3{ 10 };	// C++11 style direct initialization
	Vector v4 = { 10 }; // C++11 style copy   initialization

	//----------------
	// #2. 
	foo(10); // Vector v = 10 입니다.!!
}







