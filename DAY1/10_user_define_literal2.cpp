// 10_user_define_literal2.cpp

class Gram
{
	int value;
public:
	Gram(int v) : value(v) {}
};

Gram operator""gram(int n)
{
	Gram g(n);
	return g;
}

int main()
{
	// ����� ���� ���ͷ��� �ٽɿ���
	// => �����Ϸ��� ��ӵ� �Լ��� ã�� ��
	Gram g = 30gram; // operator""gram(30)
}