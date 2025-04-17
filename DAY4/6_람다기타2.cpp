

int main()
{
	// generic lambda
	// => ���ڷ� auto �� ����ϴ� ���� ǥ����
	// => c++14 ���� ����
	auto f = [](auto a, auto b) { return a + b; };

	int    n = f(1, 2);
	double d1 = f(3.2, 3.2);
	double d2 = f(3.2, 1);
}
// generic lambda �� ����
class CompilerGeneratedName
{
public:
	// �ٽ� : 2���� ���ڰ� ���� �ٸ� ���ø�
	template<typename T1, typename T2>
	auto operator()(T1 a, T2 b) const
	{
		return a + b;
	}
};
/*
// ���ٰ� �ƴ� �Ϲ� �Լ��� ���ڷ� auto �� ����Ҽ� �������?
// => C++20 ���� �˴ϴ�.
auto add(auto a, auto b)
{
	return a + b;
}
auto ret1 = add(1, 2);
auto ret2 = add(1.2, 2);

// �� add �� template �Դϴ�. �Ʒ��� ����
template<typename T1,typename T2>
auto add(T1 a, T2 b)
{
	return a + b;
}
*/