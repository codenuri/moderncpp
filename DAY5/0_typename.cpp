// typename
struct Test
{
	static int data;
	typedef int DWORD; // using DWORD = int;
};
int Test::data = 0;
int p1 = 0;

template<typename T> void foo(T a)
{
	// 아래 코드에서 * 의 의미를 생각해 보세요
	Test::data  * p1;	// 0 * 0    여기서 * 는 곱하기의 의미
	Test::DWORD * p2;	// int* p2  여기서 * 는 포인터 연산자

	// "클래스이름::이름" 에서 "이름" 은
	// 1. 값일수도 있고 ( static 멤버 데이타, enum 상수등)
	// 2. 타입 일수도 있습니다. ( typedef, using)
	// => 값인지 타입 인지에 따라 * 같은 연산자 의미가 달라 집니다.
	
}
int main()
{
}




