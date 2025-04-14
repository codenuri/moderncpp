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