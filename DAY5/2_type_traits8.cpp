#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}

	Object(const Object&) { std::cout << "copy" << std::endl; }

	Object(Object&&) noexcept { std::cout << "move" << std::endl;}
};

// std::move �� ����� ���ô�.
/*
template<typename T>
T&& mymove(T& obj)
{
	return static_cast<T&&>(obj);
}
*/

// �Լ� ���ø� ���鶧(�м��Ҷ�) �Ʒ� 2�� �� �����ϼ���
// T&  : lvalue �� �ްڴٴ°�
// T&& : lvalue, rvalue �� ��� �ްڴٴ� ��

// std::move : lvalue �� rvalue �� ��� �޾Ƽ� rvalue ĳ����

template<typename T>
constexpr std::remove_reference_t<T>&& mymove(T&& obj) noexcept
{
	// T&& �� �Լ���
	// lvalue �� �����ϸ� T = Object&
	// rvalue �� �����ϸ� T = Object

	// ���� mymove(o2) �ϸ� T = Object& �̹Ƿ� 
	// �Ʒ� ĳ������ 
	// static_cast<Object& &&>(obj) �Դϴ�
	// static_cast<Object&>(obj)  <= �ᱹ �̷��� �˴ϴ�.
//	return static_cast<T&&>(obj); // �ᱹ lvalue �� ���޽� 
									// lvalue �� ĳ�����Ѱ�!

	// �ذ�å  : T �� ���� ��� ���۷����� �����ϰ� && ���̸� �˴ϴ�.
	return static_cast<std::remove_reference_t<T> &&>(obj);
}


int main()
{
	Object o1;
	Object o2 = std::move(o1); // �̵�
	Object o3 = mymove(o2); 
	Object o4 = mymove(Object{}); // �ʿ������
								  // �Ǿ� �մϴ�.
}
