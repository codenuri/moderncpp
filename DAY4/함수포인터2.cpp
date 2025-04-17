#include <functional>
class Dialog
{
public:
	void close1(int a) {}
	static void close2(int a) {}
};
void foo(int a) {}

int main()
{
	// ������ ������ ã������
	void(*f1)(int) = &foo;				// ok
//	void(*f2)(int) = &Dialog::close1;	// ERROR. ��� �Լ��� this �� �߰��ȴ�
	void(*f3)(int) = &Dialog::close2;	// ok.    static �� this �߰� �ȵ�

	// #1. �Ϲ� �Լ� �����Ϳ� ��� �Լ��� �ּҸ� ������ �����ϴ�.
	// #2. �Ϲ� �Լ� �����Ϳ� static ��� �Լ��� �ּҸ� ������ �ֽ��ϴ�.

	// #3. ��� �Լ� �ּҴ� �Ʒ�ó�� ��ƾ� �մϴ�.
	// => ��� �Լ� ������ ��� �մϴ�.
	void(Dialog::*f2)(int) = &Dialog::close1;

	
	// #4. ��� �Լ� ������ ����(ȣ���ϴ� ���)
	f2(10); // error. ��ü�� �����ϴ�.

	Dialog dlg;
//	dlg.f2(10); // error. Dialog �ȿ��� f2��� ����� �����ϴ�.

	// �̷��� ����ϴ� �����ڰ� "pointer to member(.*)" ��� �������Դϴ�

	dlg.*f2(10); // error. ������ �켱���� ����

	(dlg.*f2)(10); // ok.. �� �ڵ尡 ��� �Լ� �����ͷ� 
					// ���� ��� �Լ��� ȣ���ϴ� �ڵ�

	// #5. ������ �����ϰ� �Ҽ� ������ ?
	f1(10);			// �Ϲ� �Լ� ������
	(dlg.*f2)(10);	// ��� �Լ� ������

	f2(&dlg, 10); // �̷��� ȣ���Ҽ� �ִٸ� ��� ?
					// "uniform call syntax" ��� "â���ڰ� ����������
					//ä�� �ȵ�

	// ��� �Ʒ� ������ �������- C++17
	// <functional> ���
	std::invoke(f1, 10);			// f1(10)
	std::invoke(f2, &dlg, 10);		// (dlg.*f2)(10)

}