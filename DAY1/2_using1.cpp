// using - 11 page

// C ��Ÿ�� �ڵ� - typedef 
typedef int DWORD;
typedef void(*F)(); 

// C++11 ���ʹ� using ����ϴ� ���� ����
// => �Ʒ� 2���� ���� ������ �����մϴ�.
using DWORD = int;
using F = void(*)();

int main() 
{
	DWORD n; // int n
	F     f; // void(*f)() 
}