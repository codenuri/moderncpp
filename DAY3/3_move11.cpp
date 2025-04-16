// 105 page.. ��� ��ü�� move
#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy" << std::endl; }

	Object(Object&&) noexcept  {std::cout << "move" << std::endl;	}
};
int main()
{
	const Object o1;

	// ��� ��ü�� move �ɼ� ����. 
	// �Ʒ� �ڵ�� ���� ������ ȣ��
	Object o2 = std::move(o1);	
				// static_cast<o1Ÿ��&&>(o1)
				// static_cast<const Object&&>(o1)
				// => Object&& �� �����Ҽ� ������
				// => const Object& �� �����Ҽ� �ִ�. 

	// ���� : rust �� ����� move �˴ϴ�.
	//		  ������ �н��� ������. 
}



