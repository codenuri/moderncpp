struct Test
{
	static int data;
	using DWORD = int;
};
int Test::data = 0;
int p1 = 0;

template<typename T> void foo(T a)
{
	// 아래 코드에서 * 의 의미를 생각해 보세요
	
	// "클래스이름::이름" 에서 "이름" 의 의미는
	// 1. 값 일수 있다. : static 멤버데이타, enum 상수등
	// 2. 타입일수도 있다.

	// "이름"의 의미에 따라 * 같은 연산자의 의미가 달라질수 있다.
//	Test::data  * p1;	// 곱하기 의미 
//	Test::DWORD * p2;	// 포인터 변수 선언( int* p2)

	// dependent name(의존이름)
	// => 템플릿 인자 T에 의존한 이름.
	// => 컴파일러는 임의의 타입 T를 조사할수 없기 때문에
	// => "이름" 을 무조건 "값"으로 해석	

	T::data * p1;	// ok. 곱하기 의미인데, p1은 전역변수로 존재
	T::DWORD* p2;	// error.곱하기 의미인데, p2가 없다.
	
}
int main()
{

}



