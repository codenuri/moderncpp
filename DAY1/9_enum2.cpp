// C/C++98 enum - unscoped enum �̶�� �մϴ�.
// enum COLOR { red = 1, green, blue };

// C++11 �� ���ο� enum - scoped enum �̶�� �մϴ�.
// => COLOR �� �����Ҽ� ���� ������ ���� �̸�
enum class COLOR { red = 1, green, blue };

int main()
{
	COLOR c1 = COLOR::red; // ok 

//	COLOR c2 = red; // error. COLOR ���� �ȵ�

//	int c3 = COLOR::red; // error. COLOR Ÿ�Ը� ����

	// enum ������ - ���� ������ �ϴ� ��쵵 �ֽ��ϴ�.
	// static_cast ����ϼ���

	int n1 = static_cast<int>(COLOR::red); // ok 
}





