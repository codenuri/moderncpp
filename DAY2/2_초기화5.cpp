#include <vector>
#include <string>
#include <memory>
// call by value ���ٴ� const & �� ������
// => explicit ������ ���� ����!!
void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	hoo("hello");	// �Ǿ� �մϴ�. ���� �ߵ˴ϴ�.
					// std::string s = "hello" �� �ȴٴ� ��
	// ���� �Ʒ� 2�� ��� �����մϴ�.
	std::string s1("hello");
	std::string s2 = "hello";	// std::string(const char*) �����ڴ�
								// explicit �� �ƴ϶�� �ǹ�


	goo(10);	// �ȵǾ� �մϴ�. ���� �ȵ˴ϴ�.
				// std::vector<int> v = 10 �� �ȵȴٴ� ��
		
	std::vector<int> v1(10);	// ok
	std::vector<int> v2 = 10;	// error.
								// std::vector(int) �����ڴ�
								// "explicit" ��� �ǹ�!
	



	


}





