class CompilerGeneratedName
{
	// int n; // 캡쳐 했다면
public:
	inline int operator()( int a, int b) { return a + b; }
										// return a + b + n

	// 함수포인터로의 변환을 위해서 operator() 와 동일 구현을 가진
	// static 멤버 함수가 필요
	static int helper(int a, int b) { return a + b; }
										// return a + b + n

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


	// 그런데, 캡쳐 했다면
	// => 함수 포인터로 변환될수 없습니다.
	// => 캡쳐하지 않은 람다 표현식만 가능
	// => 위 원리에서 "helper" 에서 캡쳐한 멤버데이타 접근할 방법이 
	//    없습니다.
	int n = 0;
	int(*f2)(int, int) = [n](int a, int b) {return a + b+n; }


	// 람다표현식은 함수포인터 변환이 됩니다.
	// => 원리를 생각해 봅시다.(위 코드 참고)
//	int(*f)(int, int) = [](int a, int b) {return a + b; }
}












