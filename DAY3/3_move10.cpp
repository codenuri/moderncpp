#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}

	Object(const Object&) {	std::cout << "copy" << std::endl;	}
	
	// �̵�������(�Ǵ� �̵����Կ�����)�� ���� ���鶧��
	// => �ǵ��� ���ܰ� �߻����� �ʰ� �����
	// => ���ܰ� ������ �˸��� ���� noexcept �� ǥ���ϼ���

	Object(Object&&) noexcept 
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = o1; // �׻� ���� ������ ȣ��
	Object o3 = std::move(o1); // �׻� �̵� ������ ȣ��

	Object o4 = std::move_if_noexcept(o1);	// �ٽ�
					// �̵������ڰ� noexcept �ΰ�� �̵������� ���
					// �ƴ� ��� ���� ������ ���
					// std::vector �� ���������� �� �Լ��� ���� ����
		



	std::vector<Object> v(5);

	std::cout << "----------------" << std::endl;

	v.resize(10); // �̼����� ������ �����غ��ô�.

	std::cout << "----------------" << std::endl;
}

