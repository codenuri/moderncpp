// 람다표현식이 함수 포인터로 변환 될수 있는 원리
// => 어렵습니다.

class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) const { return a + b; }
};

int main()
{
//	int(*f)(int, int) = [](int a, int b) {return a + b; };

	int(*f)(int, int) = CompilerGeneratedName{};
}












