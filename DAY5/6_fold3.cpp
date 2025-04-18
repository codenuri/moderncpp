#include <vector>
#include <iostream>

// �����ϽǶ� ���ۿ��� "C++ fold expression example" �غ�����
// ���� ������ ���� �ֽ��ϴ�.

template<typename ... Types>
void insert_vector(std::vector<int>& v, Types ... args)
{
	// args �� ��� ��Ҹ� v �� �־� ������
	( v.push_back(args), ...  );
//    (pack           op ...)	(E1 op(... op(EN - 1 op EN)))
//    v.push_back(1), ( v.push_back(2), ( v.push_back(3) .. 
}

int main()
{
	std::vector<int> v;

	insert_vector(v, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	for (auto e : v)
		std::cout << e << ", ";
}