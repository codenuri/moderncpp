#include <iostream>
#include <type_traits> 

#pragma pack(1)   // ����ü ��� align �� 1�� ���� �޶�
struct PACKET	  // padding ���� ����� �ǹ�
{
	char cmd;
	int  data;
};

// PACKET �� �ǵ����� ���� padding �� ���̸� ������ ���ߴ� �ڵ�
static_assert (sizeof(PACKET) == sizeof(char) + sizeof(int),
				"error. unexpected padding!!!");

/*
int main()
{
	std::cout << sizeof(PACKET) << std::endl; // ?
}
*/



template<typename T> void object_set_zero(T* p)
{
	// �����Լ��� �ִ� Ÿ���� ���� memset �ϸ� �ȵ˴ϴ�.
	// => ��ü�޸� �������� �ִ� �����Լ� ���̺� ������ ���� 0���� �˴ϴ�
	//	  
	// std::is_polymorphic<T>::value : T Ÿ�Կ� �����Լ��� ������ true
	//								=> ����Ͽ� ���� traits ���

	static_assert(!std::is_polymorphic<T>::value,
				"error. T has virtual function");

	memset(p, 0, sizeof(T)); 
}

class Test
{
	int data;
public:
};

int main()
{
	Test t;
	object_set_zero(&t);
}