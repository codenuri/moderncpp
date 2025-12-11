// 2_typename

struct Test
{
	static int data;
	using DWORD = int;
};
int Test::data = 0;
int p = 0;

template<typename T> void foo(T a)
{
	// 아래 코드에서 * 의 의미를 생각해 보세요	
//	Test::data  * p;	// 여기서 * 의 의미는 곱하기
//	Test::DWORD * p;    // 여기서 * 의 의미는 포인터 변수의 선언

	// 핵심 : "타입이름::이름" 에서 "이름"은 
	// 1. 값일수 있습니다.    Test::data 
	// 2. 타입 일수 있습니다. Test::DWORD
	// "값", "타입" 에 따라 * 등의 연산자의 의미가 달라집니다.

	// 아래 코드를 생각해 보세요
	T::data  * p;
//	T::DWORD * p2; // error. 의도는 포인터를 선언 이지만, 컴파일러는 "값"으로 해석

	typename T::DWORD* p2;

	// "T::이름" : dependent name
	// => template 인자에 의존해서 얻게 되는 이름
	// => 컴파일러는 "이름" 을 항상 "값" 으로 해석!
	// => 타입으로 해석되게 하려면 typename 을 붙여야 한다.
	// => 단, T가 아닌 "Test::DWORD" 는 typename 붙일필요 없다.
}




int main()
{
	Test t;
	foo(t);
}



