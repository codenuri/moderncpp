// 10_user_define_literal2.cpp

class Gram
{
	int value;
public:
	Gram(int v) : value(v) {}
};

// ������ ���ͷ��� ���̴� ���̻�� ���ڰ� unsigned long long �̾�� �մϴ�.
// => 34page �Ʒ� ǥ ����
Gram operator""gram(unsigned long long n)
{
	Gram g( static_cast<int>(n));
	return g;
}

int main()
{
	// ����� ���� ���ͷ��� �ٽɿ���
	// => �����Ϸ��� ��ӵ� �Լ��� ã�� ��
	Gram g = 30gram; // operator""gram(30)
}