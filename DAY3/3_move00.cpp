#include <iostream>
#include <string>
#include <vector>

// move ����
// C++11 ���� ó������ ���Ե� ����
// ���� ������ ���� �� ������ �ְ� �˴ϴ�.
// => D, Rust, Zig, Carbon ���� �ֽ� ���� ���ԵǾ����ϴ�



int main()
{
	std::string s1 = "hello";
	std::string s2 = "hello";

	std::string s3 = s1; // ���ڿ� ��ü�� ����
						 // ���� ����
						 // s1, s3 ���� ���ڿ� ����, s3�� ��ӻ�밡��

	std::string s4 = std::move(s2);
						// s2 �� �ڿ�(���ڿ�) �� s4�� ���Ѿ� ���� �˴ϴ�
						// ������(ownership) �� �̵��̶�� ǥ��
						// s2 �� ���̻� ���ڿ� �ڿ��� �����ϴ�.
	 
	std::cout << s1 << std::endl;	// "hello"
	std::cout << s2 << std::endl;	// ""


}

