// ����ǥ������ �Լ� �����ͷ� ��ȯ �ɼ� �ִ� ����
// => ��ƽ��ϴ�.

class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) const { return a + b; }

	// �Լ� �����ͷ��� ��ȯ�� ���ؼ�
	// operator() �� ������ ���� �ϴ� static ��� �Լ��� �߰��˴ϴ�.
	static int helper(int a, int b)
	{
		return a + b;
	}
	
	using FP = int(*)(int, int);
	
	// ��ȯ ������ �Լ� : ��ü�� �ٸ� Ÿ������ ��ȯ�ɼ� �ְ� �Ҷ� ���
	// => �Լ� �̸��� ���� Ÿ���� �ֱ� ������ ������ ��ȯ Ÿ��ǥ�� ���մϴ�.
	// => ex) operator int(), operator double()

//	operator FP() { return &CompilerGeneratedName::operator(); }
						// => error
						// => operator() �� ��� �Լ��̹Ƿ� this �߰���

	operator FP() { return &CompilerGeneratedName::helper; }
};

int main()
{
//	int(*f)(int, int) = [](int a, int b) {return a + b; };

	int(*f)(int, int) = CompilerGeneratedName{};
					// ��ü.operator int() => ��ü�� int�� ��ȯ����
					// ��ü.operator �Լ�������Ÿ��() �� �ʿ�

	int n = f(1, 2);
}












