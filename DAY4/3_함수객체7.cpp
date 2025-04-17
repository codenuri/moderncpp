#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// C++ ǥ�� std::sort() �� ��� ���ڰ� template �Դϴ�
	// => ����ڰ� ������ ������ Ÿ���� �����ؼ� �Լ��� "����" �Ѵٴ� �ǹ�


	// 1. �� ��å���� �Ϲ� �Լ��� ����ϴ� ���
	
	// ���� : �� ��å�� ������ ��ü �ص� sort() �Լ��� �Ѱ��� �����ȴ�.
	//        => �ڵ� �޸� ���� ����.

	// ���� : ���Լ��� �ζ��� ġȯ�ɼ� ����.
	//		  ������.
	//        ����Ÿ ���� ������ �����ؾ� �Ѵ�.

	std::sort(x, x+10, cmp1); // sort(int*, int*, bool(*)(int, int)) �� �Լ�����
	std::sort(x, x+10, cmp2); // sort(int*, int*, bool(*)(int, int)) �� �Լ�����



	// 2. �� ��å���� �Լ� ��ü�� ����ϴ� ���

	// ���� : �� ��å�� �ζ��� ġȯ �ǹǷ� ������.!

	// ���� : ����å�� ��ü�� Ƚ�� ��ŭ�� sort() �Լ� ����
	// => �� ��å�� ������ ��ü�ϸ� �ڵ�޸� ����!!

	Less f1;
	Greater f2;

	std::sort(x, x + 10, f1); // sort(int*, int*, Less) �� �Լ� ����
	std::sort(x, x + 10, f2); // sort(int*, int*, Greater) �� �Լ� ����
}