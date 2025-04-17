#include <string>
#include <optional>
class Holder
{
public:
	std::string data = "hello";

//	std::string& get_data() { return data; } // A

	std::string&  get_data() &  { return data; }				// B
	std::string&& get_data() && { return std::move(data); } // C
};

int main()
{
	Holder h = Holder{}; // �ӽð�ü�̹Ƿ� move, ����ȭ�ϸ� ȣ�� ���ŵ�

	std::string s = Holder{}.data; // �ӽð�ü�� �̸��ִ� �������Ÿ��
									// rvalue �̹Ƿ� move

	std::string s = Holder{}.get_data();	// A�� �ִٸ� ��ȯ���� ����! lvalue
											// move �� �ƴ� copy
								// => B,C �� �ذ�


	std::optional<int> opt(10);

//	int n = *opt;  // �� ������
//	int n = opt.operator*(); // �� �ڵ��ε�
							// �� �Լ��� ��ó�� �Ǿ� �ֽ��ϴ�.

}