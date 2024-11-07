class CompilerGeneratedName
{
public:
	inline int operator()( int a, int b) { return a + b; }

	// 함수포인터로의 변환을 위해서 operator() 와 동일 구현을 가진
	// static 멤버 함수가 필요
	static int helper(int a, int b) { return a + b; }


	using F = int(*)(int, int);

	// 변환 연산자 함수 : 객체가 다른 타입으로 변환이 필요할때 호출
	// operator F() { return 함수주소; }
	operator F() { return &CompilerGeneratedName::helper; }
};



int main()
{
	int(*f)(int, int) = CompilerGeneratedName(); // 임시객체
						// 임시객체.operator 변환될타입() 
						// 임시객체.operator 함수포인터타입() 



	// 람다표현식은 함수포인터 변환이 됩니다.
	// => 원리를 생각해 봅시다.(위 코드 참고)
//	int(*f)(int, int) = [](int a, int b) {return a + b; }
}












