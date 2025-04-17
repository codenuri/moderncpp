// 5_����ǥ����1
#include <iostream>
#include <algorithm>
#include <functional>

// 

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// �� ������ ����
	// => �����Ϸ��� �� ������ �Ʒ� �ڵ�� �����մϴ�.

	class CompilerGeneratedName
	{
	public:
		inline auto operator()(int a, int b) const
		{
			return a < b;
		}
	};

	std::sort(v.begin(), v.end(), CompilerGeneratedName{} );

}

// ���� ǥ����
// => �Լ� ��ü�� ����� ǥ����Դϴ�.
// => ���� ǥ������ ���, ����ڰ� ���� �Լ� ��ü Ŭ���� ����� �˴ϴ�.

// ���� ǥ����(lambda expression)
// => "ǥ����(expression)" �̹Ƿ� �ϳ��� ���� ����� �ڵ�!!
// => �ᱹ ���� ǥ������ "�ӽð�ü(rvalue)" �� ����� ǥ���



