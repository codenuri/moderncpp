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
T&& mymove(T&& obj)
{
	return static_cast<T&&>(obj);
}


int main()
{
	Object o1;
	Object o2 = std::move(o1); // �̵�
	Object o3 = mymove(o2); 
	Object o4 = mymove(Object{}); // �ʿ������
								  // �Ǿ� �մϴ�.
}
