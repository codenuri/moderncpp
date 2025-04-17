// 6_����_��������ĸ��1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// #1. ����ǥ���Ŀ��� �������� - ok
	auto f1 = [](int a) { return a + g; };


	// #2. ����ǥ���Ŀ��� �������� - �⺻�����δ� ���� �ȵ�
//	auto f2 = [](int a) { return a + v1 + v2; }; // error


	// #3. �����Ϸ��� ���������� ĸ�� �ؾ� �մϴ�.
	auto f2 = [v1, v2](int a) { return a + v1 + v2; }; // ok

	// #4. ���������� ���� - error
//	auto f3 = [v1, v2](int a) { v1 = 100;  return a + v1 + v2; };

	// #4. ���������� �����Ϸ��� - mutable ���ٷ�
	auto f3 = [v1, v2](int a) mutable { v1 = 100;  return a + v1 + v2; };//ok
}





