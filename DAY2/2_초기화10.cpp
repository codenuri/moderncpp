// 1_�ʱ�ȭ10
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2{ 1,2,3,4,5 };


	// �Ʒ� 2���� �������� ?
	std::vector<int> v3(10, 2);	// vector(int, int) ������ ȣ��
								// => 10����Ҹ� 2�� �ʱ�ȭ
								// => v3.size() => 10

	std::vector<int> v4{10, 2}; // vector(std::initializer_list)ȣ��
								// => 2�� ��Ҹ� 10, 2�� �ʱ�ȭ
								// => v4.size() => 2


	// �Ʒ� �ڵ忡�� ������ ?
	std::vector<int> v5 = 10;		// error
									// vector(int) �� explicit 

	std::vector<int> v6 = {10};		// ok
									// vector(std::initializer_list)
									// �� explicit �ƴ�.

	// ��� : ��ü ������ () �� {} �ʱ�ȭ��
	// ������ ���ڷ� "std::initializer_list" �� ����ϴ� �����ڰ�
	// �������� ���� �մϴ�.
	// �������� �ٸ��� ���� �մϴ�.
}




