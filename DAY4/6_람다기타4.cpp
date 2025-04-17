// 람다표현식이 함수 포인터로 변환 될수 있는 원리
// => 어렵습니다.

class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) const { return a + b; }

	// 함수 포인터로의 변환을 위해서
	// operator() 와 동일한 일을 하는 static 멤버 함수가 추가됩니다.
	static int helper(int a, int b)
	{
		return a + b;
	}
	
	using FP = int(*)(int, int);
	
	// 변환 연산자 함수 : 객체가 다른 타입으로 변환될수 있게 할때 사용
	// => 함수 이름에 리턴 타입이 있기 때문에 별도로 반환 타입표기 안합니다.
	// => ex) operator int(), operator double()

//	operator FP() { return &CompilerGeneratedName::operator(); }
						// => error
						// => operator() 는 멤버 함수이므로 this 추가됨

	operator FP() { return &CompilerGeneratedName::helper; }
};

int main()
{
//	int(*f)(int, int) = [](int a, int b) {return a + b; };

	int(*f)(int, int) = CompilerGeneratedName{};
					// 객체.operator int() => 객체가 int로 변환가능
					// 객체.operator 함수포인터타입() 이 필요

	int n = f(1, 2);


	// 생각 해보세요
	int v1 = 10;

	int(*f1)(int, int) = [v1](int a, int b) {return a + b + v1; };
					// error.!!
}

// 지역변수 캡쳐한 경우
class CompilerGeneratedName
{
	int v1;
public:
	inline int operator()(int a, int b) const { return a + b + v1; }

	// 아래 static 멤버 함수에서 v1 에 접근이 안됩니다.
	// => 그래서 캡쳐한 람다 표현식은 "함수 포인터로 변환 될수없다"
	//    라는 문법이 있습니다. (rust 에도 동일 문법 존재)
	
	static int helper(int a, int b)
	{
		return a + b + v1;
	}

	using FP = int(*)(int, int);

	operator FP() { return &CompilerGeneratedName::helper; }
};






