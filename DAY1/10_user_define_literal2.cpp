// 10_user_define_literal2.cpp

class Gram
{
	int value;
public:
	Gram(int v) : value(v) {}
};

// ������ ���ͷ��� ���̴� ���̻�� ���ڰ� unsigned long long �̾�� �մϴ�.
// => 34page �Ʒ� ǥ ����
// => ���� ����ڰ� ����� ���ͷ��� �ݵ�� _�� �����ؾ� �մϴ�.
//    _�� ���� ���� ���� ǥ�ؿ��� ����ϱ�� ��ӵ�
// _�� ������
// g++ : ������ ����
// vs  : ��� �߻�
//Gram operator""gram(unsigned long long n)
Gram operator""_gram(unsigned long long n)
{
	Gram g( static_cast<int>(n));
	return g;
}

int main()
{
	// ����� ���� ���ͷ��� �ٽɿ���
	// => �����Ϸ��� ��ӵ� �Լ��� ã�� ��
	Gram g = 30_gram; // operator""_gram(30)

	auto g2 = 30_gram;
}