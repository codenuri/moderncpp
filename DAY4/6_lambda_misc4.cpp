// 람다 표현식 사용시 컴파일러가 만드는 클래스라고 가정
class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) { return a + b; }


	using PF = int(*)(int, int);

	operator PF() { return &CompilerGeneratedName::operator(); }
};

int main()
{
	int(*f1)(int, int) = CompilerGeneratedName{};
						// 임시객체.operator 함수포인터타입()


//	int(*f1)(int, int) = [](int a, int b) {return a + b; };
						// class xxx{}; xxx{};
}












