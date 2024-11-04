// 58 page
// C++98 이야기. 
class Vector
{
	int sz;
public:
	// explicit 생성자
	// => 직접 초기화만 가능하고 복사 초기화는 사용할수 없다.
	// => C++98 시절부터 있던 문법
	// => 아래 main 코드에서 "복사 초기화" 부분은 모두 에러
	explicit Vector(int s) : sz(s) {}
};
void foo(Vector v) {} // Vector v = 10				  

int main()
{
	// 인자가 한개인 생성자가 있으면 아래의 표기법이 가능합니다.
	Vector v1(10);  // C++98 direct init.
	Vector v2 = 10; // C++98 copy   init.

	Vector v3{ 10 };	// C++11 direct init
	Vector v4 = { 10 };	// C++11 copy   init

	//----------------
	// 함수의 인자 전달은 복사 초기화 과정입니다.
	foo(10); // Vector v = 10
}







