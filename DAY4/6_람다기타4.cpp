// ����ǥ������ �Լ� �����ͷ� ��ȯ �ɼ� �ִ� ����
// => ��ƽ��ϴ�.

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












