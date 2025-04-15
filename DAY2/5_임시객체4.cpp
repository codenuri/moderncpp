// 3_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// �ӽð�ü�� Ư¡ - 79 page
int main()
{
	Point pt{ 1, 2 };
	
	// #1. �ӽð�ü�� ��ȣ�� ���ʿ� �ü� ����.(rvalue �̴�)
	pt.x = 10;				// ok. named object �� lvalue �� �ɼ� �ִ�.
	Point{ 1, 2 }.x = 10;	// error. 
						

	// #2. �ӽð�ü�� �ּ� �����ڷ� �ּҸ� ���Ҽ� ����.
	Point* p1 = &pt;			// ok
	Point* p2 = &Point{ 1, 2 };	// error
							

	// #3. �ӽð�ü�� non-const reference �� ����ų�� ����.
	Point& r1 = pt;				// ok
	Point& r2 = Point{ 1, 2 };	// error.


	// #4. �ӽð�ü�� const reference �� ����ų�� �ִ�.
	const Point& cr = Point{ 1, 2 };	// ok
		// �ӽð�ü��  const reference �� ����Ű�� 
		// ������ "cr" �� �������� ���� �˴ϴ�
		// "lifetime extension" �̶�� ����..
	
		
//	cr.x = 10; // error. ��, cr�� ��� �����̹Ƿ�  ������ �ȵ�


	// #5. C++11 ���鶧 ����� �ƴ� ������ �ӽð�ü�� ����Ű�� �;����ϴ�.
	// => move �� perfect forwarding ����� ���ؼ�
	// => �׷��� ���ο� ���� ���� ����
	// => rvalue reference ��� C++11�� �ٽ� ����
	Point&& rr = Point{ 1,2 };
		
	rr.x = 10;	// ok..
				// ���� �����.
}





