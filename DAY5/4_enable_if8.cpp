#include <iostream>
#include <vector>
#include <type_traits>

// C++11 type traits : Ÿ���� Ư���� "����" �ϴ� ��      is_xxx ����
// C++20 concept     : "����(concept)" �� ���� �ϴ� ��. is �ν������� ����

template<typename T>
concept Container = requires(T & c)
{
	{ c.begin() } -> std::input_iterator;
	{ c.end() } -> std::input_iterator;
};



template<typename T>
void foo(T a)
{
	// T�� ������ ���� �˰� �ʹ�.
	bool b1 = std::is_pointer_v<T>;

	// T�� STL �� �����̳����� �˰� �ʹ�.
	// => ��� �����ұ �߿��Ѱ��� �ƴմϴ�.
	// => "�����̳ʸ� ��� �����ұ�?" �� �߿��մϴ�.
	bool b2 = Container<T>;
}

void use_container(Container auto& c)
{

}

int main()
{
	std::vector<int> v = { 1,2,3 };
	foo(v);

	use_container(v); // ok
	use_container(3); // error
}