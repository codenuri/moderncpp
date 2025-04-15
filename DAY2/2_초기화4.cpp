// 58 page
class Vector
{
	int sz;
public:
	// explicit ������
	// => direct �ʱ�ȭ�� �����ϰ� copy �ʱ�ȭ�� ����Ҽ� ����.
	// => C++98 ���� ���� ����ϴ� ����
	// => �Ʒ� main ���� "copy initialization" �� ��� ����!
	explicit Vector(int s) : sz(s) {}
};

void foo(Vector v) {} 				  

int main()
{
	// #1. ���ڰ� �Ѱ��� �����ڰ� ������ �Ʒ��� ǥ����� �����մϴ�.
	Vector v1(10);		// C++98 style direct initialization
	Vector v2 = 10;		// C++98 style copy   initialization
	Vector v3{ 10 };	// C++11 style direct initialization
	Vector v4 = { 10 }; // C++11 style copy   initialization

	//----------------
	// #2. 
	foo(10); // Vector v = 10 �Դϴ�.!!
}







