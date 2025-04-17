struct Test
{
	static int data;
	typedef int DWORD; 
};
int Test::data = 0;
int p1 = 0;

template<typename T> void foo(T a)
{
	// 의존이름(dependent name)
	// => 템플릿 인자 T에 의존해서 꺼내는 이름
	// => 컴파일러는 "의존이름"을 무조건 값으로 해석한다.

	T::data  * p1;	
//	T::DWORD * p2;	

	// typename : dependent name 을 타입으로 해석해 달라고
	//			  컴파일러에게 알려 주는것
	//			  C++98 시절 부터 있던 문법
	typename T::DWORD* p2;



}
int main()
{
}




